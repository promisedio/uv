import ssl
from promisedio import loop, ns, promise, timer

n = 0

context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
context.load_cert_chain('localhost.cert', 'localhost.key')


async def work(stream):
    print(stream.getsockname())
    print(stream.getpeername())
    await stream.write(b'azaza')


def new_connection(stream):
    global n
    if n == 1:
        server.close()
    else:
        promise.exec_async(work(stream))
        n += 1


server = ns.start_server(new_connection, ("127.0.0.1", 8090), ssl=context)


loop.run_forever()
