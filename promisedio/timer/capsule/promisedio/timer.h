// Auto-generated

#ifndef CAPSULE_TIMER_API
#define CAPSULE_TIMER_API

static int timer_api_87628408d36b58dc79fc1e618b008598__LOADED = 0;
static void *timer_api_87628408d36b58dc79fc1e618b008598__API[6];

#define TIMER_API timer_api_87628408d36b58dc79fc1e618b008598

#include <promisedio_uv.h>
#include "promisedio/promise.h"

typedef void (*timeout_cb)(void* data);

#define TIMER_TIMEOUT_ID 0
#define Timer_Timeout(...) \
  ((Promise * (*) (void*, uint64_t timeout))(timer_api_87628408d36b58dc79fc1e618b008598__API[TIMER_TIMEOUT_ID]))( \
    _ctx->timer_api_87628408d36b58dc79fc1e618b008598__CTX, __VA_ARGS__)

#define TIMER_SETPROMISETIMEOUT_ID 1
#define Timer_SetPromiseTimeout(...) \
  ((void * (*) (void*, Promise *promise, uint64_t timeout, timeout_cb callback, void *data))(timer_api_87628408d36b58dc79fc1e618b008598__API[TIMER_SETPROMISETIMEOUT_ID]))( \
    _ctx->timer_api_87628408d36b58dc79fc1e618b008598__CTX, __VA_ARGS__)

#define _TIMER_UPDATEPROMISETIMEOUT_ID 2
#define _Timer_UpdatePromiseTimeout(...) \
  ((void (*) (void*, Promise *promise, timeout_cb callback))(timer_api_87628408d36b58dc79fc1e618b008598__API[_TIMER_UPDATEPROMISETIMEOUT_ID]))( \
    _ctx->timer_api_87628408d36b58dc79fc1e618b008598__CTX, __VA_ARGS__)

#define Timer_UpdatePromiseTimeout(promise, callback)   \
    if ((promise)->timer)                               \
        _Timer_UpdatePromiseTimeout(promise, callback)

#define _TIMER_CANCELPROMISETIMEOUT_ID 3
#define _Timer_CancelPromiseTimeout(...) \
  ((void (*) (Promise *promise))(timer_api_87628408d36b58dc79fc1e618b008598__API[_TIMER_CANCELPROMISETIMEOUT_ID]))( \
    __VA_ARGS__)

#define Timer_CancelPromiseTimeout(promise)             \
    if ((promise)->timer)                               \
        _Timer_CancelPromiseTimeout(promise)

#define TIMER_START_ID 4
#define Timer_Start(...) \
  ((PyObject * (*) (void*, PyObject *func, uint64_t timeout, uint64_t repeat))(timer_api_87628408d36b58dc79fc1e618b008598__API[TIMER_START_ID]))( \
    _ctx->timer_api_87628408d36b58dc79fc1e618b008598__CTX, __VA_ARGS__)

#define TIMER_STOP_ID 5
#define Timer_Stop(...) \
  ((int (*) (void*, PyObject *ob))(timer_api_87628408d36b58dc79fc1e618b008598__API[TIMER_STOP_ID]))( \
    _ctx->timer_api_87628408d36b58dc79fc1e618b008598__CTX, __VA_ARGS__)

#endif
