import pkg_resources
from setuptools.extension import Extension
from setuptools.command.build_ext import build_ext

define_macros_release = [
    ("Py_BUILD_CORE", "1")
]

define_macros_debug = define_macros_release + [
    ("BUILD_DEBUG_LOG", "1"),
    ("BUILD_DEBUG_MEM", "1"),
    # ("BUILD_DISABLE_FREELISTS", "1")
]

undef_macros_debug = ["NDEBUG"]

build_environment_include = pkg_resources.resource_filename("promisedio_build_environment", "include")
promise_include = pkg_resources.resource_filename("promisedio.promise", "capsule")
project_capsules = [
    "promisedio/fs/capsule",
    "promisedio/ns/capsule",
    "promisedio/loop/capsule",
    "promisedio/timer/capsule",
    "promisedio/signal/capsule",
]

extension_defaults = {
    "include_dirs": [build_environment_include, promise_include] + project_capsules,
    "extra_compile_args": ["-O2"],
    "libraries": ["uv"]
}


def extension(name, sources):
    return [
        Extension(
            name,
            sources=sources,
            define_macros=define_macros_release,
            **extension_defaults
        ),
        Extension(
            name + "_debug",
            sources=sources,
            define_macros=define_macros_debug,
            undef_macros=undef_macros_debug,
            **extension_defaults
        ),
    ]


ext_modules = \
    extension(
        "promisedio.error._error",
        sources=["promisedio/error/error.c"],
    ) + \
    extension(
        "promisedio.loop._loop",
        sources=["promisedio/loop/loop.c"],
    ) + \
    extension(
        "promisedio.timer._timer",
        sources=["promisedio/timer/timer.c"],
    ) + \
    extension(
        "promisedio.signal._signal",
        sources=["promisedio/signal/signal.c"],
    ) + \
    extension(
        "promisedio.fs._fs",
        sources=["promisedio/fs/fs.c"],
    ) + \
    extension(
        "promisedio.ns._ns",
        sources=["promisedio/ns/ns.c"],
    )


def build(setup_kwargs):
    setup_kwargs.update({
        "ext_modules": ext_modules,
        "cmdclass": {"build_ext": build_ext}
    })
