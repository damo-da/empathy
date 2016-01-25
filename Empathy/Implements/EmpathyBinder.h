//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_NONNATIVEEMPATHY_H
#define EMPATHY_NONNATIVEEMPATHY_H

#include <GL/glew.h>

class EmpathyBinder {

public:
    virtual bool shouldTerminate();

    virtual GLfloat  getTime();
    virtual void pollEvents();
    virtual void swapBuffers();

    virtual void terminate();

    EmpathyBinder(){}
};


#endif //EMPATHY_NONNATIVEEMPATHY_H
