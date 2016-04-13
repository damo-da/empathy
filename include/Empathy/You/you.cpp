#include <iostream>
#include "you.h"

#include "../LifeEvent/LifeEvent.h"
#include "../Brain/Brain.h"
#include "../RadioStation/TimeBroadcaster.h"

using namespace std;

empathy::You::You():brains(),background()
{
    instance=this;
    background= new life_event::Background();
}



int empathy::You::calcFPS(GLfloat curTime){

    deltaTime=curTime-lastTime;

    lastTime=curTime;

    int FPS=(int)(1.0f/deltaTime);
//    cout<<"FPS "<<FPS<<endl;
    return FPS;
}

void empathy::You::passTime(GLfloat timeLength){

    for(int i=0;i<lifeEvents.size();i++){
        empathy::life_event::LifeEvent * event=lifeEvents[i];

        if(event->isDestroyed()){

            removeLifeEvent(event);
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

    addLifeEvent(background);
}

void empathy::You::addLifeEvent(empathy::life_event::LifeEvent *e) {
    e->init();
    lifeEvents.push_back(e);
}
void empathy::You::removeLifeEvent(empathy::life_event::LifeEvent *e) {
    for (int i = 0; i < lifeEvents.size(); i++) {
        if (e->getId() == lifeEvents[i]->getId()) {

            lifeEvents.erase(lifeEvents.begin() + i);
//            delete(e);
            i--;
        }
    }
}

void empathy::You::clearLifeEvents() {
    while(lifeEvents.size()>0){
        empathy::life_event::LifeEvent * event = lifeEvents[0];

        removeLifeEvent(event);
    }
}

void empathy::You::blit(){
//    cout<<"BLITTING"<<endl;
    for(int i=0;i<lifeEvents.size();i++){
//        cout<<"Lower"<<endl;
        empathy::life_event::LifeEvent * event=lifeEvents[i];
//        cout<<"RENDERING"<<endl;
        if(event== nullptr){
            cout<<"FOUND A null event";
            continue;
        }
//        cout<<"EVENT ID IS "<< event->getId()<<endl;

        if(event->isCreating() || event->isRunning() || event->isFinishing())
            event->draw();
//        cout<<"RENDERED"<<endl;
    }
//    cout<<"BLITTED"<<endl;
}

empathy::You * empathy::You::instance=nullptr;

void empathy::You::addBrain(empathy::brain::Brain *brain) {
    brains.push_back(brain);
    brain->run();
}

void empathy::You::terminate() {
    clearLifeEvents();

    for(int i=0;i<brains.size();i++){

        brains[i]->terminate();
    }
}
