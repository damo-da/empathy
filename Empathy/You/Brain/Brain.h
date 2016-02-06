//
// Created by damo on 2/4/16.
//

#ifndef EMPATHY_BRAIN_H
#define EMPATHY_BRAIN_H


#include "../../RadioStation/Subscriber.h"
#include "../../global.hpp"
#include "../../LifeEvent/life_event.hpp"

class Brain  : public Subscriber{
public:
    virtual void onReceiveEvent(Event &event) override;

    Brain();

    void run();

    virtual void runLineNumber(int number, int caller);
private:

    void addLifeEvent(LifeEvent * event);
};


#endif //EMPATHY_BRAIN_H
