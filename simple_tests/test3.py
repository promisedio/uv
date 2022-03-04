from promisedio import promise, loop, timer


some_value1 = "VALUE1"
some_value2 = "VALUE2"
some_value3 = "VALUE3"


print("0x%x" % id(some_value1))
print("0x%x" % id(some_value2))
print("0x%x" % id(some_value3))


async def resolve_later(timeout, value, promises):
    await timer.sleep(timeout)
    for x in promises:
        x.resolve(value)


async def test_then_only(p):
    def then1(v):
        print("test_then_only.then1:", v)
        return some_value2

    def then2(v):
        print("test_then_only.then2:", v)
        return some_value3

    p.then(then1).then(then2)


async def test_then_await(p):
    def then1(v):
        print("test_then_await.then1:", v)
        return some_value2

    def then2(v):
        print("test_then_await.then2:", v)
        return some_value3

    value = await p.then(then1).then(then2)
    print("test_then_await:", value)


def start():
    deferred1 = promise.deferred()
    deferred2 = promise.deferred()

    promise.exec_async(resolve_later(2, some_value1, [deferred1, deferred2]))

    coro1 = test_then_only(deferred1.promise())
    coro2 = test_then_await(deferred2.promise())

    promise.exec_async(coro1)
    promise.exec_async(coro2)

    print("#ALLOCSTAT")

    loop.run_forever()


start()
