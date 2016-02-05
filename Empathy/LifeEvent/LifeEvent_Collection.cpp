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
    LifeEvent::onDestroy();

    for(int i=0;i<collection.size();i++){
        collection[i]->onDestroy();
    }
}

void LifeEvent_Collection::draw() {
    for(int i=0;i<collection.size();i++){
        collection[i]->draw();
    }
}

void LifeEvent_Collection::removeFromCollection(LifeEvent *event) {
    for (int i = 0; i < collection.size(); i++) {
        if ( collection[i]->getId() == event->getId()) {

            collection.erase(collection.begin() + i);
            i--;
        }
    }
}

void LifeEvent_Collection::addToCollection(LifeEvent *event) {
    collection.push_back(event);
}

void LifeEvent_Collection::clearCollection() {
    collection.clear();
}

void LifeEvent_Collection::passTime(GLfloat delTime) {
    for(int i=0;i<collection.size();i++){

        if(! collection[i]->isDestroyed())
            collection[i]->passTime(delTime);
    }
}
