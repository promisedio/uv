// Auto-generated

#ifndef CAPSULE_NS_API
#define CAPSULE_NS_API

static int ns_api_7ab729d4e085e81135827b365bb6af40__LOADED = 0;
static void *ns_api_7ab729d4e085e81135827b365bb6af40__API[19];

#define NS_API ns_api_7ab729d4e085e81135827b365bb6af40

#include <promisedio_uv.h>
#include "promisedio/promise.h"

#ifdef CAPSULE_NS_API
typedef PyObject Stream;
typedef PyObject Server;
#endif

#define NS_GETADDRINFO_ID 0
#define Ns_GetAddrInfo(...) \
  ((Promise * (*) (void*, const char *node, const char *service, int family, int type, int proto, int flags))(ns_api_7ab729d4e085e81135827b365bb6af40__API[NS_GETADDRINFO_ID]))( \
    _ctx->ns_api_7ab729d4e085e81135827b365bb6af40__CTX, __VA_ARGS__)

#define NS_GETNAMEINFO_ID 1
#define Ns_GetNameInfo(...) \
  ((Promise * (*) (void*, const struct sockaddr *addr, int flags))(ns_api_7ab729d4e085e81135827b365bb6af40__API[NS_GETNAMEINFO_ID]))( \
    _ctx->ns_api_7ab729d4e085e81135827b365bb6af40__CTX, __VA_ARGS__)

#define TCPSTREAM_GETSOCKNAME_ID 2
#define TcpStream_GetSockName(...) \
  ((PyObject * (*) (Stream *stream))(ns_api_7ab729d4e085e81135827b365bb6af40__API[TCPSTREAM_GETSOCKNAME_ID]))( \
    __VA_ARGS__)

#define TCPSTREAM_GETPEERNAME_ID 3
#define TcpStream_GetPeerName(...) \
  ((PyObject * (*) (Stream *stream))(ns_api_7ab729d4e085e81135827b365bb6af40__API[TCPSTREAM_GETPEERNAME_ID]))( \
    __VA_ARGS__)

#define TCPSTREAM_SETTCPNODELAY_ID 4
#define TcpStream_SetTcpNoDelay(...) \
  ((int (*) (Stream *stream, int enabled))(ns_api_7ab729d4e085e81135827b365bb6af40__API[TCPSTREAM_SETTCPNODELAY_ID]))( \
    __VA_ARGS__)

#define TCPSTREAM_SETTCPKEEPALIVE_ID 5
#define TcpStream_SetTcpKeepAlive(...) \
  ((int (*) (Stream *stream, int delay))(ns_api_7ab729d4e085e81135827b365bb6af40__API[TCPSTREAM_SETTCPKEEPALIVE_ID]))( \
    __VA_ARGS__)

#define STREAM_CLOSE_ID 6
#define Stream_Close(...) \
  ((Promise * (*) (Stream *stream))(ns_api_7ab729d4e085e81135827b365bb6af40__API[STREAM_CLOSE_ID]))( \
    __VA_ARGS__)

#define STREAM_SHUTDOWN_ID 7
#define Stream_Shutdown(...) \
  ((Promise * (*) (Stream *stream))(ns_api_7ab729d4e085e81135827b365bb6af40__API[STREAM_SHUTDOWN_ID]))( \
    __VA_ARGS__)

#define STREAM_WRITE_ID 8
#define Stream_Write(...) \
  ((Promise * (*) (Stream *stream, PyObject *data))(ns_api_7ab729d4e085e81135827b365bb6af40__API[STREAM_WRITE_ID]))( \
    __VA_ARGS__)

#define STREAM_READ_ID 9
#define Stream_Read(...) \
  ((Promise * (*) (Stream *stream, Py_ssize_t n, double timeout))(ns_api_7ab729d4e085e81135827b365bb6af40__API[STREAM_READ_ID]))( \
    __VA_ARGS__)

#define STREAM_READEXACTLY_ID 10
#define Stream_ReadExactly(...) \
  ((Promise * (*) (Stream *stream, Py_ssize_t n, double timeout))(ns_api_7ab729d4e085e81135827b365bb6af40__API[STREAM_READEXACTLY_ID]))( \
    __VA_ARGS__)

#define STREAM_READUNTIL_ID 11
#define Stream_ReadUntil(...) \
  ((Promise * (*) (Stream *stream, char c, double timeout))(ns_api_7ab729d4e085e81135827b365bb6af40__API[STREAM_READUNTIL_ID]))( \
    __VA_ARGS__)

#define STREAM_OPENCONNECTION_ID 12
#define Stream_OpenConnection(...) \
  ((Promise * (*) (void*, const struct sockaddr *remote_addr, const struct sockaddr *local_addr, Py_ssize_t limit, Py_ssize_t chunk_size, int nodelay, int keepalive, PyObject *ssl, const char *server_hostname, double timeout))(ns_api_7ab729d4e085e81135827b365bb6af40__API[STREAM_OPENCONNECTION_ID]))( \
    _ctx->ns_api_7ab729d4e085e81135827b365bb6af40__CTX, __VA_ARGS__)

#define STREAM_OPENUNIXCONNECTION_ID 13
#define Stream_OpenUnixConnection(...) \
  ((Promise * (*) (void*, const char *path, Py_ssize_t limit, Py_ssize_t chunk_size, PyObject *ssl, const char *server_hostname, double timeout))(ns_api_7ab729d4e085e81135827b365bb6af40__API[STREAM_OPENUNIXCONNECTION_ID]))( \
    _ctx->ns_api_7ab729d4e085e81135827b365bb6af40__CTX, __VA_ARGS__)

#define UNIXSTREAM_GETPEERNAME_ID 14
#define UnixStream_GetPeerName(...) \
  ((PyObject * (*) (Stream *stream))(ns_api_7ab729d4e085e81135827b365bb6af40__API[UNIXSTREAM_GETPEERNAME_ID]))( \
    __VA_ARGS__)

#define UNIXSTREAM_GETSOCKNAME_ID 15
#define UnixStream_GetSockName(...) \
  ((PyObject * (*) (Stream *stream))(ns_api_7ab729d4e085e81135827b365bb6af40__API[UNIXSTREAM_GETSOCKNAME_ID]))( \
    __VA_ARGS__)

#define STREAM_SERVERCLOSE_ID 16
#define Stream_ServerClose(...) \
  ((Promise * (*) (Server *server))(ns_api_7ab729d4e085e81135827b365bb6af40__API[STREAM_SERVERCLOSE_ID]))( \
    __VA_ARGS__)

#define STREAM_STARTSERVER_ID 17
#define Stream_StartServer(...) \
  ((Server * (*) (void*, PyObject *client_connected_cb, const struct sockaddr *addr, Py_ssize_t limit, Py_ssize_t chunk_size, int backlog, int nodelay, int keepalive, int simultaneous_accepts, PyObject *ssl))(ns_api_7ab729d4e085e81135827b365bb6af40__API[STREAM_STARTSERVER_ID]))( \
    _ctx->ns_api_7ab729d4e085e81135827b365bb6af40__CTX, __VA_ARGS__)

#define STREAM_STARTUNIXSERVER_ID 18
#define Stream_StartUnixServer(...) \
  ((Server * (*) (void*, PyObject *client_connected_cb, const char *path, Py_ssize_t limit, Py_ssize_t chunk_size, int backlog, PyObject *ssl))(ns_api_7ab729d4e085e81135827b365bb6af40__API[STREAM_STARTUNIXSERVER_ID]))( \
    _ctx->ns_api_7ab729d4e085e81135827b365bb6af40__CTX, __VA_ARGS__)

#endif
