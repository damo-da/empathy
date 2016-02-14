//
// Created by damo on 2/14/16.
//

#include <sstream>
#include "string_utils.h"

std::vector<std::string> str_split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    str_split(s,delim,elems);
    return elems;
}

std::vector<std::string> &str_split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss,item,delim)){
        elems.push_back(item);
    }
    return elems;
}

std::string str_trim(const std::string string){
    std::string ret=string;

    while(ret[0]==' '){
        std::string yo="";
        for(int i=1;i<ret.size();i++){
            yo += ret[i];
        }
        ret=yo;
    }
    while(ret[ret.size()-1]==' '){
        std::string yo="";
        for(int i=0;i<ret.size()-1;i++){
            yo += ret[i];
        }
        ret=yo;
    }
    return ret;
}

std::string str_replace(const std::string string, const char initial, const char final) {
    std::string ret="";
    for(int i=0;i<string.size();i++){
        if(string[i]==initial){
            ret += final;
        }else {
            ret += string[i];
        }
    }
    return ret;
}

std::string str_remove_char(const std::string string, const char toRemove) {
    std::string ret="";
    for(int i=0;i<string.size();i++){
        if(string[i]==toRemove){
            continue;
        }else {
            ret += string[i];
        }
    }
    return ret;
}
