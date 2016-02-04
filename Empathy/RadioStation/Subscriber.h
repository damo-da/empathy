//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_STATIONBASE_H
#define EMPATHY_STATIONBASE_H

#include "Event.h"
#include <vector>

#define EMPATHY_SUBSCRIBER_ID "EMPATHY_SUBSCRIBER_ID"


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

    void createRepeatingTimeout(GLfloat,GLfloat,int);
    void createRepeatingTimeout(GLfloat,int);

    int getId(){return id;}
private:
    int id;


public:
    static Subscriber* getById(int id){
        for(int i=0;i<lifeEvents.size();i++){
            if(lifeEvents[i]->getId()==id){
                return lifeEvents[i];
            }
        }

        return nullptr;
    }
private:
    static std::vector <Subscriber*> lifeEvents;
};


#endif //EMPATHY_STATIONBASE_H
