//
// Created by geek on 4/8/16.
//

#include "../Utils/string_utils.h"
#include "BasicNote.h"

std::string empathy::moonlight::BasicNote::toString()
{
    std::string ret=std::to_string(octave) + note + (sharp?"s":"");
    return ret;
}

empathy::moonlight::BasicNote::BasicNote(std::string key) {
    octave=str_to_int(key);

    sharp=str_has_character(key,'s') || str_has_character(key,'#');

    note=str_to_lower(
            str_remove_character(
                    str_remove_character(
                            str_remove_character(key, int_to_single_char(octave))
                            ,'s')
                    ,'#'));
}


