//
// Created by damo on 2/4/16.
//

#include "Brain.h"

#include "../../LifeEvent/MathWave/MathWave_Sine.h"
#include "../../LifeEvent/MathWave/MathWave_Line.h"
#include "../../LifeEvent/MathWave/MathWave_Sinc.h"
#include "../../LifeEvent/CWave/LifeEvent_CWave_data.h"
#include "../../LifeEvent/CWave/LifeEvent_CWave.h"
#include <iostream>
using namespace std;
void Brain::onReceiveEvent(Event &event) {
    Subscriber::onReceiveEvent(event);

//    cout<<"received "<<event.action<<" from "<<event.broadcaster->getId()<<endl;
}

void Brain::begin() {
    std::cout<<"Brain began"<<std::endl;

    instance=new Brain();
    instance->mainloop();
}

void Brain::mainloop() {
    emit(EMPATHY_CREATE_EVENT);

    //add a base wave
//    LifeEvent_Wave * wave=new LifeEvent_Wave(0.0f,0.0f);
//    addLifeEvent(wave);
//    wave->setColor(0.0f,1.0f,0.0f,0.5f);//green
//    wave->setCenter(0.0f,0.0f);
//    wave->setDepth(0.0f);
//    wave->setFrequency(0.4f);

//    LifeEvent_CWave_data * waveData=new LifeEvent_CWave_data(0.0f,0.0f);
//    addLifeEvent(waveData);
//
    LifeEvent_CWave * wave=new LifeEvent_CWave();
    addLifeEvent(wave);
    wave->setCenter(0.0f,0.0f);
    wave->setColor(1.0f,0.1f,1.0f);
    wave->setFrequency(1.0f);
//    wave->setWaveLength(0.1f);
//
//
//
//    //add a secondary wave
//	LifeEvent_Wave * sWave=new LifeEvent_Wave(0.2f,0.2f);
//    addLifeEvent(sWave);
//	sWave->setColor(1.0f,0.0f,1.0f,0.5f);//pink
//    sWave->setCenter(0.2f,0.2f);
//    sWave->setDepth(0.1f);
//
//
//
//    MathWave_Sine* sineWave=new MathWave_Sine(0.1f);
//    addLifeEvent(sineWave);
//    sineWave->setZoomY(0.1f);
//    sineWave->setPencilSize(2.0f);
//    sineWave->setHead(-0.7f);
//    sineWave->setTail(0.0f);
//    sineWave->setPeriod(0.1f);
//    sineWave->setSpeed(0.3f);
//    sineWave->setLength(0.5f);
//    sineWave->setDepth(1.0f);
//
//    MathWave_Line* line=new MathWave_Line();
//    addLifeEvent(line);
//    line->setOffsetY(0.3f);
//    line->setDepth(0.1f);
//
//
//    MathWave_Sinc* sincWave=new MathWave_Sinc();
//    addLifeEvent(sincWave);
//    sincWave->setZoomY(0.7f);
//    sincWave->setOffsetY(-0.2f);
//    sincWave->setRotationAngle(M_PI_2);
//    sincWave->setSpeed(0.3f);
//    sincWave->setHead(-1.0f);
//    sincWave->setLength(1.0f);
//    sincWave->setPencilSize(2.0f);

}

Brain * Brain::instance= nullptr;

Brain::Brain() {
    listenAll();
}
