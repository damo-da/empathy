//
// Created by damo on 2/7/16.
//

/*
 * The function file_read is from the OpenGL Programming wikibook: http://en.wikibooks.org/wiki/OpenGL_Programming
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"
#include "string_utils.h"


/**
 * Store all the file's contents in memory
 */
char* file_read(const char* filename)
{
    FILE* in = fopen(filename, "rb");
    if (in == NULL) {
        fprintf(stderr,"Could not open file: ");
        fprintf(stderr,"%s",filename);
        fprintf(stderr,"\n");
        return NULL;
    }

    int res_size = BUFSIZ;
    char* res = (char*)malloc(res_size);
    int nb_read_total = 0;

    while (!feof(in) && !ferror(in)) {
        if (nb_read_total + BUFSIZ > res_size) {
            if (res_size > 10*1024*1024) break;
            res_size = res_size * 2;
            res = (char*)realloc(res, res_size);
        }
        char* p_res = res + nb_read_total;
        nb_read_total += fread(p_res, 1, BUFSIZ, in);
    }

    fclose(in);
    res = (char*)realloc(res, nb_read_total + 1);
    res[nb_read_total] = '\0';
    return res;
}

std::vector<std::string> file_readlines(const char* filename) {
    std::string content=file_read(filename);

    std::vector<std::string> ret;
    str_split(content,'\n',ret);

    return ret;
}
