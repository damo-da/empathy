//
// Created by damo on 2/5/16.
//

#include "LifeEvent_CWave.h"
#include "LifeEvent_CWave_data.h"
#include "../RadioStation/TimeBroadcaster.h"
using namespace std;

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
        LifeEvent_CWave_data * data=new LifeEvent_CWave_data(centerX,centerY);
        data->init();
        data->setDepth(getDepth());
        data->setFrequency(getFrequency());
        data->setWaveLength(getWavelength());
        data->setColor(color[0],color[1],color[2],color[3]);

        //create a callback for next wave
        createTimeOut(getTimePeriod(),EMPATHY_LIFE_EVENT_CWAVE_CREATE_NEW_WAVE);

        addToCollection(data);

        shouldCreateNewWave=false;
    }
//
//    std::vector<LifeEvent *> waveData=getCollection();
//    for (int i = 0; i < waveData.size(); i++) {
//        LifeEvent_CWave_data * data=(LifeEvent_CWave_data *)waveData[i];
//        if (data->getRadius() > 2.0f) {
//
////            data->kill();
//
////            removeFromCollection(data);
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

void LifeEvent_CWave::onReceiveEvent(Event &event) {
    Subscriber::onReceiveEvent(event);

    if(event.action==EMPATHY_EVENT_REPEAT_TIMEOUT ||
       event.action==EMPATHY_EVENT_TIMEOUT){

        shouldCreateNewWave=true;

        //broadcast that a period is complete
        Event e(EMPATHY_LIFE_EVENT_CWAVE_PERIOD_COMPLETE);
        emit(e);

    }else{

    }
}
