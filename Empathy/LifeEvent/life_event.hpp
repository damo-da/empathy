/*
 * LifeEvents come as happenings. Together, You process LifeEvents to find out the meaning behind Empathy.
 *
 */

#ifndef EMPATHY_LIFE_EVENT
#define EMPATHY_LIFE_EVENT

#include "../global.hpp"
#include "../RadioStation/Subscriber.h"

#include <GL/glew.h>
#include <map>
#include <vector>

#define EMPATHY_LIFE_EVENT_CREATE_COMPLETE "EMPATHY_LIFE_EVENT_CREATE_COMPLETE"
#define EMPATHY_LIFE_EVENT_RUN_COMPLETE "EMPATHY_LIFE_EVENT_RUN_COMPLETE"
#define EMPATHY_LIFE_EVENT_FINISH_COMPLETE "EMPATHY_LIFE_EVENT_FINISH_COMPLETE"
#define EMPATHY_LIFE_EVENT_DESTROYED "EMPATHY_LIFE_EVENT_DESTROYED"

class LifeEvent : public Subscriber{
public:
    LifeEvent();

/*Activity lifecycle*/
public:
    bool isCreating() const{return !createComplete;}
    bool isRunning()const{ return createComplete && !runComplete;}
    bool isFinishing()const { return createComplete && runComplete && !finishComplete;}
    bool isFinished() const{return finishComplete;}
    bool isDestroyed()const{return destroyComplete;}

    virtual void draw()=0;
    virtual void onDestroy();
    virtual void onInit();
    void init();
protected:
    void doneCreating();
    void doneRunning();
    void doneFinishing();

    virtual void onCreate(GLfloat delTime);
    virtual void onRun(GLfloat delTime);
    virtual void onFinish(GLfloat delTime);

    GLfloat getTimeSinceRun()const {return runTime+finishTime;}
    GLfloat getTimeSinceCreate()const{return createTime+runTime+finishTime;}
    GLfloat getTimeSinceFinish()const{return finishTime;}
private:
    void doneDestroying(){destroyComplete=true;emit(EMPATHY_LIFE_EVENT_DESTROYED);}

    bool initComplete;
    bool runComplete;
    bool createComplete;
    bool finishComplete;
    bool destroyComplete;

    GLfloat createTime;
    GLfloat runTime;
    GLfloat finishTime;

/*End of Activity life cycle*/

//Time and loop handlers
public:
    GLfloat getTotalTime();

    //game loop
    virtual void passTime(GLfloat delTime);
private:
    GLfloat totalTime;

//Depth. It is the z-index in the range 0.0 to 1.0. The more it is, the backward the object goes
public:
    GLfloat getDepth() const {
        return depth;
    }


    void setDepth(GLfloat depth) {
        LifeEvent::depth = depth;
    }

private:
    GLfloat depth;
};


#endif