// Copyright (c) 2021-2022 Andrey Churin (aachurin@gmail.com).
// This file is part of promisedio

/*[capsule:name TIMER_API]*/
/*[capsule:output capsule/promisedio/]*/

/*[capsule:copy]*/
#include <promisedio_uv.h>
#include "promisedio/promise.h"

typedef void (*timeout_cb)(void* data);
/*[capsule:endcopy]*/

#include "promisedio/loop.h"
#include "clinic/timer.c.h"

typedef struct {
    PyTypeObject *TimerType;
    PyObject *TimeoutError;
    Capsule_MOUNT(PROMISE_API)
    Capsule_MOUNT(LOOP_API)
} _modulestate;

typedef struct {
    Promise *promise;
    timeout_cb timeout;
    HANDLE_BASE(uv_timer_t)
} TimeoutHandle;

/*[clinic input]
module timer
[clinic start generated code]*/
/*[clinic end generated code: output=da39a3ee5e6b4b0d input=360be8ec388bdfbe]*/

static void
timeout_callback(uv_timer_t *handle)
{
    ACQUIRE_GIL
        TimeoutHandle *h = Handle_Get(handle, TimeoutHandle);
        Promise_Resolve(h->promise, Py_None);
        Py_CLEAR(h->promise);
        Handle_Close(h);
    RELEASE_GIL
}

static void
timeout_finalizer(TimeoutHandle *handle)
{
    // TODO: Maybe reject timeout here???
    Py_XDECREF(handle->promise);
}

CAPSULE_API(Promise *)
Timer_Timeout(_ctx_var, uint64_t timeout)
{
    Loop_SETUP(loop)
    Promise *promise = Promise_New();
    if (!promise)
        return NULL;
    TimeoutHandle *handle = Handle_New(TimeoutHandle, timeout_finalizer);
    if (!handle) {
        Py_DECREF(promise);
        return NULL;
    }
    handle->promise = promise;
    uv_timer_init(loop, &handle->base);
    uv_timer_start(&handle->base, (uv_timer_cb) timeout_callback, timeout, 0);
    return (Promise *) Py_NewRef(promise);
}

typedef struct timeout_s {
    Promise *promise;
    void *data;
    timeout_cb callback;
    HANDLE_BASE(uv_timer_t)
} PromiseTimeout;

static void
set_timeout_callback(uv_timer_t *handle)
{
    ACQUIRE_GIL
        PromiseTimeout *h = Handle_Get(handle, PromiseTimeout);
        _CTX_set(h);
        h->promise->timer = NULL;
        Promise_RejectString(h->promise, S(TimeoutError), "Operation timeout");
        Py_CLEAR(h->promise);
        if (h->callback) {
            h->callback(h->data);
        }
        Handle_Close(h);
    RELEASE_GIL
}

static void
set_promise_timeout_finalizer(PromiseTimeout *handle)
{
    Py_XDECREF(handle->promise);
}

CAPSULE_API(void *)
Timer_SetPromiseTimeout(_ctx_var, Promise *promise, uint64_t timeout, timeout_cb callback, void *data)
{
    Loop_SETUP(loop)
    PromiseTimeout *handle = Handle_New(PromiseTimeout, set_promise_timeout_finalizer);
    if (!handle) {
        return NULL;
    }
    Py_INCREF(promise);
    handle->promise = promise;
    handle->callback = callback;
    handle->data = data;
    promise->timer = handle;
    uv_timer_init(loop, &handle->base);
    uv_timer_start(&handle->base, (uv_timer_cb) set_timeout_callback, timeout, 0);
    return handle;
}

CAPSULE_API(void)
_Timer_UpdatePromiseTimeout(_ctx_var, Promise *promise, timeout_cb callback)
{
    assert(promise->timer != NULL);
    LOG("(%p)", promise);
    PromiseTimeout *handle = (PromiseTimeout *) promise->timer;
    handle->callback = callback;
}

/*[capsule:copy]*/
#define Timer_UpdatePromiseTimeout(promise, callback)   \
    if ((promise)->timer)                               \
        _Timer_UpdatePromiseTimeout(promise, callback)
/*[capsule:endcopy]*/

CAPSULE_API(void)
_Timer_CancelPromiseTimeout(Promise *promise)
{
    assert(promise->timer != NULL);
    LOG("(%p)", promise);
    PromiseTimeout *handle = (PromiseTimeout *) promise->timer;
    promise->timer = NULL;
    Handle_Close(handle);
}

/*[capsule:copy]*/
#define Timer_CancelPromiseTimeout(promise)             \
    if ((promise)->timer)                               \
        _Timer_CancelPromiseTimeout(promise)
/*[capsule:endcopy]*/

/*[clinic input]
timer.sleep
    seconds: double
[clinic start generated code]*/

