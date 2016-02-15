//
// Created by damo on 2/15/16.
//

#ifndef EMPATHY_JSONBRAIN_H
#define EMPATHY_JSONBRAIN_H


#include "Brain.h"

class JSONBrain : public Brain{

public:
    JSONBrain(std::string fileName);

protected:
    virtual void runLineNumber(std::string lineID, std::string callerID) override;
};


#endif //EMPATHY_JSONBRAIN_H
