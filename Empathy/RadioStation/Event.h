//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_EVENT_H
#define EMPATHY_EVENT_H

#include <iostream>
#include <map>

class Event {
public:
    const static int LIFE_EVENT_WAVE_COMPLETE=1;
public:
    void put(std::string key, const void *value) {
        int a=1;
        data[key]=&a;

    }

    const void *get(const std::string key) {
        return data[key];
    }

    bool existsKey(std::string key) {
        return data.find("world") != data.end();
    }

    Event(std::string ,int);

    int action;

private:
    std::map<std::string,void *> data;
    std::string name;
};


#endif //EMPATHY_EVENT_H
