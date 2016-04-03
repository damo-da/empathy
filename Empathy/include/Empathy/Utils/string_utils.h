//
// Created by damo on 2/14/16.
//

#ifndef EMPATHY_STRING_UTILS_H
#define EMPATHY_STRING_UTILS_H
#include <vector>
#include <iostream>

/* Split a string.
 *
 * @s the string to be splitted.
 * @delim the delimiter.
 * @elems the return variable.
 * */
std::vector<std::string> &str_split(const std::string &s,char delim,std::vector<std::string> &elems);

/* Split a string.
 *
 * @s the string to be splitted.
 * @delim the delimiter.
 * */
std::vector<std::string> str_split(const std::string&s,char delim);


/* Trim a string.
 *
 * By trimming a string means 'remove spaces from first and last of string.
 * @string the string to be trimmed.
 * */
std::string str_trim(const std::string string);


/* Convert a string to integer. */
int str_to_int(std::string string);

/* Convert an integer to string. */
std::string int_to_str(int integer);


std::string str_replace(const std::string str, const char from, const char to);

std::string str_remove_character(const std::string str,const char mChar);

bool str_has_character(const std::string str,const char mChar);

char int_to_single_char(const int num);

std::string str_to_lower(const std::string str);

#endif //EMPATHY_STRING_UTILS_H