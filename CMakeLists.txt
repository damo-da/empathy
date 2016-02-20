#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.8)

#Named the project `empathy`
project(empathy)

#set source code

set (DEMPATHY_SOURCES
        DEmpathy/DoonLight.cpp
        DEmpathy/DoonLight.h
        DEmpathy/DEmpathy.h
        DEmpathy/DEmpathy.cpp
        DEmpathy/__main__.cpp
        )
set (EMPATHY_SOURCES

        Empathy/empathy.h
        Empathy/empathy.cpp

        Empathy/global.h

        Empathy/Utils/Uniqueness.h
        Empathy/Utils/Uniqueness.cpp

        Empathy/LifeEvent/LifeEvent.cpp
        Empathy/LifeEvent/LifeEvent.h

        Empathy/You/you.cpp
        Empathy/You/you.h

        Empathy/Brain/Brain.cpp
        Empathy/Brain/Brain.h

        Empathy/Brain/DummyBrain/DummyBrain.cpp
        Empathy/Brain/DummyBrain/DummyBrain.h

        Empathy/MoonLight/MoonLight.cpp
        Empathy/MoonLight/MoonLight.h

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
        Empathy/LifeEvent/Collection.cpp
        Empathy/LifeEvent/Collection.h
        Empathy/LifeEvent/CWave/CWave.cpp
        Empathy/LifeEvent/CWave/CWave.h
        Empathy/LifeEvent/CWave/CWave_data.cpp
        Empathy/LifeEvent/CWave/CWave_data.h
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
        ${DEMPATHY_SOURCES}
        Empathy/Brain/MusicalBrain/MusicalBrain.cpp
        Empathy/Brain/MusicalBrain/MusicalBrain.h
        Empathy/Utils/string_utils.cpp
        Empathy/Utils/string_utils.h

        Empathy/Libs/cJSON/cJSON.c
        Empathy/Libs/cJSON/cJSON.h
        Empathy/Brain/JSONBrain/JSONBrain.cpp
        Empathy/Brain/JSONBrain/JSONBrain.h
        Empathy/Libs/cJSON/cJSON_utils.cpp
        Empathy/Libs/cJSON/cJSON_utils.h
        DEmpathy/tests/CWave_Test.cpp DEmpathy/tests/CWave_Test.h Empathy/e.h Empathy/LifeEvent/include.h Empathy/MoonLight/include.h Empathy/Brain/include.h Empathy/PureMath/include.h)
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

#        "${CMAKE_CURRENT_SOURCE_DIR}/DEmpathy/libs/irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so"
        "${CMAKE_CURRENT_SOURCE_DIR}/DEmpathy/libs/irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so"
#        "${CMAKE_CURRENT_SOURCE_DIR}/DEmpathy/libs/irrKlang-64bit-1.5.0/bin/linux-gcc-64/ikpMP3.so"
        )
