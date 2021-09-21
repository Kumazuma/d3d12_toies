cmake_minimum_required(VERSION 3.0.0)
project(render_module VERSION 0.1.0 LANGUAGES CXX)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED 17)
include_directories(include)
add_library(render_module src/render_module.cpp)