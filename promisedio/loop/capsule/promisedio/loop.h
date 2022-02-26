// Auto-generated

#ifndef CAPSULE_LOOP_API
#define CAPSULE_LOOP_API

#include "promisedio_uv.h"

static int loop_api_213e92bb8996a97c068288110bac7fb8__api_loaded = 0;
static void *loop_api_213e92bb8996a97c068288110bac7fb8__api[1];

#define LOOP_API loop_api_213e92bb8996a97c068288110bac7fb8

#define LOOP_GET_ID 0
#define Loop_Get() \
  ((uv_loop_t * (*) (void*))(loop_api_213e92bb8996a97c068288110bac7fb8__api[LOOP_GET_ID]))( \
    _ctx->loop_api_213e92bb8996a97c068288110bac7fb8__ctx)

#endif
