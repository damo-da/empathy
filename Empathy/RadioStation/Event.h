//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_EVENT_H
#define EMPATHY_EVENT_H

#include <iostream>
#include <map>

class Event {
public:
    static std::string LIFE_EVENT_WAVE_COMPLETE;
    static std::string INPUT_KEY_PRESS;
    static std::string INPUT_KEY_RELEASE;

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

private:
    std::map<std::string,void *> data;
};


#endif //EMPATHY_EVENT_H
