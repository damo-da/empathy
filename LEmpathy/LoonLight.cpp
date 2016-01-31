//
// Created by damo on 1/29/16.
//

#include "LoonLight.h"

#include <iostream>
using namespace std;
void LoonLight::play(std::string id, bool repeat) {
    MoonLight::play(id, repeat);

    cout<<"playing "<<id<<endl;
}

void LoonLight::init() {
    MoonLight::init();


}
