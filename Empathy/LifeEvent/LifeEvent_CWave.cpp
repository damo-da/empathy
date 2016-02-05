//
// Created by damo on 2/5/16.
//

#include "LifeEvent_CWave.h"
#include "Wave/wave_data.hpp"

LifeEvent_CWave::LifeEvent_CWave() : LifeEvent_Collection() {

}

void LifeEvent_CWave::onInit() {
    LifeEvent_Collection::onInit();

    frequency=0.95f;
    waveLength = 0.1f;

    shouldCreateNewWave=true;

    color = {1.0f, 1.0f, 1.0f, 1.0f};
}


void LifeEvent_CWave::passTime(GLfloat delTime) {
    LifeEvent_Collection::passTime(delTime);

    if(shouldCreateNewWave){

        //create the new wave
        WaveData data( 0.0f, centerX, centerY, true);
        data.setDepth(getDepth());

        //create a callback for next wave
        createTimeOut(getTimePeriod(),EMPATHY_LIFE_EVENT_CWAVE_CREATE_NEW_WAVE);

//        addToCollection(data);

        shouldCreateNewWave=false;
    }

//    for (int i = 0; i < waveData.size(); i++) {
//
//        waveData[i].radius += getWaveSpeed()*delTime;
//        waveData[i].calculateGlVertices();
//
//        if (waveData[i].radius > 2.0f) {
//
//            waveData[i].destroy();
//
//            waveData.erase(waveData.begin() + i);
//            i--;
//        }
//    }
}

LifeEvent_CWave::LifeEvent_CWave(GLfloat cX, GLfloat cY):
        centerX(cX),
        centerY(cY)
{

}

void LifeEvent_CWave::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    color = {r, g, b, a};
}
