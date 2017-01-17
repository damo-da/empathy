#ifndef DEMPATHY_LINEAR_TEXTINPUT_H
#define DEMPATHY_LINEAR_TEXTINPUT_H

#include "../Text/Text.h"

#define EMPATHY_TEXT_INPUT_ENTERED "EMPATHY_TEXT_ENTERED"
#define EMPATHY_TEXT_INPUT_TEXT "EMPATHY_TEXT_INPUT_TEXT"

namespace empathy{
    namespace life_event{
        class TextInput : public Text{
        public:
            TextInput();

            virtual void onReceiveEvent(radio::Event &event) override;
        };

    }
}


#endif //DEMPATHY_LINEAR_TEXTINPUT_H
