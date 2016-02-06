//
// Created by damo on 2/6/16.
//

#include "DummyBrain.h"
#include "../../../LifeEvent/MathWave/MathWave_Sine.h"
#include "../../../LifeEvent/CWave/LifeEvent_CWave_data.h"
#include "../../../LifeEvent/MathWave/MathWave_Line.h"
#include "../../../LifeEvent/MathWave/MathWave_Sinc.h"
#include "../../../LifeEvent/MathWave/MathWave_Para_Circle.h"


DummyBrain::DummyBrain() : Brain() {

}

void DummyBrain::runLineNumber(int number, int caller) {
    switch (number){
        case 1:
        {
//            LifeEvent_CWave_data * wave=new LifeEvent_CWave_data();
//            addLifeEvent(wave);
//            wave->setCenter(0.0f,0.0f);
//            wave->setColor(1.0f,0.1f,1.0f);
//            wave->setFrequency(2.0f);

            MathWave_Para_Circle * wave=new MathWave_Para_Circle();

            addLifeEvent(wave);
            wave->setZoomY(0.3f);
            wave->setZoomX(0.3f);
            wave->setPencilSize(2.0f);
            wave->setHead(0.0f);
            wave->setTail(M_PI*2);
            wave->setSpeed(1.6f);
            wave->setLength(0.5f);
            wave->setDepth(0.0f);

            playKeyboardAudio("2A");

//            activateTimeoutForNextLine(2,3.0f);
            break;
        }
        case 2:
        {
            MathWave_Sinc* sineWave=new MathWave_Sinc();
            addLifeEvent(sineWave);
            sineWave->setZoomY(0.3f);
            sineWave->setPencilSize(2.0f);
            sineWave->setHead(-0.5f);
            sineWave->setTail(0.5f);
            sineWave->setPeriod(0.1f);
            sineWave->setSpeed(0.3f);
            sineWave->setLength(0.5f);
            sineWave->setDepth(1.0f);

            playKeyboardAudio("0B");

            activateTimeoutForNextLine(3,4.0f);
            break;
        }
        case 3:{
            MathWave_Line* line=new MathWave_Line();
            addLifeEvent(line);
            line->setOffsetY(0.3f);
            line->setDepth(0.1f);
            line->setSpeed(0.4f);

            playKeyboardAudio("0C");

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

            playKeyboardAudio("0D");

            activateTimeoutForNextLine(1,2.0f);
            break;
        }
        default:
            break;
    }
}

