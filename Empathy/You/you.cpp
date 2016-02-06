#include <iostream>
#include "you.hpp"
#include "../RadioStation/TimeBroadcaster.h"
//#include "../LifeEvent/SineWave/LifeEvent_SineWave.h"
#include "../LifeEvent/MathWave/MathWave_Sine.h"
#include "../LifeEvent/MathWave/MathWave_Sinc.h"
#include "../Shader.h"
#include "../LifeEvent/MathWave/MathWave_Line.h"
#include "Brain/Brain.h"


using namespace std;

You::You(){
    instance=this;
}


void You::onReceiveEvent(Event & event) {
    Subscriber::onReceiveEvent(event);

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

    for(int i=0;i<lifeEvents.size();i++){
        LifeEvent * event=lifeEvents[i];

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
    lifeEvents=std::vector<LifeEvent*>();

    brain=new Brain();

    brain->run();

    //initializing time
    curTime=0;

    listen(EMPATHY_CREATE_EVENT);
}

void You::addEvent(LifeEvent * e) {
    e->init();
    lifeEvents.push_back(e);
}
void You::removeEvent(LifeEvent * e) {

    for (int i = 0; i < lifeEvents.size(); i++) {
        if ( lifeEvents[i]->getId() == e->getId()) {

            lifeEvents.erase(lifeEvents.begin() + i);
//            delete(e);
            i--;
        }
    }
}

void You::clearEvents() {

    while(lifeEvents.size()>0){
        LifeEvent * event = lifeEvents[0];

        removeEvent(event);
    }
}

void You::blit(){

    // cout<<"blitting you"<<endl;

    for(int i=0;i<lifeEvents.size();i++){
        LifeEvent * event=lifeEvents[i];

        event->draw();
    }
}

You * You::instance=nullptr;