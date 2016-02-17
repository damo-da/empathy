//
// Created by damo on 1/26/16.
//

#include <iostream>
#include "TimeBroadcasterObject.h"
using namespace std;

TimeBroadcasterObject::TimeBroadcasterObject(Event event, GLfloat nextOccurance, Subscriber *subscriber):
        event(event),
        nextOccurance(nextOccurance),
        subscriber(subscriber),
        repeat(false),
        period(0.0f)
{

}



TimeBroadcasterObject::TimeBroadcasterObject(Event event, GLfloat nextOccurance, Subscriber *subscriber, GLfloat period) :
        event(event),
        nextOccurance(nextOccurance),
        subscriber(subscriber),
        period(period),
        repeat(true)
{

}

void TimeBroadcasterObject::printDebug() {
    cout<<"---printdebug--"<<endl;
    cout<<"object: TimeBroadcasterObject"<<endl;
    cout<<"event "<<event.action<<endl;
    cout<<"nextOccurance "<<nextOccurance<<endl;
    cout<<"subscriber "<<subscriber<<endl;
    cout<<" repeating "<<repeat<<endl;
    cout<<" period "<<period<<endl;
    cout<<"--endprintdebug--"<<endl;
}
