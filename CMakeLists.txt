cmake_minimum_required(VERSION 3.10)
project(RenderSurface)

add_library(glad STATIC deps/glad/src/glad.c)
target_include_directories(glad PUBLIC deps/glad/include)

add_subdirectory(deps/glfw)

find_package(OpenGL REQUIRED)

file(GLOB SOURCES "src/*.cpp")
add_library(RenderSurface STATIC ${SOURCES})

target_include_directories(RenderSurface PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(RenderSurface PUBLIC glad glfw OpenGL::GL)
