//
// Created by damo on 2/15/16.
//

#include "JSONBrain.h"
#include "../../Utils/file_utils.h"
#include "../../Libs/cJSON/cJSON_utils.h"
#include "../../Utils/string_utils.h"
#include <vector>

using namespace std;

void JSONBrain::runLineNumber(std::string lineID, std::string callerID) {
    std::vector<cJSON*> actions=steps[lineID];

    for(int i=0;i<actions.size();i++){
        std::string action=cJSON_GetObjectItem(actions[i],"type")->valuestring;
        executeJson(action,actions[i]);
    }
}

JSONBrain::JSONBrain(std::string fileName) :
        Brain(),
        root(nullptr),
        steps()
{
    std::string fileContents=file_read(fileName.c_str());
    root = cJSON_Parse(fileContents.c_str());

    cJSON * steps=cJSON_GetObjectItem(root,"steps");

    std::vector<std::string> stepKeys=cJSON_get_keys(steps);
    for(int i=0;i<stepKeys.size();i++){
        std::string key=stepKeys[i];

        cJSON* actionList=cJSON_GetObjectItem(steps,key.c_str());

        std::vector<cJSON*> arrayList;
        if(actionList->type==cJSON_Object)arrayList.push_back(actionList);
        else if(actionList->type==cJSON_Array){
            actionList=actionList->child;
            while(actionList){
                arrayList.push_back(actionList);
                actionList=actionList->next;
            }
        }
        this->steps[key]=arrayList;
    }



}

void JSONBrain::terminate() {
    Brain::terminate();

    cJSON_Delete(root);
}

void JSONBrain::addTo(EmpathyBinder *binder) {
    Brain::addTo(binder);
}

void JSONBrain::executeJson(const std::string action,cJSON *json) {
    if(action=="audio"){

        std::string name=cJSON_GetObjectItem(json, "name")->valuestring;
        bool instrumental=cJSON_GetObjectItem(json,"instrumental")->valueint;

        if(instrumental){

            std::string instrument=cJSON_GetObjectItem(json,"instrument")->valuestring;

            if(instrument=="keyboard" || instrument=="piano"){
                playKeyboardAudio(name);
            }
        }
    }else if(action=="goto"){
        std::string stepID=cJSON_GetObjectItem(json,"stepID")->valuestring;
        double after=cJSON_GetObjectItem(json,"in")->valuedouble;

        activateTimeoutForNextLine(stepID,after);
    }
}
