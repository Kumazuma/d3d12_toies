cmake_minimum_required(VERSION 3.0.0)
project(render_test VERSION 0.1.0 LANGUAGES CXX)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED 17)
include_directories(${CMAKE_SOURCE_DIR}/render_module/include)
add_executable(render_test src/main.cpp)
target_link_libraries(render_test  render_module)
#configure_file(render_module ${CMAKE_BINARY_DIR} COPYONLY)