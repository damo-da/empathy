#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.8)

#Named the project `empathy`
project(empathy)

#set source code
file(GLOB LEMPATHY_SRC "LEmpathy/*.hpp" "LEmpathy/*.cpp")
file(GLOB EMPATHY_SRC "Empathy/*.hpp" "Empathy/*.cpp")
file(GLOB EMPATHY_REALITY_SRC "Empathy/Reality/*.hpp" "Empathy/Reality/*.cpp")
file(GLOB EMPATHY_LIFE_EVENT_SRC "Empathy/LifeEvent/*.hpp" "Empathy/LifeEvent/*.cpp" "Empathy/LifeEvent/Wave/*.cpp")
file(GLOB EMPATHY_YOU_SRC "Empathy/You/*.hpp" "Empathy/You/*.cpp")


set (SOURCES 
	${LEMPATHY_SRC}

	${EMPATHY_SRC}

	${EMPATHY_REALITY_SRC}
	${EMPATHY_LIFE_EVENT_SRC}
	${EMPATHY_YOU_SRC}
	)

#support for nullptr, etc
add_definitions(-std=c++0x)

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

#add source files for compilation
add_executable(empathy ${SOURCES})

#link the libraries
 target_link_libraries(empathy ${GLFW_STATIC_LIBRARIES} ${GLEW_LIBRARIES} ${x11_LIBRARIES} ${xi_LIBRARIES} ${OPENGL_LIBRARIES} ${xxf86vm_LIBRARIES} ${xrandr_LIBRARIES})
