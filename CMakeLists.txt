#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.8)

include(Empathy/config.cmake)

#set source code

set (DEMPATHY_SOURCES
        DEmpathy/DoonLight.cpp
        DEmpathy/DoonLight.h
        DEmpathy/DEmpathy.h
        DEmpathy/DEmpathy.cpp
        DEmpathy/__main__.cpp
        )

set(SOURCES
        ${EMPATHY_SOURCES}
        ${DEMPATHY_SOURCES}
        )


#include libraries
find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

pkg_search_module(x11 REQUIRED x11)
include_directories(${x11_INCLUDE_DIRS})

pkg_search_module(xrandr REQUIRED xrandr)
include_directories(${xrandr_INCLUDE_DIRS})

pkg_search_module(xi REQUIRED xi)
include_directories(${xi_INCLUDE_DIRS})

pkg_search_module(xxf86vm REQUIRED xxf86vm)
include_directories(${xxf86vm_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

include_directories(DEmpathy/libs/irrKlang-64bit-1.5.0/include/)

#add source files for compilation
add_executable(empathy ${SOURCES})


#link the libraries
target_link_libraries(empathy
        ${GLFW_STATIC_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${x11_LIBRARIES}
        ${xi_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${xxf86vm_LIBRARIES}
        ${xrandr_LIBRARIES}

        "${CMAKE_CURRENT_SOURCE_DIR}/DEmpathy/libs/irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so"
        )

