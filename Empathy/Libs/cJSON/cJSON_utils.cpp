//
// Created by damo on 2/16/16.
//

#include "cJSON_utils.h"
using namespace std;

std::vector<std::string> cJSON_get_keys(cJSON *object) {

    std::vector<std::string> result;

    if(object== nullptr)return result;
    if(object->type != cJSON_Object)return result;

    cJSON * c=object->child;
    while(c){
        result.push_back(c->string);
        c=c->next;
    }

    return result;
}

void cJSON_print_keys(cJSON *object) {
    std::vector<std::string> keys;
    keys=cJSON_get_keys(object);
    for(int i=0;i<keys.size();i++){
        std::cout<<keys[i]<<""<<endl;

    }
    cout<<endl;
}
