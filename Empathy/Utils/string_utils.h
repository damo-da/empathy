//
// Created by damo on 2/14/16.
//

#ifndef EMPATHY_STRING_UTILS_H
#define EMPATHY_STRING_UTILS_H
#include <vector>
#include <iostream>

std::vector<std::string> &str_split(const std::string &s,char delim,std::vector<std::string> &elems);
std::vector<std::string> str_split(const std::string&s,char delim);
std::string str_trim(const std::string string);
std::string str_replace(const std::string string,const char initial,const char final);
std::string str_remove_char(const std::string string,const char toRemove);

#endif //EMPATHY_STRING_UTILS_H
