//
// Created by damo on 1/26/16.
//

#ifndef EMPATHY_TIMEBROADCASTER_H
#define EMPATHY_TIMEBROADCASTER_H


#include <GL/glew.h>
#include "Subscriber.h"

#include <vector>
#include "TimeBroadcasterObject.h"

#define EMPATHY_EVENT_TIMEOUT "EMPATHY_EVENT_TIMEOUT"
#define EMPATHY_EVENT_REPEAT_TIMEOUT "EMPATHY_EVENT_REPEAT_TIMEOUT"


class TimeBroadcaster {

public:
    static void createRepeatingTimeout(Subscriber *,Event&,GLfloat,GLfloat);

    static void createTimeout(Subscriber *, Event&, GLfloat);

    static void poll(GLfloat);

    static std::vector<TimeBroadcasterObject> items;
};




#endif //EMPATHY_TIMEBROADCASTER_H
