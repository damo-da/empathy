#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.8)

find_package(PkgConfig REQUIRED)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(Freetype REQUIRED)
include_directories(${FREETYPE_INCLUDE_DIRS})

pkg_search_module(MUPARSER REQUIRED muparser)
include_directories(${MUPARSER_INCLUDE_DIRS})

set(EMPATHY_DEPENDENCY_LIBRARIES
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${MUPARSER_LIBRARIES}
        ${FREETYPE_LIBRARIES}
        )