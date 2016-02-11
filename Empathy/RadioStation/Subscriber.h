//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_STATIONBASE_H
#define EMPATHY_STATIONBASE_H

#include "Event.h"
#include <vector>

#define EMPATHY_SUBSCRIBER_ID "EMPATHY_SUBSCRIBER_ID"

class Event;

//The class to be overridden to emit/receive broadcasts
class Subscriber {
public:
    virtual void onReceiveEvent(Event &);

    void emit(Event&);
    void emit(std::string);

    void listen(std::string);
    void listenAll();

    Subscriber();

    void createTimeOut(GLfloat interval,int);
    void createTimeOut(GLfloat interval,Event&);

    void createRepeatingTimeout(GLfloat start,GLfloat interval,int);
    void createRepeatingTimeout(GLfloat interval,int);
    void createRepeatingTimeout(GLfloat start,GLfloat interval,Event&);
    void createRepeatingTimeout(GLfloat interval,Event&);

    int getId(){return id;}

    void playAudio(std::string key);
    void playKeyboardAudio(std::string key);

private:
    int id;


public:
    static Subscriber* getById(int id){
        for(int i=0;i<subscribers.size();i++){
            if(subscribers[i]->getId()==id){
                return subscribers[i];
            }
        }

        return nullptr;
    }
private:
    static std::vector <Subscriber*> subscribers;

protected:
    Event createEvent();
    Event createEvent(std::string action);
};


#endif //EMPATHY_STATIONBASE_H
