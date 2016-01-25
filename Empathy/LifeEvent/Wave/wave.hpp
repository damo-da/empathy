#ifndef LIFE_EVENT_WAVE
#define LIFE_EVENT_WAVE

#include "../life_event.hpp"
#include "wave_data.hpp"

#include <vector>

class LifeEvent_Wave: public LifeEvent{
public:
	float radius;
	float width;
	const float diff=0.03f;

	GLfloat centerX;
	GLfloat centerY;


	void init();

	std::vector<WaveData> waveData;

	void draw(GLuint);

	void destroy();

	void setCenter(GLfloat x,GLfloat y){centerX=x;y=centerY;}

	LifeEvent_Wave(int,std::string);
	LifeEvent_Wave(int,std::string,GLfloat,GLfloat);

	
	std::vector<GLfloat> color;//in rgba
	void setColor(GLfloat,GLfloat,GLfloat,GLfloat);

	GLfloat speed,waveLength;
	GLfloat amplitude;
	GLfloat getFrequency();
	GLfloat lastWaveCompletionTime;
	GLfloat getTimePeriod();
	GLfloat getLastWaveCompletionTime();

	void passTime(GLfloat);
private:
	
};

#endif