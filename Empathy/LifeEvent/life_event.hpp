/*
 * LifeEvents come as happenings. Together, You process LifeEvents to find out the meaning behind Empathy.
 *
 */

#ifndef EMPATHY_LIFE_EVENT
#define EMPATHY_LIFE_EVENT

#include "../global.hpp"
#include "../RadioStation/Subscriber.h"

#include <map>
#include <GL/glew.h>

class LifeEvent : public Subscriber{
public:
    virtual void passTime(GLfloat);
    GLfloat getTime();

    LifeEvent();


    bool isCreating() const{return !createComplete;}
    bool isRunning()const{ return createComplete && !runComplete;}
    bool isFinishing()const { return createComplete && runComplete && !finishComplete;}
    bool isFinished() const{return finishComplete;}
    bool isDestroyed()const{return destroyComplete;}

    virtual void draw();
    virtual void onDestroy();
    virtual void onInit();
protected:
    void doneCreating(){createComplete=true;}
    void doneRunning(){runComplete=true;}
    void doneFinishing(){finishComplete=true;}

    virtual void onCreate(GLfloat delTime);
    virtual void onRun(GLfloat delTime);
    virtual void onFinish(GLfloat delTime);

    GLfloat getTimeSinceRun()const {return runTime+finishTime;}
    GLfloat getTimeSinceCreate()const{return createTime+runTime+finishTime;}
    GLfloat getTimeSinceFinish()const{return finishTime;}

    bool runComplete;
    bool createComplete;
    bool finishComplete;
private:

    void doneDestroying(){destroyComplete=true;}

    bool destroyComplete;

    GLfloat createTime;
    GLfloat runTime;
    GLfloat finishTime;

    GLfloat totalTime;
};

#endif