import ssl
import certifi
from promisedio import loop, ns, promise, timer


async def example1():
    context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
    context.verify_mode = ssl.CERT_REQUIRED
    context.check_hostname = True
    context.load_default_certs()
    context.load_verify_locations(
        cafile=certifi.where(),
        capath=None,
        cadata=None
    )

    stream = await ns.open_connection(("209.131.162.45", 443), ssl=context, server_hostname="www.verisig1n.com", timeout=0.2)

    print(stream.getsockname())
    print(stream.getpeername())
    await stream.write(b"GET / HTTP 1.1\n\n")
    print(await stream.read())
    await stream.shutdown()


async def example2():
    stream = await ns.open_connection(("192.168.1.99", 8080), timeout=2)
    print(stream.getsockname())
    print(stream.getpeername())
    await stream.shutdown()


promise.exec_async(example1())
loop.run_forever()
