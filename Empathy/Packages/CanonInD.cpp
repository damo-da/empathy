//
// Created by damo on 2/14/16.
//

#include "CanonInD.h"
#include "../You/Brain/MusicalBrain/MusicalBrain.h"
#include "../LifeEvent/CWave/LifeEvent_CWave_data.h"

CanonInD::CanonInD() : Brain() {

}

void CanonInD::runLineNumber(int number, int caller) {
    switch (number){
        case 1: {
            LifeEvent_CWave_data * wave=new LifeEvent_CWave_data();
            wave->setColor(0.8f,0.1f,0.8f);
            addLifeEvent(wave);

            activateTimeoutForNextLine(1,4.0f);
            break;
        }
        default:
            break;
    }
}

void CanonInD::addTo(EmpathyBinder *binder) {
    Brain::addTo(binder);

    MusicalBrain * musicalBrain=new MusicalBrain();
    musicalBrain->setFrequency(1.0f);
    musicalBrain->setMusic("2D,4Fs,2A,3D,3Fs,1A 4E,2E,2A,3Cs,1B 4D,2Fs,2B,3D,1Fs 4Cs,2Cs,1Fs,1A,1G 3B, 2D, 2G, 2B,1D 3A,1A, 2D, 2Fs, 1G 3B, 2D, 2G,2B,1A 4Cs, 2E, 2A, 3Cs");
//    musicalBrain->setMusic("1C , 2D, 3E");
    binder->addBrain(musicalBrain);
    musicalBrain->setDelay(getDelay());

}
