
#include "Calming_2.h"

empathy::brain::Calming_2::Calming_2()
        : JSONBrain("brains/Calming_2.json") {

}

void empathy::brain::Calming_2::runLineNumber(std::string lineID, std::string callerID, cJSON *override) {
    JSONBrain::runLineNumber(lineID, callerID, override);
}

void empathy::brain::Calming_2::executeJson(const std::string action, cJSON *json, cJSON *override) {
    JSONBrain::executeJson(action, json, override);
}

void empathy::brain::Calming_2::onReceiveEvent(empathy::radio::Event &event) {
    Brain::onReceiveEvent(event);

    if(event.action == EMPATHY_CALMING_2_START_MUSIC ){
        runLineNumber("b1", "", nullptr);
    }
}
