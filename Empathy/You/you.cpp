#include <iostream>
#include "you.hpp"
#include "../LifeEvent/Wave/wave.hpp"
#include "../RadioStation/TimeBroadcaster.h"
//#include "../LifeEvent/SineWave/LifeEvent_SineWave.h"
#include "../LifeEvent/MathWave/MathWave_Sine.h"
#include "../LifeEvent/MathWave/MathWave_Sinc.h"
#include "../Shader.h"
#include "../LifeEvent/MathWave/MathWave_Line.h"


using namespace std;

You::You(){

}


void You::onReceiveEvent(Event & event) {
    Subscriber::onReceiveEvent(event);

    if(event.action==EMPATHY_EVENT_INPUT_KEY_PRESS){
        cout<<"key press listened!"<<endl;
    }
}


int You::calcFPS(GLfloat curTime){

    deltaTime=curTime-lastTime;

    lastTime=curTime;

    int FPS=1/deltaTime;
//    cout<<"FPS "<<FPS<<endl;
    return FPS;
}

void You::passTime(GLfloat timeLength){
    curTime += timeLength;

    for(int i=0;i<lifeEvents->size();i++){
        LifeEvent * event=(*lifeEvents)[i];

        if(event->isDestroyed()){
            removeEvent(event);
            i--;
            continue;
        }


        event->passTime(timeLength);
    }
    TimeBroadcaster::poll(timeLength);
}

void You::setTime(GLfloat time){
    calcFPS(time);
    passTime(deltaTime);
}
void You::init(){
    //initiaulize vector to store lifeevents
    lifeEvents=new std::vector<LifeEvent*>();

    //add a base wave
    LifeEvent_Wave * wave=new LifeEvent_Wave(0.0f,0.0f);
    wave->setColor(0.0f,1.0f,0.0f,0.5f);//green
    wave->setCenter(0.0f,0.0f);
    wave->setDepth(0.0f);
    

    addEvent(wave);

	//add a secondary wave
	LifeEvent_Wave * sWave=new LifeEvent_Wave(0.2f,0.2f);
	sWave->setColor(1.0f,0.0f,1.0f,0.5f);//pink
    sWave->setCenter(0.2f,0.2f);
    sWave->setDepth(0.1f);

    addEvent(sWave);

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



    //initializing time
    curTime=0;

    listen(EMPATHY_EVENT_INPUT_KEY_PRESS);
    listen(EMPATHY_EVENT_INPUT_KEY_RELEASE);
    listen(EMPATHY_EVENT_INPUT_KEY_REPEAT);
}

void You::addEvent(LifeEvent * e) {
    lifeEvents->push_back(e);
}
void You::removeEvent(LifeEvent * e) {

    for (int i = 0; i < lifeEvents->size(); i++) {
        if ( (*lifeEvents)[i]->getId() == e->getId()) {

            lifeEvents->erase(lifeEvents->begin() + i);
//            delete(e);
            i--;
        }
    }
}

void You::clearEvents() {

    while(lifeEvents->size()>0){
        LifeEvent * event = (*lifeEvents)[0];

        removeEvent(event);
    }
}

void You::blit(){

    // cout<<"blitting you"<<endl;

    for(int i=0;i<lifeEvents->size();i++){
        LifeEvent * event=(*lifeEvents)[i];

        event->draw();
    }
}