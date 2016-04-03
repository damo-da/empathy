//
// Created by damo on 1/26/16.
//

#ifndef EMPATHY_TIMEBROADCASTEROBJECT_H
#define EMPATHY_TIMEBROADCASTEROBJECT_H



#include "Subscriber.h"
#include <GL/glew.h>

/* A single TimeBroadcaster item.
 *
 * */
class TimeBroadcasterObject {
private:

public:
    /* The subscriber: the one who listens to this timed event. */
    empathy::radio::Subscriber * subscriber;

    /* The event to be dispatched on trigger.*/
    empathy::radio::Event event;

    /* The period of a repeating trigger. */
    GLfloat period;

    /* Whether the trigger should repeat. */
    bool repeat;

    /* The next occurance of the trigger. */
    GLfloat nextOccurance;

    /* Constructor */
    TimeBroadcasterObject(empathy::radio::Event e,GLfloat nextOccurance,empathy::radio::Subscriber* s,GLfloat p=0.0f);

    /* Print the current state of this object. Useful for debugging purposes. */
    void printDebug();
};


#endif //EMPATHY_TIMEBROADCASTEROBJECT_H
