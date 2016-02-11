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
//            activateTimeoutForNextLine(2,1.6f);
//            return;

            static int count=0;
            count++;

            MathWave_Para_Circle * wave=new MathWave_Para_Circle();
            addLifeEvent(wave);
            wave->setZoomY(0.3f);
            wave->setColor(1.0f,1.0f,0.0f);
            wave->setZoomX(0.3f);
            wave->setPencilSize(2.0f);
            wave->setHead(0.0f);
            wave->setTail(M_PI);
            wave->setSpeed(1.6f);
            wave->setLength(0.5f);
            wave->setDepth(0.0f);

            if(count%2==0){
                playKeyboardAudio("2B");
                wave->setColor(0.8f,0.8f,0.0f);
            }
            else{
                playKeyboardAudio("2A");
            }


            if(count<3){
                activateTimeoutForNextLine(1,1.6f);
            }
            else{
                count=0;
                activateTimeoutForNextLine(3,1.6f);
            }

            break;
        }
        case 3:
        {

            MathWave_Para_Circle * wave=new MathWave_Para_Circle();
            addLifeEvent(wave);
            wave->setZoomY(0.3f);
            wave->setColor(1.0f,0.5f,0.0f);
            wave->setZoomX(0.3f);
            wave->setPencilSize(2.0f);
            wave->setHead(0.0f);
            wave->setTail(M_PI);
            wave->setSpeed(1.6f);
            wave->setLength(0.5f);
            wave->setDepth(0.0f);

            playKeyboardAudio("2C");

            activateTimeoutForNextLine(4,2.2f);

            break;
        }
        case 4:
        {
            LifeEvent_CWave_data * wave=new LifeEvent_CWave_data();
            addLifeEvent(wave);
            wave->setColor(1.0f,0.1f,1.0f);
            wave->setWaveLength(1.0f);
            wave->setFrequency(0.5f);

            playKeyboardAudio("2E");
            activateTimeoutForNextLine(1,2.0f);
        }
        default:
            break;
    }
}

