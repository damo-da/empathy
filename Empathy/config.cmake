#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.8)

#Named the project `empathy`
project(empathy)

set (EMPATHY_SOURCES

        Empathy/Empathy/Empathy.h
        Empathy/Empathy/Empathy.cpp

        Empathy/Utils/UniqueObject.h
        Empathy/Utils/UniqueObject.cpp

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


        Empathy/empathy.h
        Empathy/Brain/DummyTouchBrain/DummyTouchBrain.cpp Empathy/Brain/DummyTouchBrain/DummyTouchBrain.h
        )

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


add_custom_target(
        doc
        cldoc generate --std=c++11 -- --static --type html --output docs/docs/ ${EMPATHY_SOURCES}
)

find_package(PkgConfig REQUIRED)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

