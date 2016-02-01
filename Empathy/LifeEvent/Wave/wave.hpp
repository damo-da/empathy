#ifndef LIFE_EVENT_WAVE
#define LIFE_EVENT_WAVE

#include "../life_event.hpp"
#include "wave_data.hpp"

#include <vector>
#include <math.h>

#define EMPATHY_LIFE_EVENT_WAVE_ID "WAVE_ID"
#define EMPATHY_LIFE_EVENT_WAVE_CREST_COMPLETE "EMPATHY_LIFE_EVENT_WAVE_CREST_COMPLETE"

#define EMPATHY_LIFE_EVENT_WAVE_ONE_WAVE_COMPLETE 1

class LifeEvent_Wave: public LifeEvent {

public:
    virtual void onReceiveEvent(Event &event) override;

    std::vector<GLfloat> color;//in rgba

    GLfloat centerX;
    GLfloat centerY;

    bool shouldCreateNewWave;

    std::vector<WaveData> waveData;

    //called once. By the constructor. Overridden method of parent
    virtual void onInit() override;

    //called every frame to draw the data
    virtual void draw() override;

    //called by the destructor
    virtual void onDestroy() override;

    //set the center
    void setCenter(GLfloat x, GLfloat y) {centerX = x; y = centerY;}

    //constructors
    LifeEvent_Wave(GLfloat, GLfloat);

    void setColor(GLfloat, GLfloat, GLfloat, GLfloat);

    GLfloat getFrequency(){return frequency;}
    GLfloat getWavelength(){return waveLength;}
    void setFrequency(GLfloat f){this->frequency=f;}
    GLfloat getLastWaveCompletionTime(){return lastWaveCompletionTime;}

    GLfloat getWaveSpeed(){return getFrequency()*getWavelength();}
    GLdouble getAngularMomentum(){return M_2_PI*getFrequency();}
    GLfloat getTimePeriod(){return 1.0f/getFrequency();}


protected:
    virtual void onRun(GLfloat lfloat) override;

private:
    GLfloat frequency, waveLength;
    GLfloat lastWaveCompletionTime;

};

#endif