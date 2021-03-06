import time
from promisedio import timer, loop, promise


async def example1():
    print("example1 start", time.time())
    def test1():
        assert 0, "Should not be here"

    def test2():
        print("test2", time.time())

    def test3():
        print("test3", time.time())

    timer.set_timeout(test1, 11)
    timer.set_interval(test3, 1)
    timer.set_timeout(test2, 5)
    await timer.sleep(7)
    print("example1 end", time.time())


promise.exec_async(example1())
loop.run_forever()

print("end", time.time())
