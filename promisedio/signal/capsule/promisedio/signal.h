// Auto-generated

#ifndef CAPSULE_SIGNAL_API
#define CAPSULE_SIGNAL_API

static int signal_api_38411d0ea922188b27adb85d702ca4e2__LOADED = 0;
static void *signal_api_38411d0ea922188b27adb85d702ca4e2__API[1];

#define SIGNAL_API signal_api_38411d0ea922188b27adb85d702ca4e2

#include <promisedio_uv.h>

#define SIGNAL_SETSIGEVENT_ID 0
#define Signal_SetSigEvent(...) \
  ((void (*) (sigevent cb))(signal_api_38411d0ea922188b27adb85d702ca4e2__API[SIGNAL_SETSIGEVENT_ID]))( \
    __VA_ARGS__)

#endif
