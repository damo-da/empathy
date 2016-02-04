//
// Created by damo on 2/4/16.
//

#include "Brain.h"
#include "../../LifeEvent/Wave/wave.hpp"

void Brain::onReceiveEvent(Event &event) {
    Subscriber::onReceiveEvent(event);


}

void Brain::begin() {
    std::cout<<"Brain began"<<std::endl;

    instance=new Brain();
    instance->mainloop();
}

void Brain::mainloop() {
    emit(EMPATHY_CREATE_EVENT);

    //add a base wave
    LifeEvent_Wave * wave=new LifeEvent_Wave(0.0f,0.0f);
    wave->setColor(0.0f,1.0f,0.0f,0.5f);//green
    wave->setCenter(0.0f,0.0f);
    wave->setDepth(0.0f);
    wave->setFrequency(0.4f);

    addLifeEvent(wave);

    //add a secondary wave
//	LifeEvent_Wave * sWave=new LifeEvent_Wave(0.2f,0.2f);
//	sWave->setColor(1.0f,0.0f,1.0f,0.5f);//pink
//    sWave->setCenter(0.2f,0.2f);
//    sWave->setDepth(0.1f);
//
//    addEvent(sWave);

//    MathWave_Sine* sineWave=new MathWave_Sine(0.1f);
//    sineWave->setZoomY(0.1f);
//    sineWave->setPencilSize(2.0f);
//    sineWave->setHead(-0.7f);
//    sineWave->setTail(0.0f);
//    sineWave->setPeriod(0.1f);
//    sineWave->setSpeed(0.3f);
//    sineWave->setLength(0.5f);
//    sineWave->setDepth(1.0f);
//    addEvent(sineWave);
//
//    MathWave_Line* line=new MathWave_Line();
//    line->setOffsetY(0.3f);
//    line->setDepth(0.1f);
//    addEvent(line);
//    MathWave_Sinc* sincWave=new MathWave_Sinc();
//    sincWave->setZoomY(0.7f);
//    sincWave->setOffsetY(-0.2f);
//    sincWave->setRotationAngle(M_PI_2);
//    sincWave->setSpeed(0.3f);
//    sincWave->setHead(-1.0f);
//    sincWave->setLength(1.0f);
//    sincWave->setPencilSize(2.0f);
//    addEvent(sincWave);


}

Brain * Brain::instance= nullptr;