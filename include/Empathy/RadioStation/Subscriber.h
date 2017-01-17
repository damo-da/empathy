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

            void emitToIdentifier(Event e, std::string identifier);

            /*
             * Apply json as passed from JSONBrain
             * */
            virtual void decodeJson(std::string key, cJSON* value);

            /* An Action that when triggered, affects a LifeEvent.
             * */
            struct Action {
                std::string on;
                std::string id;
                std::string action;

                static Action create(std::string trigger, std::string action, std::string applyTo) {
                    return Action{trigger, applyTo, action};

                }
            };

            /* The identifier for this life event usually passed from JSON.
                 *
                 * Not to be confused with the `getId()` method.
                 * */
            std::string getIdentifier();

        protected:
            /* Create an empty event. of empty action.
             * */
            Event createEvent();

            /* Create an empty event.
             *
             * @action the action of the event.
             *
             * @return an empty event.
             * */
            Event createEvent(std::string action);

            /* Dispatches event to subscriber if condition from `actions` is matched
             *
             * @id the name of the subscriber to which the event will be dispatched
             *
             * @event_action the Event::action
             */
            void dispatchEventToActions(std::string event_action, Event event);
            void dispatchEventToActions(std::string event_action);

        public:
            /* The identifier for this life event usually passed from JSON.
                 * */
            void setIdentifier(std::string newId);

        private:
            /* The identifier for this life event usually passed from JSON.
            *
            * Not to be confused with the Subscriber ID.
            * */
            std::string identifier;

            /* contains all the triggers passed on the "triggers" key of JSON.
             *
             * These may also contain "direct calbacks" which refer to passing events without onReceiveEvents()
             * */
            std::vector<Action> actions;
        public:
            /* Add an action to match the respective requirement
             *
             * the @subscriber will get an event with action @callbackActionName when @event occurs in this instance.
             * */
            void addAction(Subscriber* subscriber, std::string event, std::string callbackActionName){
                addAction(subscriber->getIdentifier(), event, callbackActionName);
            }
            void addAction(std::string subscriber_identifier, std::string event, std::string callbackActionName){
                Subscriber::actions.push_back(Action::create(event, callbackActionName, subscriber_identifier));
            }
        };

    }
}

#endif //EMPATHY_STATIONBASE_H
