#ifndef EMPATHY
#define EMPATHY

#include "global.hpp"

#include "You/you.hpp"

#include "LifeEvent/life_event.hpp"
#include "RadioStation/BroadcastStation.h"

#include "Implements/EmpathyBinder.h"
#include "Implements/MoonLight.h"

class EmpathyBinder;
class You;
class Brain;
class Empathy{
public:
    EmpathyBinder * binder;
	MoonLight * moonLight;

    //init the cross-platform system ready.
    virtual void init();

	//The constructor
	Empathy(EmpathyBinder * binder);

    void setMoonLight(MoonLight *m){moonLight=m;}

    void loop();

	void setScreenSize(int,int);

	void flush();

	You * you;

    static BroadcastStation broadcastStation;

    void addBrain(Brain * brain);


    const std::vector<Brain *> &getBrains() const {
        return brains;
    }

    std::vector<Brain *> brains;

private:
	//Screen Size
	uint sc_size_x,sc_size_y;

	void initGlew();
	void initShaders();
	void initGL();
	void initYou();
};

#endif