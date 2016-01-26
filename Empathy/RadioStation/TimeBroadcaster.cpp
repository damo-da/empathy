//
// Created by damo on 1/26/16.
//

#include "TimeBroadcaster.h"


static void emCreateTimeout(Event event,GLfloat duration){
    std::cout<<"Creting timeout"<<std::endl;
}

void TimeBroadcaster::createRepeatingTimeout(Subscriber &subscriber, Event &event, GLfloat duration) {

}

void TimeBroadcaster::createTimeout(Subscriber &subscriber, Event & event, GLfloat duration) {
//    std::thread timeout(emCreateTimeout,&subscriber,&event);
}
