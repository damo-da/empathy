//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_EVENT_H
#define EMPATHY_EVENT_H


#include <map>

class Event {
public:
    void put(std::string key, const void *value) {
        data[key]=&value;

    }

    const void *get(const std::string key) {
        return data[key];
    }

    bool existsKey(std::string key) {
        return data.find(key) != data.end();
    }

    Event(std::string);

    std::string action;
    std::string name;

    void * broadcaster;
private:
    std::map<std::string,void *> data;
};


#endif //EMPATHY_EVENT_H
