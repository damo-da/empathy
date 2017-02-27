#include "TextInput.h"
#include <iostream>
using namespace std;

empathy::life_event::TextInput::TextInput() : Text(){

    Text::setText("");
    listen(EMPATHY_EVENT_INPUT_KEY_PRESS);
}

void empathy::life_event::TextInput::onReceiveEvent(empathy::radio::Event &event) {
    Text::onReceiveEvent(event);

    if(isRunning()){

        if (event.action == EMPATHY_EVENT_INPUT_KEY_PRESS){
            int key = event.getInt(EMPATHY_EVENT_INPUT_KEY);


            if (key == 257){//enter key
                empathy::radio::Event e(EMPATHY_TEXT_INPUT_ENTERED);
                e.putString(EMPATHY_TEXT_INPUT_TEXT, getText());
                dispatchEventToActions(EMPATHY_TEXT_INPUT_ENTERED, e);
            }else{
                //instantiate with original text
                std::string text= Text::getText();

                if (key == 259) { //back space
                    text = text.length() == 0?"":text.substr(0, text.size()-1);

                } else if(key >=32 && key <= 254){//printable characters
                    text += (char)key;
                }

                Text::setText(text);
            }

        }
    }

}
