#include <iostream>
#include "you.h"
#include "../RadioStation/TimeBroadcaster.h"

using namespace std;

empathy::You::You():brains()
{
    instance=this;

}


void empathy::You::onReceiveEvent(empathy::radio::Event & event) {
    empathy::radio::Subscriber::onReceiveEvent(event);

}


int empathy::You::calcFPS(GLfloat curTime){

    deltaTime=curTime-lastTime;

    lastTime=curTime;

    int FPS=1/deltaTime;
//    cout<<"FPS "<<FPS<<endl;
    return FPS;
}

void empathy::You::passTime(GLfloat timeLength){
    curTime += timeLength;

//    cout<<"passing time"<<endl;
    for(int i=0;i<lifeEvents.size();i++){
        empathy::life_event::LifeEvent * event=lifeEvents[i];

        if(event->isDestroyed()){
            removeEvent(event);
            i--;
            continue;
        }

        event->passTime(timeLength);
    }
//    cout<<"passed time"<<endl;
    empathy::radio::TimeBroadcaster::poll(timeLength);
}

void empathy::You::setTime(GLfloat time){
    calcFPS(time);
    passTime(deltaTime);
}
void empathy::You::init(){
    //initiaulize vector to store lifeevents
    lifeEvents=std::vector<empathy::life_event::LifeEvent*>();

    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //initializing time
    curTime=0;

}

void empathy::You::addEvent(empathy::life_event::LifeEvent * e) {
    e->init();
    lifeEvents.push_back(e);
}
void empathy::You::removeEvent(empathy::life_event::LifeEvent * e) {

    for (int i = 0; i < lifeEvents.size(); i++) {
        if ( lifeEvents[i]->getId() == e->getId()) {

            lifeEvents.erase(lifeEvents.begin() + i);
//            delete(e);
            i--;
        }
    }
}

void empathy::You::clearEvents() {

    while(lifeEvents.size()>0){
        empathy::life_event::LifeEvent * event = lifeEvents[0];

        removeEvent(event);
    }
}

void empathy::You::blit(){

    // cout<<"blitting you"<<endl;

    for(int i=0;i<lifeEvents.size();i++){
        empathy::life_event::LifeEvent * event=lifeEvents[i];

        event->draw();
    }
}

empathy::You * empathy::You::instance=nullptr;

void empathy::You::addBrain(empathy::brain::Brain *brain) {
    brains.push_back(brain);
    brain->run();
}

void empathy::You::terminate() {
    clearEvents();

    for(int i=0;i<brains.size();i++){

        brains[i]->terminate();
    }
}
