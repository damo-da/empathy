#include "wave.hpp"
#include <iostream>
#include <math.h>
#include "../../global.hpp"
#include "../../RadioStation/TimeBroadcaster.h"

using namespace std;

void LifeEvent_Wave::init() {
    LifeEvent::init();

	frequency=1.0f;
	waveLength = 2.f;
	amplitude = 1.0f;

    lastWaveCompletionTime=0.0f;

    shouldCreateNewWave=true;

	color = {1.0f, 1.0f, 1.0f, 1.0f};

    createRepeatingTimeout(3.0f,EMPATHY_LIFE_EVENT_WAVE_ONE_WAVE_COMPLETE);
}

void LifeEvent_Wave::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	color = {r, g, b, a};
}

void LifeEvent_Wave::destroy() {
	for (int i = 0; i < waveData.size(); i++) {
		waveData[i].destroy();
	}
}

void LifeEvent_Wave::draw(GLuint shaderProgram) {
	glUseProgram(shaderProgram);

	// cout<<"Drawing"<<endl;
	glLineWidth(2.5);

	//set Vertex Color
	GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "vertexColor");
	glUniform4f(vertexColorLocation, color[0], color[1], color[2], color[3]);

	for (int i = 0; i < waveData.size(); i++) {
		waveData[i].draw(shaderProgram);
	}

	glUseProgram(0);

}


LifeEvent_Wave::LifeEvent_Wave(GLfloat cX, GLfloat cY)
	: LifeEvent()
{
	centerX = cX;
	centerY = cY;


	init();
}

GLfloat LifeEvent_Wave::getFrequency() {
	return frequency;
}
GLfloat LifeEvent_Wave::getLastWaveCompletionTime() {
	return lastWaveCompletionTime;
}
GLfloat LifeEvent_Wave::getTimePeriod() {
	return 1.0f/frequency;
}

void LifeEvent_Wave::passTime(GLfloat delTime) {
	LifeEvent::passTime(delTime);

	GLfloat timeDiff = getTime() - getLastWaveCompletionTime();

	GLfloat distanceDiff=waveLength/(timeDiff/frequency);

	if (distanceDiff>waveLength || (getLastWaveCompletionTime() == 0 && waveData.size() == 0)) {
		// cout << "wave complete at " << getTime() << endl;
		//time to add a new wave

		if (waveData.size() != 0) {
			lastWaveCompletionTime += getTimePeriod();
		}

		GLfloat frequency = getFrequency();
		GLfloat aMomentum = 2 * M_PI * frequency;
		GLfloat amplitude = sin(aMomentum * getTime());

		WaveData data(1.0f, 0.0f, centerX, centerY, true);

		waveData.push_back(data);

		Event e=Event(EMPATHY_EVENT_WAVE_COMPLETE);
        emit(e);
	}

	for (int i = 0; i < waveData.size(); i++) {

		waveData[i].radius += 0.001;
		waveData[i].calculateGlVertices();

		if (waveData[i].radius > 2.0f) {

			waveData[i].destroy();

			waveData.erase(waveData.begin() + i);
			i--;
		}
	}



}

void LifeEvent_Wave::onReceiveEvent(Event &event) {
    Subscriber::onReceiveEvent(event);

    if(event.action==EMPATHY_EVENT_REPEAT_TIMEOUT){

        int id=event.getInt(EMPATHY_LIFE_EVENT_ID);

        cout<<"received correct event with id "<<id<<endl;
    }else{
		cout<<"else event received"<<event.action<<endl;
	}
}
