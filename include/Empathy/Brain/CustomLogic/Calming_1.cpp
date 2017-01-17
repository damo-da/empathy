#include "Calming_1.h"
#include "../../LifeEvent/TextInput/TextInput.h"

using namespace std;

void empathy::brain::Calming_1::runLineNumber(std::string lineID, std::string callerID, cJSON *overrideData) {
    JSONBrain::runLineNumber(lineID, callerID, overrideData);

    if (lineID == CALMING_COLLECT_NAME){

        life_event::TextInput * textInput = new life_event::TextInput();
        textInput->setColor(0.8, 0.5, 0.5);
        textInput->setText("");
        textInput->setIdentifier("calming_1_text_input");
        textInput->setDuration(1000);
        textInput->setFadeOutDuration(0.5);
        textInput->addAction(this, EMPATHY_TEXT_INPUT_ENTERED, CALMING_COLLECT_NAME);
        textInput->addAction("user_name_input_label", EMPATHY_TEXT_INPUT_ENTERED, EMPATHY_LIFE_EVENT_FINISH);
        textInput->addAction(textInput, EMPATHY_TEXT_INPUT_ENTERED, EMPATHY_LIFE_EVENT_FINISH);

        addLifeEvent(textInput);
    }
}

empathy::brain::Calming_1::Calming_1() :
        empathy::brain::JSONBrain("brains/Calming_1.json"),
        name("Human") {

}

void empathy::brain::Calming_1::onReceiveEvent(empathy::radio::Event &event) {
    Brain::onReceiveEvent(event);

    if(event.action == CALMING_COLLECT_NAME){
        string name = event.getString(EMPATHY_TEXT_INPUT_TEXT);

        Calming_1::setName(name);
    }
}

const string &empathy::brain::Calming_1::getName() const {
    return name;
}

void empathy::brain::Calming_1::setName(const string &name) {
    Calming_1::name = name;
}
