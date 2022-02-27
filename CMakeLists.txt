# this file is only for clion (not for building)

cmake_minimum_required(VERSION 3.19)
project(promisedio_uv C)

add_compile_options(-Werror)
set(CMAKE_C_STANDARD 11)
execute_process(COMMAND bash "-c" "poetry env list --full-path | cut -d' ' -f1" OUTPUT_VARIABLE poetry_env)
string(REGEX REPLACE "\n$" "" poetry_env "${poetry_env}")

include_directories(/Library/Frameworks/Python.framework/Versions/3.10/include/python3.10)
include_directories(/usr/local/Cellar/libuv/1.41.0/include)
include_directories(${poetry_env}/lib/python3.10/site-packages/promisedio_build_environment/include)
include_directories(${poetry_env}/lib/python3.10/site-packages/promisedio/promise/capsule)
include_directories(promisedio/fs/capsule)
include_directories(promisedio/ns/capsule)
include_directories(promisedio/loop/capsule)
include_directories(promisedio/timer/capsule)
include_directories(promisedio/signal/capsule)

add_definitions(-DBUILD_DEBUG_LOG -DBUILD_DEBUG_MEM)
add_library(promisedio.error SHARED
            promisedio/error/error.c)

add_library(promisedio.loop SHARED
            promisedio/loop/loop.c)

add_library(promisedio.timer SHARED
            promisedio/timer/timer.c)

add_library(promisedio.signal SHARED
            promisedio/signal/signal.c)

add_library(promisedio.fs SHARED
            promisedio/fs/fs.c)

add_library(promisedio.ns SHARED
            promisedio/ns/ns.c)
