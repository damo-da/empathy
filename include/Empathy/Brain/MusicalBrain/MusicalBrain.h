//
// Created by damo on 2/14/16.
//

#ifndef EMPATHY_MUSICALBRAIN_H
#define EMPATHY_MUSICALBRAIN_H


#include "../Brain.h"

namespace empathy {

    namespace brain {

        class MusicalBrain : public Brain {
            /* The simplest way to play keyboard music in Empathy.
             *
             * You give it a beat frequency: 2 bits per second, 1.5 bits per second. And notes: '1As,2Bs,1C'
             * and MusicalBrain runs! Tada!
             *
             * Usage:
             *
             *     MusicalBrain* mBrain=new MusicalBrain();
             *     mBrain->setMusic("1As 2As,2Bs,1C");
             *     mBrain->setFrequency(1.0f);
             *     mBrain->addTo(empathy);
             *
             * Music notation : <moment>,<moment>,<moment>,...
             * <moment> ::= <beat>[<space><beat>][<space><beat>]...
             * <beat> ::= "2As", "1Bs", "1C", etc
             *
             * eg:
             * "1As, 2As" plays 1As then 2As
             * "1As 2As, 3A" plays 1As and 2As at the same time and then 3A
             */

        public:
            /* Default Constructor */
            MusicalBrain();

        protected:
            /* @inherit */
            virtual void runLineNumber(std::string lineID, std::string callerID,cJSON * override=nullptr) override;

        public:

            /* Get the beats per second of the music notation.
             *
             * Warning: not frequency of music but the beat per second frequency
             * */
            GLfloat getFrequency() const { return frequency; }

            /* Set the beats per second of the music notation.
             *
             * Warning: not frequency of music but the beat per second frequency
             * */
            void setFrequency(GLfloat frequency) { MusicalBrain::frequency = frequency; }

        private:

            /* The beats per second of the music notation.
             *
             * Warning: not frequency of music but the beat per second frequency
             * */
            GLfloat frequency;

        public:

            /* Set the music. See the manual above for <MusicalBrain> for more info. */
            void setMusic(std::string);

        private:
            /* The music sequence, decoded from string. */
            std::vector<std::vector<std::string>> sequence;
        };
    }
}

#endif //EMPATHY_MUSICALBRAIN_H
