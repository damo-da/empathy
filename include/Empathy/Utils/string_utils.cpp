//
// Created by damo on 2/14/16.
//

#include <sstream>
#include "string_utils.h"
#include <algorithm>
#include <string>

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


int str_to_int(std::string string) {
    const char *p = string.c_str();

    char *end;

    for (long i = strtol(p, &end, 10);
         p != end;
         i = strtol(p, &end, 10))
    {
        p = end;
        if (errno == ERANGE){
            errno = 0;

            //TODO raise RuntimeException
            return -1;
        }

        return i;

    }
}

std::string int_to_str(int integer) {
    char str[20];
    sprintf(str, "%d", integer);
    std::string string(str);

    return string;
}

std::string str_replace(const std::string str, const char from, const char to) {
    std::string ret="";

    std::vector<std::string> boxes=str_split(str,from);
    for(int i=0;i<boxes.size();i++){
        ret += boxes[i];

        if(i<boxes.size()-1){
            if(to != '\0')
                ret += to;
        }
    }

    return ret;
}

std::string str_remove_character(const std::string str, const char mChar) {
    return str_replace(str,mChar,'\0');
}

bool str_has_character(const std::string str, const char mChar) {
    for(int i=0;i<str.size();i++){
        if(str[i]==mChar)return true;
    }
    return false;
}

char int_to_single_char(const int num) {
    return int_to_str(num).c_str()[0];
}

std::string str_to_lower(const std::string str) {
    std::string data = str;
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data;
}
