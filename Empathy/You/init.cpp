#include "you.hpp"

#include "../LifeEvent/Wave/wave.hpp"

#include <typeinfo>

void You::init(){
	//initialize vector to store lifeevents
	lifeEvents=new std::vector<LifeEvent*>();
	
	//add a base wave
	LifeEvent_Wave * wave=new LifeEvent_Wave(1,"BaseWave",0.5f,0.5f);
	addEvent(wave);
	//add a secondary wave
	LifeEvent_Wave * sWave=new LifeEvent_Wave(2,"SecondaryWave",0.0f,0.0f);
	addEvent(sWave);
	
	//initializing time
	curTime=0;
}