#include "TextInput.h"
#include <iostream>
using namespace std;

empathy::life_event::TextInput::TextInput() : Text(){

    Text::setText("");
    listen(EMPATHY_EVENT_INPUT_KEY_PRESS);
}

void empathy::life_event::TextInput::onReceiveEvent(empathy::radio::Event &event) {
    Subscriber::onReceiveEvent(event);

    if (event.action == EMPATHY_EVENT_INPUT_KEY_PRESS){
        cout << event << endl;
        int key = event.getInt(EMPATHY_EVENT_INPUT_KEY);

        std::string text = Text::getText() + (char)key;
        Text::setText(text);
    }
}
