//
// Created by damo on 2/19/16.
//

#include "CWave_Test.h"

#include "Empathy/LifeEvent/CWave/CWave.h"
#include "Empathy/LifeEvent/CWave/CWave_data.h"

void CWave_Test::runLineNumber(std::string lineID, std::string callerID) {
    if(lineID=="begin"){
        empathy::life_event::CWave * cWave=new empathy::life_event::CWave();

        addLifeEvent(cWave);

        empathy::life_event::CWave_data * data=new empathy::life_event::CWave_data();
//        addLifeEvent(data);
    }
}
