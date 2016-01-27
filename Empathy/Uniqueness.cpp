//
// Created by damo on 1/26/16.
//


#include "Uniqueness.h"
#include <iostream>

using namespace std;
int Uniqueness::newId() {
    lastId ++;
    return lastId;
}

int Uniqueness::lastId=0;