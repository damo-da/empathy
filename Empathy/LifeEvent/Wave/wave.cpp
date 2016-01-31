#include "wave.hpp"
#include <iostream>
#include <math.h>
#include "../../global.hpp"
#include "../../RadioStation/TimeBroadcaster.h"

using namespace std;

void LifeEvent_Wave::init() {
    LifeEvent::init();

    frequency=0.95f;
    waveLength = 0.1f;

    shouldCreateNewWave=true;

    color = {1.0f, 1.0f, 1.0f, 1.0f};
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

void LifeEvent_Wave::passTime(GLfloat delTime) {
    LifeEvent::passTime(delTime);

    if(shouldCreateNewWave){
        //create the new wave
        WaveData data( 0.0f, centerX, centerY, true);

        //create a callback for next wave
        createTimeOut(getTimePeriod(),EMPATHY_LIFE_EVENT_WAVE_ONE_WAVE_COMPLETE);

        waveData.push_back(data);

        shouldCreateNewWave=false;
    }

    for (int i = 0; i < waveData.size(); i++) {

        waveData[i].radius += getWaveSpeed()*delTime;
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

    if(event.action==EMPATHY_EVENT_REPEAT_TIMEOUT ||
            event.action==EMPATHY_EVENT_TIMEOUT){

        int id=event.getInt(EMPATHY_SUBSCRIBER_ID);

        if(id==getId()){
            shouldCreateNewWave=true;

            //broadcast that the wave is complete
            Event e(EMPATHY_LIFE_EVENT_WAVE_CREST_COMPLETE);
            emit(e);
        }
    }else{
        cout<<"else event received"<<event.action<<endl;
    }
}
