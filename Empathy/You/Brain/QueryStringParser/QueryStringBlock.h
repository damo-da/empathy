//
// Created by damo on 2/6/16.
//

#ifndef EMPATHY_QUERYSTRINGBLOCK_H
#define EMPATHY_QUERYSTRINGBLOCK_H

#include <iostream>
#include <vector>
#include "QueryStringLine.h"

class QueryStringBlock {
public:
    void execute();

private:
    std::vector<QueryStringLine> lines;
};


#endif //EMPATHY_QUERYSTRINGBLOCK_H
