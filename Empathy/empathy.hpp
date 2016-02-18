#ifndef EMPATHY
#define EMPATHY

#include "global.hpp"

#include "You/you.hpp"

#include "LifeEvent/life_event.hpp"
#include "RadioStation/BroadcastStation.h"

#include "Implements/MoonLight.h"

class You;
class Brain;
class Empathy{
public:
	MoonLight * moonLight;

    virtual GLfloat  getTime()=0;
    virtual void terminate()=0;
    virtual void run()=0;


    //init the cross-platform system ready.
    virtual void init();

	//The constructor
	Empathy();

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