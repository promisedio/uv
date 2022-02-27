// Auto-generated

#ifndef CAPSULE_SIGNAL_API
#define CAPSULE_SIGNAL_API

#include "promisedio_uv.h"

static int signal_api_4e247f2dad1d0a8160b909b158b7b95e__API_LOADED = 0;
static void *signal_api_4e247f2dad1d0a8160b909b158b7b95e__API[1];

#define SIGNAL_API signal_api_4e247f2dad1d0a8160b909b158b7b95e

#define SIGNAL_SETSIGEVENT_ID 0
#define Signal_SetSigEvent(...) \
  ((void (*) (sigevent cb))(signal_api_4e247f2dad1d0a8160b909b158b7b95e__API[SIGNAL_SETSIGEVENT_ID]))( \
    __VA_ARGS__)

#endif
