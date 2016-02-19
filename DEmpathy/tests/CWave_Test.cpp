//
// Created by damo on 2/19/16.
//

#include "CWave_Test.h"
#include "../../Empathy/LifeEvent/CWave/LifeEvent_CWave.h"
#include "../../Empathy/LifeEvent/CWave/LifeEvent_CWave_data.h"

void CWave_Test::runLineNumber(std::string lineID, std::string callerID) {
    if(lineID=="begin"){
        LifeEvent_CWave * cWave=new LifeEvent_CWave();

        addLifeEvent(cWave);

        LifeEvent_CWave_data * data=new LifeEvent_CWave_data();
//        addLifeEvent(data);
    }
}
