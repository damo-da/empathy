//
// Created by damo on 1/26/16.
//

#ifndef EMPATHY_TIMEBROADCASTEROBJECT_H
#define EMPATHY_TIMEBROADCASTEROBJECT_H



#include "Subscriber.h"
#include <GL/glew.h>

class TimeBroadcasterObject {
private:

public:
    empathy::radio::Subscriber * subscriber;
    empathy::radio::Event event;

    GLfloat period;

    bool repeat;

    GLfloat nextOccurance;

    TimeBroadcasterObject(empathy::radio::Event,GLfloat,empathy::radio::Subscriber * );
    TimeBroadcasterObject(empathy::radio::Event,GLfloat,empathy::radio::Subscriber*,GLfloat);

    void printDebug();
};


#endif //EMPATHY_TIMEBROADCASTEROBJECT_H
