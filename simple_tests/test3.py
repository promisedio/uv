import sys
from promisedio.promise import deferred, exec_async
from promisedio.loop import run_until_complete
from promisedio import timer


some_value1 = "VALUE1"
some_value2 = "VALUE2"
some_value3 = "VALUE3"


print("0x%x" % id(some_value1))
print("0x%x" % id(some_value2))
print("0x%x" % id(some_value3))


async def resolve_later(timeout, value, promises):
    # f = await fs.open("demo1.txt", "wb")
    # await f.close()
    await timer.sleep(timeout)
    for x in promises:
        x.resolve(value)


async def test_then_only(promise):
    def then1(v):
        print("test_then_only.then1:", v)
        return some_value2

    def then2(v):
        print("test_then_only.then2:", v)
        return some_value3

    promise.then(then1).then(then2)


async def test_then_await(promise):
    def then1(v):
        print("test_then_await.then1:", v)
        return some_value2

    def then2(v):
        print("test_then_await.then2:", v)
        return some_value3

    value = await promise.then(then1).then(then2)
    print("test_then_await:", value)


def start():
    deferred1 = deferred()
    deferred2 = deferred()

    exec_async(resolve_later(0.1, some_value1, [deferred1, deferred2]))

    coro1 = test_then_only(deferred1.promise())
    coro2 = test_then_await(deferred2.promise())

    exec_async(coro1)
    exec_async(coro2)

    print("#ALLOCSTAT")

    run_until_complete()


start()
