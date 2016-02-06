//
// Created by damo on 2/4/16.
//

#include "Brain.h"

#include "../../LifeEvent/MathWave/MathWave_Sine.h"
#include "../../LifeEvent/MathWave/MathWave_Line.h"
#include "../../LifeEvent/MathWave/MathWave_Sinc.h"
#include "../../LifeEvent/CWave/LifeEvent_CWave_data.h"
#include "../../LifeEvent/CWave/LifeEvent_CWave.h"
#include "../you.hpp"

using namespace std;
void Brain::onReceiveEvent(Event &event) {
    Subscriber::onReceiveEvent(event);

    if(event.broadcaster->getId()==getId()){
        if(event.action==EMPATHY_EVENT_BRAIN_LINE_NUMBER){
            int lineNumber=event.getInt(EMPATHY_EVENT_BRAIN_LINE_NUMBER);
            int caller=event.getInt(EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER);

            cout<<"action received"<<endl;
            runLineNumber(lineNumber,caller);
        }
    }
}

Brain::Brain() {

}

void Brain::addLifeEvent(LifeEvent *event) {

    You::getInstance()->addEvent(event);

}

void Brain::run() {
    listenAll();
    activateTimeoutForNextLine(1,0.0f);


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

void Brain::runLineNumber(int number, int caller) {
    switch (number){
        case 1:
        {
            LifeEvent_CWave_data * wave=new LifeEvent_CWave_data();
            addLifeEvent(wave);
            wave->setCenter(0.0f,0.0f);
            wave->setColor(1.0f,0.1f,1.0f);
            wave->setFrequency(2.0f);

            activateTimeoutForNextLine(2,5.0f);
            break;
        }
        case 2:
        {
            MathWave_Sine* sineWave=new MathWave_Sine(0.1f);
            addLifeEvent(sineWave);
            sineWave->setZoomY(0.1f);
            sineWave->setPencilSize(2.0f);
            sineWave->setHead(-0.7f);
            sineWave->setTail(0.0f);
            sineWave->setPeriod(0.1f);
            sineWave->setSpeed(0.3f);
            sineWave->setLength(0.5f);
            sineWave->setDepth(1.0f);


            break;
        }

        default:
            break;
    }
}

void Brain::activateTimeoutForNextLine(int lineNumber, GLfloat afterTime) {
    activateTimeoutForNextLine(lineNumber,afterTime,-1);
}

void Brain::activateTimeoutForNextLine(int lineNumber, GLfloat afterTime, int callerLineNumber) {
    Event event=createEvent(EMPATHY_EVENT_BRAIN_LINE_NUMBER);
    event.putInt(EMPATHY_EVENT_BRAIN_LINE_NUMBER,lineNumber);
    event.putInt(EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER,callerLineNumber);

    createTimeOut(afterTime,event);
}
