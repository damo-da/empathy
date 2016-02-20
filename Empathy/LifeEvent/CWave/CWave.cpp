//
// Created by damo on 2/5/16.
//

#include "CWave.h"
#include "CWave_data.h"
#include "../../RadioStation/TimeBroadcaster.h"

using namespace std;

empathy::life_event::CWave::CWave() : Collection(), Color(), Wave() {

}

void empathy::life_event::CWave::onInit() {
    Collection::onInit();

    shouldCreateNewWave=true;
}


void empathy::life_event::CWave::passTime(GLfloat delTime) {
    Collection::passTime(delTime);

    if(shouldCreateNewWave){

        //create the new wave
        empathy::life_event::CWave_data * data=new empathy::life_event::CWave_data();
        data->init();
        data->setCenter(0.0f,0.0f);
        data->setFrequency(getFrequency());
        data->setWaveLength(getWaveLength());
        data->setDepth(getDepth());

        data->setColor(this);

        //create a callback for next wave
        createTimeOut(getTimePeriod(),EMPATHY_LIFE_EVENT_CWAVE_CREATE_NEW_WAVE);

        addToCollection(data);

        shouldCreateNewWave=false;
    }

//    cout<<"size is"<<getCollection().size()<<endl;
}



void empathy::life_event::CWave::onReceiveEvent(Event &event) {
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

void empathy::life_event::CWave::decodeJson(std::string key, cJSON *value) {
    Collection::decodeJson(key, value);
    Color::decodeJson(key, value);
    Wave::decodeJson(key,value);

}
