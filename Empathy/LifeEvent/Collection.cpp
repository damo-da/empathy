//
// Created by damo on 2/5/16.
//

#include <assert.h>
#include "Collection.h"

empathy::life_event::Collection::Collection()
        : LifeEvent(),
          collection()
{

}

void empathy::life_event::Collection::onInit() {
    LifeEvent::onInit();

    for(int i=0;i<collection.size();i++){
        collection[i]->onInit();
    }
}

void empathy::life_event::Collection::onDestroy() {
    LifeEvent::onDestroy();

    for(int i=0;i<collection.size();i++){
        collection[i]->onDestroy();
    }
}

void empathy::life_event::Collection::draw() {
    for(int i=0;i<collection.size();i++){
        if(! collection[i]->isDestroyed())
            collection[i]->draw();
    }
}

void empathy::life_event::Collection::removeFromCollection(LifeEvent *event) {
    for (int i = 0; i < collection.size(); i++) {
        if ( collection[i]->getId() == event->getId()) {

            collection.erase(collection.begin() + i);
            i--;
        }
    }
}

void empathy::life_event::Collection::addToCollection(LifeEvent *event) {
    collection.push_back(event);
}

void empathy::life_event::Collection::clearCollection() {
    collection.clear();
}

void empathy::life_event::Collection::passTime(GLfloat delTime) {
    for(int i=0;i<collection.size();i++){

        if(! collection[i]->isDestroyed())
            collection[i]->passTime(delTime);
        else{
            removeFromCollection(collection[i]);
            i--;
        }
    }
}

void empathy::life_event::Collection::removeCompletedFromCollection() {

}

void empathy::life_event::Collection::decodeJson(std::string key, cJSON *value) {
    LifeEvent::decodeJson(key, value);

    for(int i=0;i<getCollection().size();i++){
        collection[i]->decodeJson(key,value);
    }
}
