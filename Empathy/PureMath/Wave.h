//
// Created by damo on 2/5/16.
//

#ifndef EMPATHY_WAVE_H
#define EMPATHY_WAVE_H


#include <GL/glew.h>
#include <math.h>
#include <iostream>
#include "../Libs/cJSON/cJSON.h"

using namespace std;

namespace empathy {
    namespace pure_math {

        /*
         * A basic transverse wave.
         *
         * This wave has the following characteristics:
         *
         * frequency, wavelength, speed.
         * Regarding distance, the openGL screen measures a distance of 2.0 unit. Both in x and y axes.
         *
         * damping constant: an exponential function that decays the amplitude by distance **BUT NOT** by time.
         * */
        class Wave {
        public:
            /* Default constructor. */
            Wave();

        /* Basic wave stuffs. */
        public:
            void setWaveLength(GLfloat w) { this->waveLength = w; }
            void setFrequency(GLfloat f) { this->frequency = f; }
            void setCenter(GLfloat x, GLfloat y) { setCenterX(x);setCenterY(y); }
            void setCenterX(GLfloat x) { centerX = x; };
            void setCenterY(GLfloat y) { centerY = y; };
            void setDampingConst(GLfloat dampingConst) { Wave::dampingConst = dampingConst; }
            void setTime(GLfloat time) { Wave::time = time; }
            void setInitialPhase(GLfloat theta) { Wave::initialPhase = theta; }

            /* Set the current maximum amplitude. */
            void setAmplitude(GLfloat amplitude) { Wave::amplitude = amplitude; }

            GLfloat getWaveSpeed() const { return getFrequency() * getWaveLength(); }
            GLfloat getFrequency() const { return frequency; }
            GLfloat getWaveLength() const { return waveLength; }
            GLdouble getAngularMomentum() const { return 2 * M_PI * getFrequency(); }
            GLfloat getTimePeriod() const { return 1.0f / getFrequency(); }
            GLfloat getCenterX() const { return centerX; }
            GLfloat getCenterY() const { return centerY; }
            GLfloat getDampingConst() const { return dampingConst; }
            GLfloat getTime() const { return time; }
            GLfloat getInitialPhase() const { return initialPhase; }

            /* Return the maximum amplitude at the current time. */
            GLfloat getAmplitude() const { return amplitude; }


        private:
            GLfloat frequency;
            GLfloat waveLength;
            GLfloat centerX,centerY;
            GLfloat time;
            GLfloat amplitude; // the maximum amplitude of the wave
            GLfloat dampingConst;
            GLfloat initialPhase;

        public:
            /* Decode JSON values. */
            void decodeJson(std::string key, cJSON *value);

            /* Get amplitude at a certain point in current time. */
            GLfloat getAmplitudeAt(GLfloat distance) const ;
        };

    }
}
#endif //EMPATHY_WAVE_H
