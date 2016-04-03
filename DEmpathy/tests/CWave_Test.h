//
// Created by damo on 2/19/16.
//

#ifndef EMPATHY_CWAVE_TEST_H
#define EMPATHY_CWAVE_TEST_H

#include "Empathy/empathy.h"
#include "Empathy/Brain/Brain.h"

#include <iostream>
class CWave_Test : public empathy::brain::Brain{

    virtual void runLineNumber(std::string lineID, std::string callerID) override;
};


#endif //EMPATHY_CWAVE_TEST_H
