//
// Created by damo on 2/5/16.
//

#include "LifeEvent_Collection.h"

LifeEvent_Collection::LifeEvent_Collection()
        : LifeEvent(),
          collection()
{

}

void LifeEvent_Collection::onInit() {
    LifeEvent::onInit();

    for(int i=0;i<collection.size();i++){
        collection[i]->onInit();
    }
}

void LifeEvent_Collection::onDestroy() {
    for(int i=0;i<collection.size();i++){
        collection[i]->onDestroy();
    }
}

void LifeEvent_Collection::draw() {
    for(int i=0;i<collection.size();i++){
        collection[i]->draw();
    }
}

void LifeEvent_Collection::onCreate(GLfloat delTime) {
    LifeEvent::onCreate(delTime);

    bool atLeastOneIsCreating =false;

    for(int i=0;i<collection.size();i++){
        if(collection[i]->isCreating()){
            atLeastOneIsCreating =true;
            collection[i]->onCreate(delTime);
        }
    }

    if(!atLeastOneIsCreating)doneCreating();

}

void LifeEvent_Collection::onRun(GLfloat delTime) {
    bool atLeastOneIsRunning=false;

    for(int i=0;i<collection.size();i++){

        if(collection[i]->isRunning()){
            atLeastOneIsRunning=true;
            collection[i]->onRun(delTime);
        }
    }

    if(! atLeastOneIsRunning)doneRunning();
}


void LifeEvent_Collection::onFinish(GLfloat delTime) {
    LifeEvent::onFinish(delTime);

    bool atLeastOneIsFinishing =false;

    for(int i=0;i<collection.size();i++){
        if(collection[i]->isFinishing()){
            atLeastOneIsFinishing =true;
            collection[i]->onFinish(delTime);
        }
    }

    if(!atLeastOneIsFinishing)doneFinishing();
}
