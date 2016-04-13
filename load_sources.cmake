#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.8)

if(EMPATHY_SOURCES_BASE)

else()
    set(EMPATHY_SOURCES_BASE ".")
endif()

set (EMPATHY_SOURCES
        ${EMPATHY_SOURCES_BASE}/empathy-linear/linear_empathy.cpp
        ${EMPATHY_SOURCES_BASE}/empathy-linear/linear_moonlight.cpp

        ${EMPATHY_SOURCES_BASE}/Empathy/Empathy.h
        ${EMPATHY_SOURCES_BASE}/Empathy/Empathy.cpp

        ${EMPATHY_SOURCES_BASE}/Utils/UniqueObject.h
        ${EMPATHY_SOURCES_BASE}/Utils/UniqueObject.cpp

        ${EMPATHY_SOURCES_BASE}/LifeEvent/LifeEvent.cpp
        ${EMPATHY_SOURCES_BASE}/LifeEvent/LifeEvent.h

        ${EMPATHY_SOURCES_BASE}/You/you.cpp
        ${EMPATHY_SOURCES_BASE}/You/you.h

        ${EMPATHY_SOURCES_BASE}/Brain/Brain.cpp
        ${EMPATHY_SOURCES_BASE}/Brain/Brain.h

        ${EMPATHY_SOURCES_BASE}/Brain/DummyBrain/DummyBrain.cpp
        ${EMPATHY_SOURCES_BASE}/Brain/DummyBrain/DummyBrain.h

        ${EMPATHY_SOURCES_BASE}/MoonLight/MoonLight.cpp
        ${EMPATHY_SOURCES_BASE}/MoonLight/MoonLight.h
        ${EMPATHY_SOURCES_BASE}/MoonLight/BasicNote.cpp

        ${EMPATHY_SOURCES_BASE}/RadioStation/BroadcastStation.cpp
        ${EMPATHY_SOURCES_BASE}/RadioStation/BroadcastStation.h
        ${EMPATHY_SOURCES_BASE}/RadioStation/Event.cpp
        ${EMPATHY_SOURCES_BASE}/RadioStation/Event.h
        ${EMPATHY_SOURCES_BASE}/RadioStation/Subscriber.cpp
        ${EMPATHY_SOURCES_BASE}/RadioStation/Subscriber.h
        ${EMPATHY_SOURCES_BASE}/RadioStation/TimeBroadcaster.cpp
        ${EMPATHY_SOURCES_BASE}/RadioStation/TimeBroadcaster.h
        ${EMPATHY_SOURCES_BASE}/RadioStation/TimeBroadcasterObject.cpp
        ${EMPATHY_SOURCES_BASE}/RadioStation/TimeBroadcasterObject.h

        ${EMPATHY_SOURCES_BASE}/LifeEvent/MathWave/MathWave.cpp
        ${EMPATHY_SOURCES_BASE}/LifeEvent/MathWave/MathWave.h
        ${EMPATHY_SOURCES_BASE}/LifeEvent/MathWave/MathWave_Sinc.h
        ${EMPATHY_SOURCES_BASE}/LifeEvent/MathWave/MathWave_Sinc.cpp
        ${EMPATHY_SOURCES_BASE}/LifeEvent/MathWave/MathWave_Sine.h
        ${EMPATHY_SOURCES_BASE}/LifeEvent/MathWave/MathWave_Sine.cpp
        ${EMPATHY_SOURCES_BASE}/LifeEvent/MathWave/MathWave_Line.cpp
        ${EMPATHY_SOURCES_BASE}/LifeEvent/MathWave/MathWave_Line.h
        ${EMPATHY_SOURCES_BASE}/LifeEvent/FadeInOut/FadeInOut.cpp
        ${EMPATHY_SOURCES_BASE}/LifeEvent/FadeInOut/FadeInOut.h
        ${EMPATHY_SOURCES_BASE}/LifeEvent/Collection.cpp
        ${EMPATHY_SOURCES_BASE}/LifeEvent/Collection.h
        ${EMPATHY_SOURCES_BASE}/LifeEvent/CWave/CWave.cpp
        ${EMPATHY_SOURCES_BASE}/LifeEvent/CWave/CWave.h
        ${EMPATHY_SOURCES_BASE}/LifeEvent/CWave/CWave_data.cpp
        ${EMPATHY_SOURCES_BASE}/LifeEvent/CWave/CWave_data.h
        ${EMPATHY_SOURCES_BASE}/LifeEvent/MathWave/MathWave_Para_Circle.cpp
        ${EMPATHY_SOURCES_BASE}/LifeEvent/MathWave/MathWave_Para_Circle.h
        ${EMPATHY_SOURCES_BASE}/LifeEvent/Background/Background.cpp
        ${EMPATHY_SOURCES_BASE}/LifeEvent/Background/Background_Transition.cpp

        ${EMPATHY_SOURCES_BASE}/Shader/DefaultShader.cpp
        ${EMPATHY_SOURCES_BASE}/Shader/DefaultShader.h
        ${EMPATHY_SOURCES_BASE}/Shader/DefaultShader.cpp
        ${EMPATHY_SOURCES_BASE}/Shader/DefaultShader.h
        ${EMPATHY_SOURCES_BASE}/Shader/shader_utils.cpp
        ${EMPATHY_SOURCES_BASE}/Shader/shader_utils.h

        ${EMPATHY_SOURCES_BASE}/PureMath/Wave.cpp
        ${EMPATHY_SOURCES_BASE}/PureMath/Wave.h

        ${EMPATHY_SOURCES_BASE}/Utils/Color.cpp
        ${EMPATHY_SOURCES_BASE}/Utils/Color.h
        ${EMPATHY_SOURCES_BASE}/Utils/file_utils.cpp
        ${EMPATHY_SOURCES_BASE}/Utils/file_utils.h

        ${EMPATHY_SOURCES_BASE}/Brain/MusicalBrain/MusicalBrain.cpp
        ${EMPATHY_SOURCES_BASE}/Brain/MusicalBrain/MusicalBrain.h
        ${EMPATHY_SOURCES_BASE}/Utils/string_utils.cpp
        ${EMPATHY_SOURCES_BASE}/Utils/string_utils.h

        ${EMPATHY_SOURCES_BASE}/Libs/cJSON/cJSON.c
        ${EMPATHY_SOURCES_BASE}/Libs/cJSON/cJSON.h
        ${EMPATHY_SOURCES_BASE}/Brain/JSONBrain/JSONBrain.cpp
        ${EMPATHY_SOURCES_BASE}/Brain/JSONBrain/JSONBrain.h
        ${EMPATHY_SOURCES_BASE}/Libs/cJSON/cJSON_utils.cpp
        ${EMPATHY_SOURCES_BASE}/Libs/cJSON/cJSON_utils.h


        ${EMPATHY_SOURCES_BASE}/empathy.h
        ${EMPATHY_SOURCES_BASE}/global.h
        ${EMPATHY_SOURCES_BASE}/global.cpp

        ${EMPATHY_SOURCES_BASE}/Brain/DummyTouchBrain/DummyTouchBrain.cpp
        ${EMPATHY_SOURCES_BASE}/Brain/DummyTouchBrain/DummyTouchBrain.h
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

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")