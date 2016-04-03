#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.8)

#Named the project `empathy`
project(empathy)

include(../load_sources.cmake)

add_custom_target(
        doc
        cldoc generate --std=c++11 -- --static --type html --output docs/docs/ ${EMPATHY_SOURCES}
)

find_package(PkgConfig REQUIRED)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})


add_library(empathy SHARED ${EMPATHY_SOURCES})


link_libraries(empathy
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES}
        )