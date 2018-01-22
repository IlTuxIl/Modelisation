cmake_minimum_required(VERSION 3.5)
project(Modelisation)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOUIC ON)
INCLUDE(FindPkgConfig)

include_directories(include)
include_directories(lib)

file(GLOB GKIT lib/*.cpp lib/*.h)
file(GLOB SOURCES src/*.cpp include/*.h)
file(GLOB QTSRC src/*.cpp include/*.h src/Modelisation/*.cpp src/Modelisation/*.h)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(QT)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

add_executable(Modelisation ${SOURCES} ${GKIT})
target_link_libraries(Modelisation ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${GLEW_LIBRARY})

list(REMOVE_ITEM QTSRC "src/main.cpp")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
add_executable(QtModelisation ${GKIT} ${QTSRC})
target_link_libraries(QtModelisation ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} Qt5::Widgets Qt5::Core Qt5::Gui ${GLEW_LIBRARY})
