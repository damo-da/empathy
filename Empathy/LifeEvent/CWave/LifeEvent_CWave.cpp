//
// Created by damo on 2/5/16.
//

#include "LifeEvent_CWave.h"
#include "LifeEvent_CWave_data.h"
#include "../../RadioStation/TimeBroadcaster.h"
using namespace std;

LifeEvent_CWave::LifeEvent_CWave() : LifeEvent_Collection(),Color(),Wave() {

}

void LifeEvent_CWave::onInit() {
    LifeEvent_Collection::onInit();


    shouldCreateNewWave=true;
}


void LifeEvent_CWave::passTime(GLfloat delTime) {
    LifeEvent_Collection::passTime(delTime);

    if(shouldCreateNewWave){

        //create the new wave
        LifeEvent_CWave_data * data=new LifeEvent_CWave_data();
        data->init();
        data->setCenter(0.0f,0.0f);
        data->setFrequency(getFrequency());
        data->setWaveLength(getWavelength());
        data->setDepth(getDepth());

        data->setColor(this);

        //create a callback for next wave
        createTimeOut(getTimePeriod(),EMPATHY_LIFE_EVENT_CWAVE_CREATE_NEW_WAVE);

        addToCollection(data);

        shouldCreateNewWave=false;
    }

//    cout<<"size is"<<getCollection().size()<<endl;
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
