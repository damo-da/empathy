//
// Created by damo on 1/26/16.
//


#include "UniqueObject.h"
#include <iostream>

using namespace std;

UniqueObject::UniqueObject() {
    id=lastId+1;

    lastId++;

    objects.push_back(this);
}

long UniqueObject::lastId=0;
std::vector<UniqueObject *> UniqueObject::objects=std::vector<UniqueObject *>();