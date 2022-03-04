// Auto-generated

#ifndef CAPSULE_LOOP_API
#define CAPSULE_LOOP_API

static int loop_api_eb88af6ea3ab9016eef7b258104871ed__LOADED = 0;
static void *loop_api_eb88af6ea3ab9016eef7b258104871ed__API[1];

#define LOOP_API loop_api_eb88af6ea3ab9016eef7b258104871ed

#include <promisedio_uv.h>
#include "promisedio/promise.h"

#define LOOP_GET_ID 0
#define Loop_Get() \
  ((uv_loop_t * (*) (void*))(loop_api_eb88af6ea3ab9016eef7b258104871ed__API[LOOP_GET_ID]))( \
    _ctx->loop_api_eb88af6ea3ab9016eef7b258104871ed__CTX)

#endif
