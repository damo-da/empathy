//
// Created by damo on 1/29/16.
//

#ifndef EMPATHY_MOONLIGHT_H
#define EMPATHY_MOONLIGHT_H

#include "../RadioStation/Subscriber.h"
#include <map>

#define EMPATHY_AUDIO_PLAY "EMPATHY_PLAY_AUDIO"
#define EMPATHY_AUDIO_SHOULD_REPEAT "EMPATHY_AUDIO_SHOULD_REPEAT"
#define EMPATHY_AUDIO_PLAY_KEYBOARD "EMPATHY_AUDIO_PLAY_KEYBOARD"
namespace empathy {
    namespace moonlight {

        class MoonLight : public Subscriber {
        public:
            virtual void onReceiveEvent(Event &event) override;

            MoonLight();

            virtual void init();

            virtual void terminate();

        private:
            void play(std::string id);

        protected:
            virtual void playKeyboard(std::string key) = 0;

            virtual void play(std::string id, bool repeat);
        };

    }
}
#endif //EMPATHY_MOONLIGHT_H
