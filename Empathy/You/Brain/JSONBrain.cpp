//
// Created by damo on 2/15/16.
//

#include "JSONBrain.h"
#include "../../Libs/cJSON/cJSON.h"
#include "../../Utils/file_utils.h"

void JSONBrain::runLineNumber(std::string lineID, std::string callerID) {

}

JSONBrain::JSONBrain(std::string fileName) : Brain() {
    std::string fileContents=file_read(fileName.c_str());
    cJSON *root = cJSON_Parse(fileContents.c_str());


}
