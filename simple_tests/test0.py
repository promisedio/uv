from promisedio import promise


async def func1(n):
    d = promise.deferred()
    print("func1", n)
    def x(v):
        print("CALLED", n)
        1/0
    p = d.promise()
    p.then(x)
    d.resolve("Some data")

promise.exec_async(func1(0))
promise.process_promise_chain()
promise.process_promise_chain()