Py_LOCAL_INLINE(PyObject *)
timer_sleep_impl(PyObject *module, double seconds)
/*[clinic end generated code: output=0e7d97eb1efd2983 input=97a9461096618dc6]*/
{
    _CTX_set_module(module);
    if (seconds < 0) {
        PyErr_SetString(PyExc_ValueError, "sleep length must be non-negative");
        return NULL;
    }
    return (PyObject *) Timer_Timeout(_ctx, (uint64_t) (seconds * 1000));
}

typedef struct timerhandle_s TimerHandle;

typedef struct {
    PyObject_HEAD
    TimerHandle *handle;
} Timer;

typedef struct timerhandle_s {
    Timer *timer;
    PyObject *func;
    HANDLE_BASE(uv_timer_t)
} TimerHandle;

static void
timer_dealloc(Timer *ob)
{
    if (ob->handle) {
        ob->handle->timer = NULL;
    }
    PyTrack_MarkDeleted(ob);
    Py_Delete(ob);
}

static PyType_Slot timer_slots[] = {
    {Py_tp_dealloc, timer_dealloc},
    {0, 0},
};

static PyType_Spec timer_spec = {
    "promisedio.timer.Timer",
    sizeof(Timer),
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    timer_slots
};

static void
timer_callback(uv_timer_t *handle)
{
    ACQUIRE_GIL
        TimerHandle *h = Handle_Get(handle, TimerHandle);
        _CTX_set(h);
        Promise *promise = Promise_NewResolved(NULL, h->func);
        if (!promise) {
            PyErr_WriteUnraisable(h->func);
        }
        Py_XDECREF(promise);
        Handle_Close(h);
    RELEASE_GIL
}

static void
interval_callback(uv_timer_t *handle)
{
    ACQUIRE_GIL
        TimerHandle *h = Handle_Get(handle, TimerHandle);
        _CTX_set(h);
        Promise *promise = Promise_NewResolved(NULL, h->func);
        if (!promise) {
            PyErr_WriteUnraisable(h->func);
        }
        Py_XDECREF(promise);
    RELEASE_GIL
}

static void
timer_finalizer(TimerHandle *handle)
{
    if (handle->timer) {
        handle->timer->handle = NULL;
    }
    PyTrack_DECREF(handle->func);
}

CAPSULE_API(PyObject *)
Timer_Start(_ctx_var, PyObject *func, uint64_t timeout, uint64_t repeat)
{
    Loop_SETUP(loop)
    Timer *timer = (Timer *) Py_New(S(TimerType));
    if (!timer)
        return NULL;
    TimerHandle *handle = Handle_New(TimerHandle, timer_finalizer);
    if (!handle) {
        Py_DECREF(timer);
        return NULL;
    }
    PyTrack_MarkAllocated(timer);
    PyTrack_INCREF(func);
    handle->func = func;
    handle->timer = timer;
    timer->handle = handle;
    uv_timer_init(loop, &handle->base);
    if (repeat) {
        uv_timer_start(&handle->base, (uv_timer_cb) interval_callback, timeout, repeat);
    } else {
        uv_timer_start(&handle->base, (uv_timer_cb) timer_callback, timeout, 0);
    }
    uv_unref((uv_handle_t *) &handle->base);
    return (PyObject *) timer;
}

CAPSULE_API(int)
Timer_Stop(_ctx_var, PyObject *ob)
{
    if (Py_TYPE(ob) != S(TimerType)) {
        PyErr_SetString(PyExc_TypeError, "Timer object expected");
        return -1;
    }
    TimerHandle *handle = ((Timer *) ob)->handle;
    if (handle) {
        ((Timer *) ob)->handle = NULL;
        Handle_Close(handle);
    }
    return 0;
}

/*[clinic input]
timer.set_timeout
    func: object
    timeout: double
[clinic start generated code]*/

Py_LOCAL_INLINE(PyObject *)
timer_set_timeout_impl(PyObject *module, PyObject *func, double timeout)
/*[clinic end generated code: output=50946b1d85b2f6a4 input=d741422e983c75c8]*/
{
    if (!PyCallable_Check(func)) {
        PyErr_SetString(PyExc_TypeError, "func must be a callable");
        return NULL;
    }
    if (timeout < 0) {
        PyErr_SetString(PyExc_ValueError, "timeout must be non-negative");
        return NULL;
    }
    _CTX_set_module(module);
    return Timer_Start(_ctx, func, (uint64_t) (timeout * 1000), 0);
}

/*[clinic input]
timer.set_interval
    func: object
    interval: double
[clinic start generated code]*/

Py_LOCAL_INLINE(PyObject *)
timer_set_interval_impl(PyObject *module, PyObject *func, double interval)
/*[clinic end generated code: output=8fcf5927a08082b3 input=e147981db1e0c318]*/
{
    if (!PyCallable_Check(func)) {
        PyErr_SetString(PyExc_TypeError, "func must be a callable");
        return NULL;
    }
    if (interval < 0) {
        PyErr_SetString(PyExc_ValueError, "interval must be non-negative");
        return NULL;
    }
    _CTX_set_module(module);
    uint64_t timeout = (uint64_t) (interval * 1000);
    return Timer_Start(_ctx, func, timeout, timeout);
}

