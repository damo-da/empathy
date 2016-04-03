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


namespace empathy {
    namespace radio {

        /* The class responsible for creating timeouts.
         *
         * Used only to `TimeBroadcaster::poll(delTime)` from gameloop.
         *
         * See <Subscriber> and <Event> for creating and receiving timeouts.
         *
         */
        class TimeBroadcaster {
        private:
            /* Register the items in the queue to the main list. */
            static void addItems();

        public:
            /* Create a repeating timeout, ie, createInterval() of JavaScript. */
            static void createRepeatingTimeout(Subscriber *, Event &, GLfloat, GLfloat);

            /* Create a repeating timeout, ie, createTimeout() of JavaScript. */
            static void createTimeout(Subscriber *, Event &, GLfloat);

            /* Poll the events.
             *
             * @delTime the time to pass on the events
             *
             * It passes @delTime to all the events in the queue.
             * If the time for any event is <0, an <onReceiveEvent> is triggered;
             * */
            static void poll(GLfloat delTime);


            /* The events queue. */
            static std::vector<TimeBroadcasterObject> items;

            /* Events ready to be added in the main queue. */
            static std::vector<TimeBroadcasterObject> toAddItems;
        };


    }
}

#endif //EMPATHY_TIMEBROADCASTER_H
