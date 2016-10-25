#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.8)

#Named the project `empathy`
project(empathy)

include(load_libraries.cmake)


set(EMPATHY_SOURCES_BASE "include/Empathy")
include(load_sources.cmake)
add_library(empathy SHARED ${EMPATHY_SOURCES})


target_link_libraries(empathy
        ${EMPATHY_DEPENDENCY_LIBRARIES}
        )

add_definitions(-DSTANDALONE_EMPATHY=true)

#add to the last of the file because it modifies the EMPATHY_SOURCES variable
set(EMPATHY_SOURCES_BASE "../include/Empathy")
include(load_sources.cmake)
add_custom_target(
        doc
	cldoc generate --std=c++11 `pkg-config --cflags opencv` -- --static --type html --output ../docs/docs/ ${EMPATHY_SOURCES}
)

