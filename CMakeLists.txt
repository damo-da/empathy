#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.8)

#Named the project `empathy`
project(empathy)

find_package(PkgConfig REQUIRED)

set(EMPATHY_SOURCES_BASE "include/Empathy")
include(load_sources.cmake)
add_library(empathy SHARED ${EMPATHY_SOURCES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

pkg_search_module(MUPARSER REQUIRED muparser)
include_directories(${MUPARSER_INCLUDE_DIRS})


target_link_libraries(empathy
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${MUPARSER_LIBRARIES}
        )

add_definitions(-DSTANDALONE_EMPATHY=true)

#add to the last of the file because it modifies the EMPATHY_SOURCES variable
set(EMPATHY_SOURCES_BASE "../include/Empathy")
include(load_sources.cmake)
add_custom_target(
        doc
        cldoc generate --std=c++11 -- --static --type html --output ../docs/docs/ ${EMPATHY_SOURCES}
)

