//
// Created by damo on 1/29/16.
//

#ifndef EMPATHY_MOONLIGHT_H
#define EMPATHY_MOONLIGHT_H

#include <map>
#include "../RadioStation/Subscriber.h"
#include "BasicNote.h"

#define EMPATHY_AUDIO_PLAY "EMPATHY_PLAY_AUDIO"
#define EMPATHY_AUDIO_SHOULD_REPEAT "EMPATHY_AUDIO_SHOULD_REPEAT"
#define EMPATHY_AUDIO_PLAY_KEYBOARD "EMPATHY_AUDIO_PLAY_KEYBOARD"

namespace empathy {
    namespace moonlight {

        /* The audio implementation for Empathy.
         *
         * Note: this is just an implementation for playing audio. It DOES NOT play any
         * audio sound. This is to ensure that audio can be played in an platform-independent mode.
         * All platform dependent codes are written by creating flavors of the base implementations.
         *
         * For playing audio,you must override <playKeyboard()> or <play()>, whichever function you like.
         * After overriding this implementation, make sure to add to the <Empathy> instance.
         * by calling `empathyApp->setMoonLight(moonLightExtendedInstance);`
         *
         */
        class MoonLight : public radio::Subscriber {
        public:

            /* @inherit */
            virtual void onReceiveEvent(radio::Event &event) override;

            /* Default constructor */
            MoonLight();

            /* onInit() */
            virtual void init();

            /* onTerminate() */
            virtual void terminate();

        protected:
            /* Play a tune on keyboard.
             *
             * Notation should be like `1As` or `2A` or `3E` and not `3A#`
             * */
            virtual void playKeyboard(BasicNote note);

            /* Play a certain tone. Repeat=false; */
            void play(std::string id);

            /* Play a certain tone.
             *
             * @id the identification of the tone.
             * @repeat should the tone repeat forever?
             * */
            virtual void play(std::string id, bool repeat);
        };

    }
}
#endif //EMPATHY_MOONLIGHT_H
