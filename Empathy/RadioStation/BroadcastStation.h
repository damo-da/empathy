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

        class BroadcastStation {
        public:
            //subscribes  a subscriber.
            static void subscribe(Subscriber *base, std::string id);

            BroadcastStation();

            //emit an event to the whole world
            static void emit(Event &);

            static void dispatch();

            static void subscribeAll(Subscriber *subscriber);

        protected:
            static BroadcastStation *instance;

        private:
            std::map<std::string, std::vector<Subscriber *>> channels;

            std::vector<Event> events;

            bool existsChannel(std::string);

            void addChannel(std::string);

            std::vector<Subscriber *> vipSubscribers;
        };
    }
}

#endif //EMPATHY_BROADCAST_H
