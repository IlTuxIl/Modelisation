cmake_minimum_required(VERSION 3.8)
project(Modelisation)

set(CMAKE_CXX_STANDARD 17)

INCLUDE(FindPkgConfig)

include_directories(include)
include_directories(lib)

file(GLOB GKIT lib/*.cpp lib/*.h)
file(GLOB SOURCES src/*.cpp include/*.h)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

add_executable(Modelisation ${SOURCES} ${GKIT})
target_link_libraries(Modelisation ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${GLEW_LIBRARY})