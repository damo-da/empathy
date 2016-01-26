//
// Created by damo on 1/26/16.
//

#include <iostream>
#include "TimeBroadcaster.h"
using namespace std;

void TimeBroadcaster::createRepeatingTimeout(Subscriber *subscriber, Event & event, GLfloat start,GLfloat period) {
    TimeBroadcasterObject object(event,start,subscriber,period);

    items.push_back(object);
}

void TimeBroadcaster::createTimeout(Subscriber *subscriber, Event & event, GLfloat start) {
    TimeBroadcasterObject object(event,start,subscriber);

    items.push_back(object);
}

void TimeBroadcaster::poll(GLfloat delTime){

    for(int i=0;i<items.size();i++){

        TimeBroadcasterObject & item=items[i];
        item.nextOccurance -= delTime;

        if(item.nextOccurance<=0){
            item.subscriber->onReceiveEvent(&item.event);

            if(!item.repeat){
                items.erase(items.begin()+i);

                i--;
                continue;
            }
            item.nextOccurance += item.period;
        }

    }
}



std::vector<TimeBroadcasterObject> TimeBroadcaster::items=std::vector<TimeBroadcasterObject>();
