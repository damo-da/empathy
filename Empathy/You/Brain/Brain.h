//
// Created by damo on 2/4/16.
//

#ifndef EMPATHY_BRAIN_H
#define EMPATHY_BRAIN_H

#define EMPATHY_EVENT_BRAIN_LINE_NUMBER "EMPATHY_EVENT_BRAIN_LINE_NUMBER"
#define EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER "EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER"

#include "../../RadioStation/Subscriber.h"
#include "../../global.hpp"
#include "../../LifeEvent/life_event.hpp"

class Brain  : public Subscriber{
public:
    virtual void onReceiveEvent(Event &event) override;

    Brain();

    void run();
protected:
    virtual void runLineNumber(int number, int caller);

    void activateTimeoutForNextLine(int lineNumber,GLfloat afterTime);
    void activateTimeoutForNextLine(int lineNumber,GLfloat afterTime,int callerLineNumber);

    void addLifeEvent(LifeEvent * event);
private:

};


#endif //EMPATHY_BRAIN_H
