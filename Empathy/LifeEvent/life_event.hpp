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
private:
    void doneDestroying(){destroyComplete=true;}

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

//Depth
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