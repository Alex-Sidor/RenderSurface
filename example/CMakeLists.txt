cmake_minimum_required(VERSION 3.10)
project(Example)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ ${CMAKE_CURRENT_BINARY_DIR}/RenderSurface)

file(GLOB SOURCES "src/*.cpp")
add_executable(Example ${SOURCES})

target_include_directories(Example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(Example PRIVATE RenderSurface)
