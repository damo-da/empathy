//
// Created by damo on 2/6/16.
//

#include "DummyBrain.h"
#include "../../../LifeEvent/MathWave/MathWave_Sine.h"
#include "../../../LifeEvent/CWave/LifeEvent_CWave_data.h"
#include "../../../LifeEvent/MathWave/MathWave_Line.h"
#include "../../../LifeEvent/MathWave/MathWave_Sinc.h"

DummyBrain::DummyBrain() : Brain() {

}

void DummyBrain::runLineNumber(int number, int caller) {
    switch (number){
        case 1:
        {
            LifeEvent_CWave_data * wave=new LifeEvent_CWave_data();
            addLifeEvent(wave);
            wave->setCenter(0.0f,0.0f);
            wave->setColor(1.0f,0.1f,1.0f);
            wave->setFrequency(2.0f);

            activateTimeoutForNextLine(2,3.0f);
            break;
        }
        case 2:
        {
            MathWave_Sine* sineWave=new MathWave_Sine(0.1f);
            addLifeEvent(sineWave);
            sineWave->setZoomY(0.1f);
            sineWave->setPencilSize(2.0f);
            sineWave->setHead(-0.7f);
            sineWave->setTail(0.0f);
            sineWave->setPeriod(0.1f);
            sineWave->setSpeed(0.3f);
            sineWave->setLength(0.5f);
            sineWave->setDepth(1.0f);

            activateTimeoutForNextLine(3,4.0f);
            break;
        }
        case 3:{
            MathWave_Line* line=new MathWave_Line();
            addLifeEvent(line);
            line->setOffsetY(0.3f);
            line->setDepth(0.1f);

            activateTimeoutForNextLine(4,2.0f);
            break;
        }
        case 4:{
            MathWave_Sinc* sincWave=new MathWave_Sinc();
            addLifeEvent(sincWave);
            sincWave->setZoomY(0.7f);
            sincWave->setOffsetY(-0.2f);
            sincWave->setRotationAngle(M_PI_2);
            sincWave->setSpeed(0.3f);
            sincWave->setHead(-1.0f);
            sincWave->setLength(1.0f);
            sincWave->setPencilSize(2.0f);

            activateTimeoutForNextLine(1,2.0f);
            break;
        }
        default:
            break;
    }
}

