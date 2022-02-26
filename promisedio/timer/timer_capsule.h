#define Timer_CancelPromiseTimeout(promise)             \
    if (promise->timer)                                 \
        _Timer_CancelPromiseTimeout(promise)

#define Timer_UpdatePromiseTimeout(promise, callback)   \
    if (promise->timer)                                 \
        _Timer_UpdatePromiseTimeout(promise, callback)
