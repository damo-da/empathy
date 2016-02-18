#include "empathy.hpp"
#include "Implements/MoonLightBinder.h"
#include "Shader/DefaultShader.h"

using namespace std;

Empathy::Empathy():
moonLight(nullptr)
{

}


void Empathy::flush(){
    cout<<"Flush done"<<endl;

    moonLight->terminate();
    you->terminate();
}

void Empathy::init() {
//	cout<<"initing emp"<<endl;

    initGlew();

    initGL();

    initShaders();

    initYou();

    MoonLightBinder::init(moonLight);


    std::vector<Brain *> brains=this->getBrains();
    for(int i=0;i<brains.size();i++){
        you->addBrain(brains[i]);
    }
    this->moonLight->init();
}
void Empathy::initGlew(){
//	cout<<"initing glew"<<endl;

    //initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;

    }
}

void Empathy::initShaders(){
    DefaultShader::init();
}

void Empathy::initGL(){
//	cout<<"initing glViewport"<<sc_size_x<<","<<sc_size_y<<endl;
    glViewport(0, 0, sc_size_x, sc_size_y);
}

void Empathy::initYou(){
    you=new You();
    you->init();
}


void Empathy::setScreenSize(int x,int y){
//    cout<<"Set setScreenSize"<<endl;
    sc_size_x=x;
    sc_size_y=y;
}


BroadcastStation Empathy::broadcastStation= BroadcastStation();

void Empathy::loop() {

    BroadcastStation::dispatch();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT );

    you->setTime(getTime());

    you->blit();

}

void Empathy::addBrain(Brain *brain) {
    brains.push_back(brain);
}
