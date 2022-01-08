cmake_minimum_required(VERSION 3.0.0)
project(d3d12_toies VERSION 0.1.0)

include(CTest)
enable_testing()

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(render_module)
add_subdirectory(render_d3d12)
add_subdirectory(testing)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
