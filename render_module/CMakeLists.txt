cmake_minimum_required(VERSION 3.0.0)
project(render_module VERSION 0.1.0 LANGUAGES CXX)

find_library(DXGI_LIB dxgi)
find_library(D3D12_LIB d3d12)


set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED 17)
include_directories(include)
add_library(render_module SHARED
    src/render_module.cpp
    src/render_manager.cpp
    )
target_link_libraries(render_module ${DXGI_LIB} ${D3D12_LIB})
add_compile_definitions(RENDER_MODULE_EXPORT)