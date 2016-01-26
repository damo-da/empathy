//
// Created by damo on 1/26/16.
//

#ifndef EMPATHY_TIMEBROADCASTER_H
#define EMPATHY_TIMEBROADCASTER_H


#include <GL/glew.h>
#include "Subscriber.h"

#include <thread>
class TimeBroadcaster {
public:
    static void createRepeatingTimeout(Subscriber &,Event&,GLfloat);

    static void createTimeout(Subscriber &, Event&, GLfloat);
};


#endif //EMPATHY_TIMEBROADCASTER_H
