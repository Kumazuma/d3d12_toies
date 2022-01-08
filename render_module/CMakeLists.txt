cmake_minimum_required(VERSION 3.0.0)
project(render_module VERSION 0.1.0 LANGUAGES CXX)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED 17)

if(NOT MSVC AND WIN32)
    add_definitions(-D_WIN32_WINNT=_WIN32_WINNT_WIN10)
endif()

include_directories(include)
add_library(render_module SHARED
    src/main.cpp)

set_property(TARGET render_module PROPERTY CXX_STANDARD 17)

add_compile_definitions(RENDER_MODULE_EXPORT)
