//
// Created by damo on 2/6/16.
//

#ifndef EMPATHY_QUERYSTRINGPARSER_H
#define EMPATHY_QUERYSTRINGPARSER_H

#include <iostream>
#include <vector>
#include <map>
#include "QueryStringBlock.h"

class QueryStringParser {
public:
    QueryStringParser(std::string);
    void execute(int lineNumber);

private:
    std::map<int,QueryStringBlock> blocks;
};


#endif //EMPATHY_QUERYSTRINGPARSER_H
