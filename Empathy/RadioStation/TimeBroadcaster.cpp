//
// Created by damo on 1/26/16.
//

#include <iostream>
#include "TimeBroadcaster.h"
using namespace std;


static void emCreateTimeout(int i){
//    std::cout<<"Creting timeout"<<std::endl;
}

void TimeBroadcaster::createRepeatingTimeout(Subscriber *subscriber, Event *event, GLfloat start,GLfloat period) {
    TimeBroadcasterObject object(event,start,subscriber,period);

    cout<<"action is a"<<event->action<<endl;
    cout<<"action is b"<<object.event->action<<endl;
    cout<<"location is "<<&(object.event->action)<<endl;
    int num=1;
    event->put("a",&num);

    items.push_back(object);
}

void TimeBroadcaster::createTimeout(Subscriber *subscriber, Event * event, GLfloat start) {
    TimeBroadcasterObject object(event,start,subscriber);

    items.push_back(object);
}

void TimeBroadcaster::poll(GLfloat delTime){
    for(int i=0;i<items.size();i++){

        TimeBroadcasterObject & item=items[i];
        item.nextOccurance -= delTime;

        if(item.nextOccurance<=0){
            Event &event=*item.event;

            item.subscriber->onReceiveEvent(item.event);
            cout<<item.repeat<<"is repeating"<<endl;
                items.erase(items.begin()+i);
                i--;
                continue;
            }

            item.nextOccurance += item.period;
        }
    }
}

std::vector<TimeBroadcasterObject> TimeBroadcaster::items=std::vector<TimeBroadcasterObject>();

