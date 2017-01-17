#include "Calming_1.h"
#include "../../LifeEvent/TextInput/TextInput.h"

using namespace std;

void empathy::brain::Calming_1::runLineNumber(std::string lineID, std::string callerID, cJSON *overrideData) {
    JSONBrain::runLineNumber(lineID, callerID, overrideData);

    if (lineID == CALMING_COLLECT_NAME){
        cout << "Collecting name"<<endl;

        life_event::TextInput * lifeEvent = new life_event::TextInput();


        lifeEvent->setColor(0.8, 0.5, 0.5);
        lifeEvent->setText("");

        addLifeEvent(lifeEvent);
    }
}

empathy::brain::Calming_1::Calming_1() :
        empathy::brain::JSONBrain("brains/Calming_1.json"),
        name("Human") {

}
