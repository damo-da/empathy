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
#include "../../Implements/EmpathyBinder.h"

class EmpathyBinder;
class Brain  : public Subscriber{
public:
    virtual void onReceiveEvent(Event &event) override;

    Brain();

    void run();


    GLfloat getDelay() const {
        return delay;
    }

    void setDelay(GLfloat delay) {
        Brain::delay = delay;
    }

    virtual void addTo(EmpathyBinder * binder);

    virtual void terminate();
protected:
    GLfloat delay;

    virtual void runLineNumber(std::string lineID, std::string callerID)=0;

    void activateTimeoutForNextLine(std::string lineID,GLfloat afterTime);
    void activateTimeoutForNextLine(std::string lineID,GLfloat afterTime,std::string callerLineID);

    void addLifeEvent(LifeEvent * event);
private:

};


#endif //EMPATHY_BRAIN_H
