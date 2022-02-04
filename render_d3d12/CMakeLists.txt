cmake_minimum_required(VERSION 3.0.0)
project(render_module_d3d12 VERSION 0.1.0 LANGUAGES CXX)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED 17)

if(NOT MSVC AND WIN32)
    add_definitions(-D_WIN32_WINNT=_WIN32_WINNT_WIN10)
endif()

include_directories(include)
include_directories(../render_module/include)

add_library(render_d3d12 SHARED
        src/main.cpp src/Manager.cpp src/Manager.h src/render_d3d12.h src/PhysicalDevice.cpp src/PhysicalDevice.h src/Output.cpp src/Output.h src/Renderer.cpp src/Renderer.h src/SwapChain.cpp src/SwapChain.h)
target_link_libraries(render_d3d12 dxgi.lib d3d12.lib)
set_property(TARGET render_d3d12 PROPERTY CXX_STANDARD 17)

add_compile_definitions(RENDER_MODULE_D3D12_EXPORT)