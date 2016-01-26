//
// Created by damo on 1/26/16.
//

#ifndef EMPATHY_TIMEBROADCASTEROBJECT_H
#define EMPATHY_TIMEBROADCASTEROBJECT_H


#include <GL/glew.h>
#include "Subscriber.h"

class TimeBroadcasterObject {
private:

public:
    Subscriber * subscriber;
    Event * event;

    GLfloat period;

    bool repeat;

    GLfloat nextOccurance;

    TimeBroadcasterObject(Event*,GLfloat,Subscriber * );
    TimeBroadcasterObject(Event*,GLfloat,Subscriber*,GLfloat);
};


#endif //EMPATHY_TIMEBROADCASTEROBJECT_H
