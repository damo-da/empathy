#ifndef EMPATHY_EVENT_H
#define EMPATHY_EVENT_H

#include <GL/glew.h>
#include <iostream>
#include <map>
#include <Empathy/Libs/cJSON/cJSON.h>
#include "Subscriber.h"
#include "../Libs/cJSON/cJSON.h"

#define EMPATHY_EVENT_ACTION_NONE "EMPATHY_EVENT_ACTION_NONE"


namespace empathy {
    namespace radio {
        class Subscriber;

        class Event {
        public:
            void putString(std::string key, std::string value) {
                strData[key] = value;

            }

            void putInt(std::string key, int value) {

                intData[key] = value;
            }

            const int getInt(const std::string key) {
                return intData[key];
            }

            const std::string getString(const std::string key) {
                return strData[key];
            }

            void putDouble(std::string key,GLdouble value){
                doubleData[key]=value;
            }
            GLdouble getDouble(const std::string key){
                return doubleData[key];
            }

            void putJson(std::string key,cJSON* json){
                jsonData[key]=json;
            }
            cJSON* getJson(const std::string key){
                return jsonData[key];
            }

            Event(std::string);

            std::string action;

            Subscriber *broadcaster;

            friend std::ostream& operator<<(std::ostream& os, const Event& event){
                os << "Event::" << event.action;

            }
        private:
            std::map<std::string, int> intData;
            std::map<std::string, std::string> strData;
            std::map<std::string, GLdouble > doubleData;
            std::map<std::string, cJSON *> jsonData;
        };

    }
}
#endif //EMPATHY_EVENT_H
