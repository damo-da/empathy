#ifndef EMPATHY
#define EMPATHY

#include "global.hpp"

#include "You/you.hpp"

#include "LifeEvent/life_event.hpp"
#include "RadioStation/BroadcastStation.h"

#include "Implements/EmpathyBinder.h"
#include "Implements/MoonLight.h"

class Empathy{
public:
    EmpathyBinder * binder;
	MoonLight * moonLight;

	//init the cross-platform system ready.
	void init();

	//The constructor
	Empathy(EmpathyBinder * binder,MoonLight * moonLightBinder);

	//The window is created. Begin serving empathy
	void begin();
	

	void setScreenSize(int,int);


	void flush();

	You * you;

    static BroadcastStation broadcastStation;
private:
	//Screen Size
	uint sc_size_x,sc_size_y;

	void initGlew();
	void initShaders();
	void initGL();
	void initYou();
};

#endif