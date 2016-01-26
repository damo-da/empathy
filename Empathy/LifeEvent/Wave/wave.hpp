#ifndef LIFE_EVENT_WAVE
#define LIFE_EVENT_WAVE

#include "../life_event.hpp"
#include "wave_data.hpp"

#include <vector>

class LifeEvent_Wave: public LifeEvent {
public:
    std::vector<GLfloat> color;//in rgba
    GLfloat speed, waveLength;
    GLfloat amplitude;
    GLfloat lastWaveCompletionTime;

	GLfloat centerX;
	GLfloat centerY;

    std::vector<WaveData> waveData;

    //called once. By the constructor. Overridden method of parent
	void init();

    //called every frame to draw the data
	void draw(GLuint);

    //called by the destructor
	void destroy();

    //set the center
	void setCenter(GLfloat x, GLfloat y) {centerX = x; y = centerY;}

    //constructors
	LifeEvent_Wave(GLfloat, GLfloat);


	void setColor(GLfloat, GLfloat, GLfloat, GLfloat);

	GLfloat getFrequency();
    GLfloat getTimePeriod();
	GLfloat getLastWaveCompletionTime();

	void passTime(GLfloat);


private:

};

#endif