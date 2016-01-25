#include "you.hpp"

#include "../LifeEvent/Wave/wave.hpp"

#include <typeinfo>

void You::init(){
	//initialize vector to store lifeevents
	lifeEvents=new std::vector<LifeEvent*>();

	//add a base wave
	LifeEvent_Wave * wave=new LifeEvent_Wave(1,"BaseWave",0.0f,0.0f);
	wave->setColor(0.0f,1.0f,0.0f,0.5f);//green
	addEvent(wave);

//	//add a secondary wave
//	LifeEvent_Wave * sWave=new LifeEvent_Wave(2,"SecondaryWave",0.2f,0.2f);
//	sWave->setColor(1.0f,0.0f,1.0f,0.5f);//pink
	// addEvent(sWave);

	//initializing time
	curTime=0;

	listen(Event::LIFE_EVENT_WAVE_COMPLETE);
}