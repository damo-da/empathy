#include "Calming_1.h"
#include "../../LifeEvent/TextInput/TextInput.h"

using namespace std;

void empathy::brain::Calming_1::runLineNumber(std::string lineID, std::string callerID, cJSON *overrideData) {
    JSONBrain::runLineNumber(lineID, callerID, overrideData);

    if (lineID == CALMING_COLLECT_NAME){

        life_event::TextInput * lifeEvent = new life_event::TextInput();


        lifeEvent->setColor(0.8, 0.5, 0.5);
        lifeEvent->setText("");
        lifeEvent->addAction(this, EMPATHY_TEXT_INPUT_ENTERED, CALMING_COLLECT_NAME);

        addLifeEvent(lifeEvent);
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
        cout << "Your name is "<<name << endl;
    }
}
