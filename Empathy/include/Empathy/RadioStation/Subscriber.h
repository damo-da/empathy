//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_STATIONBASE_H
#define EMPATHY_STATIONBASE_H

#include "Event.h"
#include "../Utils/UniqueObject.h"
#include <vector>

#define EMPATHY_SUBSCRIBER_ID "EMPATHY_SUBSCRIBER_ID"

namespace empathy {
    namespace radio {
        class Event;

        /* The class to be overridden to emit/receive events.
         *
         * See <Event> to know more about events.
         *
         * */
        class Subscriber : public UniqueObject {

        public:
            /* Called when an event is received for this subscriber.*/
            virtual void onReceiveEvent(Event &);

            /* Emit an event in the system. */
            void emit(Event &);

            /* Create and emit an event of certain string. */
            void emit(std::string);

            /* Listen to a specific channel. */
            void listen(std::string);

            /* Listen to ALL channels, become a VIP subscriber. */
            void listenAll();

            /* Default constructor. */
            Subscriber();


            /* Create a timeout after  equivalent to setTimeout() of JavaScript,
             *
             * @after how many seconds.
             * @id of the output event. @deprecated
             * */
            void createTimeOut(GLfloat after, int id);


            /* Create a timeout after  equivalent to setTimeout() of JavaScript,
             *
             * @after how many seconds.
             * @event the event to be emitted
             * */
            void createTimeOut(GLfloat after, Event & event);

            /* Create a repeating timeout after  equivalent to setInterval() of JavaScript,
             *
             * @start how many seconds to start emitting.
             * @interval the timeperiod of emission
             * @id the id of the event to be emitted. @deprecated
             * */
            void createRepeatingTimeout(GLfloat start, GLfloat interval, int);

            /* Create a repeating timeout after  equivalent to setInterval() of JavaScript,
             *
             * Start immediately
             * @interval the timeperiod of emission
             * @id the id of the event to be emitted. @deprecated
             * */
            void createRepeatingTimeout(GLfloat interval, int);

            /* Create a repeating timeout after  equivalent to setInterval() of JavaScript,
             *
             * @start how many seconds to start emitting.
             * @interval the timeperiod of emission
             * @event the event to be emitted.
             * */
            void createRepeatingTimeout(GLfloat start, GLfloat interval, Event & event);

            /* Create a repeating timeout after  equivalent to setInterval() of JavaScript,
             *
             * start immediately
             * @interval the timeperiod of emission
             * @event the event to be emitted.
             * */
            void createRepeatingTimeout(GLfloat interval, Event & event);

            /* Emit an intent to play an audio.
             *
             * @key the identification of the audio.
             * */
            void playAudio(std::string key);

            /* Emit an intent to play a musical keyboard key
             *
             * @key the identification of the audio.
             *
             * */
            void playKeyboardAudio(std::string key);

        protected:
            /* Create an empty event. of empty action. */
            Event createEvent();

            /* Create an empty event.
             *
             * @action the action of the event.
             *
             * @return an empty event.
             * */
            Event createEvent(std::string action);
        };

    }
}

#endif //EMPATHY_STATIONBASE_H
