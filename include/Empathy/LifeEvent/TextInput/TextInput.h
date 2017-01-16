#ifndef DEMPATHY_LINEAR_TEXTINPUT_H
#define DEMPATHY_LINEAR_TEXTINPUT_H

#include "../Text/Text.h"

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
