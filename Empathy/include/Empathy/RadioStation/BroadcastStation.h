//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_BROADCAST_H
#define EMPATHY_BROADCAST_H

#include <vector>
#include <iostream>

#include <map>
#include "Subscriber.h"

namespace empathy {
    namespace radio {

        /* The class responsible for managing all events, including which subscriber it should be dispatched to,
         *
         * ALMOST never used by any class directly. To use event management, see <Subscriber> and <Event> instead.
         *
         */
        class BroadcastStation {
        public:
            /* Subscriber a subscriber to listen to a specific channel. */
            static void subscribe(Subscriber *base, std::string channel);

            /*Default constructor. */
            BroadcastStation();

            /* Add an event to the dispatch queue. */
            static void emit(Event &);

            /* Dispatch items from the dispatch queue.
             *
             * Called from the gameloop directly.
             * */
            static void dispatch();

            /* Subscribe a subscriber to all channels. */
            static void subscribeAll(Subscriber *subscriber);

        protected:
            /* `this`. */
            static BroadcastStation *instance;

        private:
            /* All singleton subscribers.
             * Structure: {"channel1":[Subscriber1,Subscriber2],"channel2":[Sub3,Sub4]}
             * */
            std::map<std::string, std::vector<Subscriber *>> channels;

            /* Subscriber that listen to ALL events in the system.
             *
             * Typically, all brains are VIP subscribers.
             * */
            std::vector<Subscriber *> vipSubscribers;

            /* The dispatch queue. */
            std::vector<Event> events;

            /* Check for the existence of a specific channel in the <channels> map. */
            bool existsChannel(std::string);

            /* Add channel in the <channels> map if not already exists. */
            void addChannel(std::string);


        };
    }
}

#endif //EMPATHY_BROADCAST_H
