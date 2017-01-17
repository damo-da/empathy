#include "Calming_1.h"

using namespace std;

void empathy::brain::Calming_1::runLineNumber(std::string lineID, std::string callerID, cJSON *overrideData) {
    JSONBrain::runLineNumber(lineID, callerID, overrideData);

    if (lineID == CALMING_COLLECT_NAME){
        cout << "Collecting name"<<endl;
    }
}

empathy::brain::Calming_1::Calming_1() :
        empathy::brain::JSONBrain("brains/Calming_1.json"),
        name("Human") {

}