/*[clinic input]
timer.clear_timeout
    timer: object
[clinic start generated code]*/

Py_LOCAL_INLINE(PyObject *)
timer_clear_timeout_impl(PyObject *module, PyObject *timer)
/*[clinic end generated code: output=a1989760e1d3b1a8 input=b2cafa306c01792e]*/
{
    _CTX_set_module(module);
    if (Timer_Stop(_ctx, timer)) {
        return NULL;
    }
    Py_RETURN_NONE;
}

/*[clinic input]
timer.clear_interval
    timer: object
[clinic start generated code]*/

Py_LOCAL_INLINE(PyObject *)
timer_clear_interval_impl(PyObject *module, PyObject *timer)
/*[clinic end generated code: output=44cfa146bc5fed17 input=79bd857166af6be9]*/
{
    _CTX_set_module(module);
    if (Timer_Stop(_ctx, timer)) {
        return NULL;
    }
    Py_RETURN_NONE;
}

static int
timermodule_init(PyObject *module)
{
    _CTX_set_module(module);
    LOG("(%p)", module);
    Capsule_LOAD("promisedio.promise._promise", PROMISE_API);
    Capsule_LOAD("promisedio.loop._loop", LOOP_API);
    S(TimerType) = (PyTypeObject *) PyType_FromModuleAndSpec(module, &timer_spec, NULL);
    if (S(TimerType) == NULL)
        return -1;
    S(TimeoutError) = PyErr_NewException("promisedio.timer.TimeoutError", PyExc_Exception, NULL);
    if (!S(TimeoutError))
        return -1;
    PyObject *d = PyModule_GetDict(module);
    if (PyDict_SetItemString(d, "Timer", (PyObject *) S(TimerType)) < 0)
        return -1;
    if (PyDict_SetItemString(d, "TimeoutError", S(TimeoutError)) < 0)
        return -1;
    return 0;
}

/*[capsule:export TIMER_API_FUNCS]*/

/*[capsule:__exportblock__]*/
#define TIMER_API timer_api_87628408d36b58dc79fc1e618b008598
#define TIMER_API_FUNCS {\
  [0] = Timer_Timeout,\
  [1] = Timer_SetPromiseTimeout,\
  [2] = _Timer_UpdatePromiseTimeout,\
  [3] = _Timer_CancelPromiseTimeout,\
  [4] = Timer_Start,\
  [5] = Timer_Stop,\
}
/*[capsule:__endexportblock__]*/

static int
timermodule_create_api(PyObject *module)
{
    LOG("(%p)", module);
    Capsule_CREATE(module, TIMER_API, TIMER_API_FUNCS);
    return 0;
}

static int
timermodule_traverse(PyObject *module, visitproc visit, void *arg)
{
    _CTX_set_module(module);
    Capsule_VISIT(LOOP_API);
    Capsule_VISIT(PROMISE_API);
    Py_VISIT(S(TimerType));
    Py_VISIT(S(TimeoutError));
    return 0;
}

static int
timermodule_clear(PyObject *module)
{
    _CTX_set_module(module);
    Py_CLEAR(S(TimerType));
    Py_CLEAR(S(TimeoutError));
    return 0;
}

static void
timermodule_free(void *module)
{
    _CTX_set_module(module);
    LOG("(%p)", module);
    Capsule_CLEAR(LOOP_API);
    Capsule_CLEAR(PROMISE_API);
    timermodule_clear(module);
}

static PyMethodDef timermodule_methods[] = {
    TIMER_SLEEP_METHODDEF
    TIMER_CLEAR_INTERVAL_METHODDEF
    TIMER_CLEAR_TIMEOUT_METHODDEF
    TIMER_SET_INTERVAL_METHODDEF
    TIMER_SET_TIMEOUT_METHODDEF
    {NULL},
};

static PyModuleDef_Slot timermodule_slots[] = {
    {Py_mod_exec, timermodule_init},
    {Py_mod_exec, timermodule_create_api},
    {0, NULL},
};

static struct PyModuleDef timermodule_def = {
    PyModuleDef_HEAD_INIT,
    "promisedio.timer",
    NULL,
    sizeof(_modulestate),
    timermodule_methods,
    timermodule_slots,
    timermodule_traverse,
    timermodule_clear,
    timermodule_free,
};

PyMODINIT_FUNC
PyInit__timer(void)
{
    return PyModuleDef_Init(&timermodule_def);
}

PyMODINIT_FUNC
PyInit__timer_debug(void)
{
    return PyModuleDef_Init(&timermodule_def);
}