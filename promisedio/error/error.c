// Copyright (c) 2021-2022 Andrey Churin <aachurin@gmail.com> Promisedio

#include <promisedio_uv.h>

int
errormodule_init(PyObject *module)
{
    LOG("(%p)", module);
#define XX(code, _) if (PyModule_AddIntConstant(module, #code, UV_ ## code)) return -1;
    UV_ERRNO_MAP(XX)
#undef XX
    return 0;
}

static void
errormodule_free(__attribute__((unused)) void *module)
{
    LOG("(%p)", module);
}

static PyModuleDef_Slot errormodule_slots[] = {
    {Py_mod_exec, errormodule_init},
    {0, NULL}
};

static struct PyModuleDef errormodule_def = {
    PyModuleDef_HEAD_INIT,
    .m_name = "promisedio.error",
    .m_slots = errormodule_slots,
    .m_free = errormodule_free
};

PyMODINIT_FUNC
PyInit__error(void)
{
    return PyModuleDef_Init(&errormodule_def);
}

PyMODINIT_FUNC
PyInit__error_debug(void)
{
    return PyModuleDef_Init(&errormodule_def);
}
