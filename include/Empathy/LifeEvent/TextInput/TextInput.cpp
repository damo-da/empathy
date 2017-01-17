#include "TextInput.h"
#include <iostream>
using namespace std;

empathy::life_event::TextInput::TextInput() : Text(){

    Text::setText("");
    listen(EMPATHY_EVENT_INPUT_KEY_PRESS);
}

void empathy::life_event::TextInput::onReceiveEvent(empathy::radio::Event &event) {
    Text::onReceiveEvent(event);

    if (event.action == EMPATHY_EVENT_INPUT_KEY_PRESS){
        int key = event.getInt(EMPATHY_EVENT_INPUT_KEY);

        if (key == 257){
            empathy::radio::Event e(EMPATHY_TEXT_INPUT_ENTERED);
            e.putString(EMPATHY_TEXT_INPUT_TEXT, getText());
            dispatchEventToActions(EMPATHY_TEXT_INPUT_ENTERED, e);
        }else {
            std::string text = Text::getText() + (char)key;
            Text::setText(text);
        }

    }
}
