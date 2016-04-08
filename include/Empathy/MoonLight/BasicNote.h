//
// Created by geek on 4/8/16.
//

#ifndef DEMPATHY_LINEAR_TONE_H
#define DEMPATHY_LINEAR_TONE_H

#include <iostream>

namespace empathy{
    namespace moonlight{
        class BasicNote {
            bool sharp;
            std::string note;
            int octave;


        public:
            bool isSharp() const {
                return sharp;
            }

            void setSharp(bool sharp) {
                BasicNote::sharp = sharp;
            }

            std::string getNote() const {
                return note;
            }

            void setNote(std::string note) {
                BasicNote::note = note;
            }

            int getOctave() const {
                return octave;
            }

            void setOctave(int octave) {
                BasicNote::octave = octave;
            }

            std::string toString();

            BasicNote(std::string);


        };
    }
}



#endif //DEMPATHY_LINEAR_TONE_H
