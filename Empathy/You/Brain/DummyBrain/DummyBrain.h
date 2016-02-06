//
// Created by damo on 2/6/16.
//

#ifndef EMPATHY_DUMMYBRAIN_H
#define EMPATHY_DUMMYBRAIN_H


#include "../Brain.h"

class DummyBrain : public Brain{

    virtual void runLineNumber(int number, int caller) override;

public:
    DummyBrain();
};


#endif //EMPATHY_DUMMYBRAIN_H
