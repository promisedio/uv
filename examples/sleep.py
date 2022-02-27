import time
import sys
import threading
from promisedio import loop, timer, promise


print("started", time.time())

async def example1():
    print("example1", time.time())

    def f1(_):
        print("f1", time.time())
        return timer.sleep(1)

    await timer.sleep(1).then(f1)


def run_in_thread(timeout):
    def resolve(d):
        time.sleep(timeout)
        d.resolve(True)
    d = promise.deferred()
    threading.Thread(target=resolve, args=(d,)).start()
    return d.promise()


async def example2():
    await run_in_thread(5)
    print("Done")


# for x in range(10):
print(sys.getrefcount(None))
promise.exec_async(example1())
promise.exec_async(example2())
loop.run_forever()
    # print(sys.getrefcount(None))
