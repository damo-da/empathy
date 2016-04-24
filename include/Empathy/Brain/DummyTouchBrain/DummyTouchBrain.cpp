//
// Created by damo on 2/24/16.
//

#include "DummyTouchBrain.h"
#include "../../LifeEvent/CWave/CWave_data.h"
#include "../../Empathy/Empathy.h"
using namespace std;

void empathy::brain::DummyTouchBrain::runLineNumber(std::string lineID, std::string callerID,cJSON * override) {

}

void empathy::brain::DummyTouchBrain::onReceiveEvent(empathy::radio::Event &event) {
    Brain::onReceiveEvent(event);

    static int level=0;

    if(event.action==EMPATHY_EVENT_INPUT_MOUSE_LEFT_KEY_PRESS || event.action==EMPATHY_EVENT_INPUT_MOUSE_RIGHT_KEY_PRESS){
        life_event::CWave_data * wave=new life_event::CWave_data();

        Empathy* empathy1=Empathy::getInstance();

        GLdouble xPos=event.getDouble(EMPATHY_MOUSE_XPOS)/(empathy1->getScreenSize());
        GLdouble yPos=event.getDouble(EMPATHY_MOUSE_YPOS)/(empathy1->getScreenSize());

        xPos=2 * xPos-1;
        yPos=2 * yPos-1;

        wave->setCenterX(xPos);
        wave->setCenterY(yPos);

        GLfloat r,g,b;

        switch (level%5){
            case 1:{
                r=0.1;
                g=0.7;
                b=0.7;
                break;
            }
            case 2:{
                r=0.7;
                g=0.3;
                b=0.4;
                break;
            }
            case 3:{
                r=0.3;
                g=0.4;
                b=0.7;
                break;
            }
            case 4:{
                r=0.7;
                g=0.7;
                b=0.1;
                break;
            }
            default:{
                r=0.7;
                g=0.1;
                b=0.7;
            }

        }
        level ++;
		wave->setDampingConst(20.0f);
        wave->setColor(r,g,b);

        addLifeEvent(wave);
    }

}

empathy::brain::DummyTouchBrain::DummyTouchBrain() : Brain() {

}
