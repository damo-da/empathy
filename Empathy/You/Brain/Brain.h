//
// Created by damo on 2/4/16.
//

#ifndef EMPATHY_BRAIN_H
#define EMPATHY_BRAIN_H


#include "../../RadioStation/Subscriber.h"
#include "../../global.hpp"
#include "../../LifeEvent/life_event.hpp"
#include "../you.hpp"

class Brain  : public Subscriber{
public:
    virtual void onReceiveEvent(Event &event) override;

    static void begin();
private:
    void mainloop();

    void addLifeEvent(LifeEvent * event){
        You::getInstance()->addEvent(event);
    }

    static Brain * instance;
};


#endif //EMPATHY_BRAIN_H
