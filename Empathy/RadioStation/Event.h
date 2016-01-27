//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_EVENT_H
#define EMPATHY_EVENT_H



#include <GL/glew.h>
#include <iostream>
#include <map>

class Event {
public:
    void putString(std::string key, std::string value) {
        strData[key]=value;

    }
    void putInt(std::string key,int value){

        intData[key]=value;
    }

    const int getInt(const std::string key){
        return intData[key];
    }

    const std::string getString(const std::string key){
        return strData[key];
    }

    Event(std::string);

    std::string action;
    std::string name;

    void * broadcaster;
private:
    std::map<std::string,int> intData;
    std::map<std::string,std::string> strData;
};


#endif //EMPATHY_EVENT_H
