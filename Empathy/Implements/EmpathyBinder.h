//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_NONNATIVEEMPATHY_H
#define EMPATHY_NONNATIVEEMPATHY_H

#include <GL/glew.h>
#include "MoonLight.h"
#include "../You/Brain/Brain.h"
#include <vector>

class Brain;
class EmpathyBinder {
public:
    virtual bool shouldTerminate();

    virtual GLfloat  getTime()=0;


    virtual void terminate();

    EmpathyBinder();

    virtual void preLoop()=0;
    virtual void postLoop()=0;

    void addBrain(Brain * brain);


    const std::vector<Brain *> &getBrains() const {
        return brains;
    }

private:
    std::vector<Brain *> brains;
};


#endif //EMPATHY_NONNATIVEEMPATHY_H
