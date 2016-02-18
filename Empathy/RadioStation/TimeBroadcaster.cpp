//
// Created by damo on 1/26/16.
//

#include <iostream>
#include "TimeBroadcaster.h"

using namespace std;

void TimeBroadcaster::createRepeatingTimeout(Subscriber *subscriber, Event & event, GLfloat start,GLfloat period) {
    TimeBroadcasterObject object(event,start,subscriber,period);

    toAddItems.push_back(object);
}

void TimeBroadcaster::createTimeout(Subscriber *subscriber, Event & event, GLfloat start) {
    TimeBroadcasterObject object(event,start,subscriber);

    toAddItems.push_back(object);
}

void TimeBroadcaster::poll(GLfloat delTime){
    addItems();

    for(int i=0;i<items.size();i++){
        TimeBroadcasterObject & item=items[i];
        item.nextOccurance -= delTime;

        if(item.nextOccurance<=0){
            item.subscriber->onReceiveEvent(item.event);

            if(!item.repeat){

                items.erase(items.begin()+i);
                i--;

                continue;
            }else{
                item.nextOccurance += item.period;
            }
        }

    }
}



std::vector<TimeBroadcasterObject> TimeBroadcaster::items=std::vector<TimeBroadcasterObject>();
std::vector<TimeBroadcasterObject> TimeBroadcaster::toAddItems=std::vector<TimeBroadcasterObject>();

void TimeBroadcaster::addItems() {
    for(int i=0;i<toAddItems.size();i++){
        items.push_back(toAddItems[i]);
    }
    toAddItems.clear();
}
