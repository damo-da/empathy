//
// Created by damo on 1/26/16.
//

#ifndef EMPATHY_TIMEBROADCASTER_H
#define EMPATHY_TIMEBROADCASTER_H


#include <GL/glew.h>
#include "Subscriber.h"

#include <vector>
#include "TimeBroadcasterObject.h"
class TimeBroadcaster {
private:
    static std::vector<TimeBroadcasterObject> items;

public:
    static void createRepeatingTimeout(Subscriber *,Event*,GLfloat,GLfloat);

    static void createTimeout(Subscriber *, Event*, GLfloat);

    static void poll(GLfloat);
};




#endif //EMPATHY_TIMEBROADCASTER_H
