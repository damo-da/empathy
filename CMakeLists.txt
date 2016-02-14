#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.8)

#Named the project `empathy`
project(empathy)

#set source code

file(GLOB EMPATHY_LIFE_EVENT_SRC "Empathy/LifeEvent/*.hpp" "Empathy/LifeEvent/*.cpp")
file(GLOB EMPATHY_YOU_SRC "Empathy/You/*.hpp" "Empathy/You/*.cpp")

set (LEMPATHY_SOURCES
        LEmpathy/LoonLight.cpp
        LEmpathy/LoonLight.h
        LEmpathy/lempathy.hpp
        LEmpathy/lempathy.cpp
        LEmpathy/__main__.cpp
        )
set (EMPATHY_SOURCES

        Empathy/empathy.hpp
        Empathy/empathy.cpp

        Empathy/global.hpp

        Empathy/Uniqueness.h
        Empathy/Uniqueness.cpp

        Empathy/LifeEvent/life_event.cpp
        Empathy/LifeEvent/life_event.hpp

        Empathy/You/you.cpp
        Empathy/You/you.hpp

        Empathy/You/Brain/Brain.cpp
        Empathy/You/Brain/Brain.h

        Empathy/You/Brain/DummyBrain/DummyBrain.cpp
        Empathy/You/Brain/DummyBrain/DummyBrain.h
        Empathy/You/Brain/QueryStringParser/QueryStringParser.cpp
        Empathy/You/Brain/QueryStringParser/QueryStringParser.h
        Empathy/You/Brain/QueryStringParser/QueryStringBlock.cpp
        Empathy/You/Brain/QueryStringParser/QueryStringBlock.h
        Empathy/You/Brain/QueryStringParser/QueryStringLine.cpp
        Empathy/You/Brain/QueryStringParser/QueryStringLine.h

        Empathy/Implements/EmpathyBinder.cpp
        Empathy/Implements/EmpathyBinder.h
        Empathy/Implements/MoonLight.cpp
        Empathy/Implements/MoonLight.h
        Empathy/Implements/MoonLightBinder.cpp
        Empathy/Implements/MoonLightBinder.h

        Empathy/RadioStation/BroadcastStation.cpp
        Empathy/RadioStation/BroadcastStation.h
        Empathy/RadioStation/Event.cpp
        Empathy/RadioStation/Event.h
        Empathy/RadioStation/Subscriber.cpp
        Empathy/RadioStation/Subscriber.h
        Empathy/RadioStation/TimeBroadcaster.cpp
        Empathy/RadioStation/TimeBroadcaster.h
        Empathy/RadioStation/TimeBroadcasterObject.cpp
        Empathy/RadioStation/TimeBroadcasterObject.h

        Empathy/LifeEvent/MathWave/MathWave.cpp
        Empathy/LifeEvent/MathWave/MathWave.h
        Empathy/LifeEvent/MathWave/MathWave_Sinc.h
        Empathy/LifeEvent/MathWave/MathWave_Sinc.cpp
        Empathy/LifeEvent/MathWave/MathWave_Sine.h
        Empathy/LifeEvent/MathWave/MathWave_Sine.cpp
        Empathy/LifeEvent/MathWave/MathWave_Line.cpp
        Empathy/LifeEvent/MathWave/MathWave_Line.h
        Empathy/LifeEvent/FadeInOut/FadeInOut.cpp
        Empathy/LifeEvent/FadeInOut/FadeInOut.h
        Empathy/LifeEvent/LifeEvent_Collection.cpp
        Empathy/LifeEvent/LifeEvent_Collection.h
        Empathy/LifeEvent/CWave/LifeEvent_CWave.cpp
        Empathy/LifeEvent/CWave/LifeEvent_CWave.h
        Empathy/LifeEvent/CWave/LifeEvent_CWave_data.cpp
        Empathy/LifeEvent/CWave/LifeEvent_CWave_data.h
        Empathy/LifeEvent/MathWave/MathWave_Para_Circle.cpp
        Empathy/LifeEvent/MathWave/MathWave_Para_Circle.h

        Empathy/Shader/DefaultShader.cpp
        Empathy/Shader/DefaultShader.h
        Empathy/Shader/DefaultShader.cpp
        Empathy/Shader/DefaultShader.h
        Empathy/Shader/shader_utils.cpp
        Empathy/Shader/shader_utils.h

        Empathy/PureMath/Wave.cpp
        Empathy/PureMath/Wave.h

        Empathy/Utils/Color.cpp
        Empathy/Utils/Color.h
        Empathy/Utils/file_utils.cpp
        Empathy/Utils/file_utils.h
        )

set(SOURCES
        ${EMPATHY_SOURCES}
        ${LEMPATHY_SOURCES}
        Empathy/You/Brain/MusicalBrain/MusicalBrain.cpp Empathy/You/Brain/MusicalBrain/MusicalBrain.h Empathy/Utils/string_utils.cpp Empathy/Utils/string_utils.h Empathy/Packages/CanonInD.cpp Empathy/Packages/CanonInD.h)
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

include_directories(LEmpathy/libs/irrKlang-64bit-1.5.0/include/)

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


        "${CMAKE_CURRENT_SOURCE_DIR}/LEmpathy/libs/irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so"
#        "${CMAKE_CURRENT_SOURCE_DIR}/LEmpathy/libs/irrKlang-64bit-1.5.0/bin/linux-gcc-64/ikpMP3.so"
        )
