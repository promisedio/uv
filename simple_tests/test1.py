import time
from promisedio import promise, loop, timer


print("start", time.time())

async def func1():
    print("func1", time.time())
    def f(_):
        print("HERE1", time.time())
        print("#ALLOCSTAT")
        return timer.sleep(1)
    await timer.sleep(1).then(f)


promise.exec_async(func1())
loop.run_until_complete()


