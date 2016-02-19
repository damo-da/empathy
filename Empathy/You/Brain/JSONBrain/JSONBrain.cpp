//
// Created by damo on 2/15/16.
//

#include "JSONBrain.h"
#include "../../../Utils/file_utils.h"
#include "../../../Libs/cJSON/cJSON_utils.h"
#include "../../../Utils/string_utils.h"
#include "../../../LifeEvent/CWave/LifeEvent_CWave_data.h"
#include "../../../LifeEvent/MathWave/MathWave.h"
#include "../../../LifeEvent/MathWave/MathWave_Line.h"
#include "../../../LifeEvent/MathWave/MathWave_Sine.h"
#include "../../../LifeEvent/MathWave/MathWave_Sinc.h"
#include "../../../LifeEvent/MathWave/MathWave_Para_Circle.h"
#include <vector>

using namespace std;

void JSONBrain::runLineNumber(std::string lineID, std::string callerID) {
    std::vector<cJSON*> actions=steps[lineID];
    cout<<"running "<<lineID<<endl;

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

void JSONBrain::addTo(Empathy *binder) {
    Brain::addTo(binder);
}

void JSONBrain::executeJson(const std::string action,cJSON *json) {
    if(action=="audio"){

        std::string name=cJSON_GetObjectItem(json, "name")->valuestring;
        bool instrumental=(bool)cJSON_GetObjectItem(json,"instrumental")->valueint;

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
    }else if(action=="create"){
        std::string object=cJSON_GetObjectItem(json,"create")->valuestring;
        createLifeEventFromJson(object,json);
    }
}

void JSONBrain::createLifeEventFromJson(const std::string action, cJSON *json) {
    std::vector<std::string> keys=cJSON_get_keys(json);

    LifeEvent * event= createEventFromString(action);

    if(event != nullptr){
        for(int i=0;i<keys.size();i++){
            std::string key=keys[i];
            cJSON* value=cJSON_GetObjectItem(json,key.c_str());

            event->decodeJson(key,value);

        }

        addLifeEvent(event);
    }

}

LifeEvent *JSONBrain::createEventFromString(const std::string name) {
    if(name=="cwave"){
        return new LifeEvent_CWave_data();
    }else if(name=="mathwave_line"){
        return new MathWave_Line();
    }else if(name=="mathwave_para_circle"){
        return new MathWave_Para_Circle();
    }else if(name=="mathwave_sinc"){
        return new MathWave_Sinc();
    }else if(name=="mathwave_sine"){
        return new MathWave_Sine();
    }


    return nullptr;
}
