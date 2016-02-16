//
// Created by damo on 2/16/16.
//

#ifndef EMPATHY_CJSON_UTILS_H
#define EMPATHY_CJSON_UTILS_H

#include <iostream>
#include <vector>
#include "cJSON.h"

std::vector<std::string> cJSON_get_keys(cJSON *object);
void cJSON_print_keys(cJSON * object);

#endif //EMPATHY_CJSON_UTILS_H
