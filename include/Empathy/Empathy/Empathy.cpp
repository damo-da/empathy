#include "Empathy.h"


#include "../MoonLight/MoonLight.h"
#include "../You/you.h"

#include "../Shader/TextShader.h"
#include "../Shader/DefaultShader.h"

using namespace std;

empathy::Empathy::Empathy():
moonLight(nullptr),
_shouldClose(false),
sc_size(800),
marginTop(10), marginLeft(10)
{
    instance=this;
}


void empathy::Empathy::flush(){
    cout<<"Flush done"<<endl;

    moonLight->terminate();
    you->terminate();

    Font::flush();

    shader::DefaultShader::flush();
    shader::TextShader::flush();

}

void empathy::Empathy::init() {
//	cout<<"initing emp"<<endl;

    //initialize base location
    getBase();


    initGlew();

    initGL();

    initShaders();

    initYou();

    Font::load(getAssetPath("fonts/FreeSans.ttf"));

    if(this->moonLight != nullptr)
        this->moonLight->init();
}
void empathy::Empathy::initGlew(){
//	cout<<"initing glew"<<endl;

    //initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;

    }
}

void empathy::Empathy::initShaders(){
    shader::DefaultShader::init();
    shader::TextShader::init();
}

void empathy::Empathy::initGL(){
//	cout<<"initing glViewport"<<sc_size_x<<","<<sc_size_y<<endl;

}

void empathy::Empathy::initYou(){
    you=new empathy::You();
    you->init();
}


void empathy::Empathy::setScreenSize(int x){
//    cout<<"Set setScreenSize"<<endl;

    sc_size=x;

    glViewport(marginLeft, marginTop, sc_size,sc_size);
}

void empathy::Empathy::setScreenMargins(int x,int y){

    marginLeft=x;
    marginTop=y;

    glViewport(marginLeft, marginTop, sc_size,sc_size);
}

void empathy::Empathy::loop() {
    empathy::radio::BroadcastStation::dispatch();

    you->setTime(getTime());

    you->blit();

}

void empathy::Empathy::addBrain(empathy::brain::Brain *brain) {
    brains.push_back(brain);
    you->addBrain(brain);
}

empathy::Empathy * empathy::Empathy::instance= nullptr;

void empathy::Empathy::initFont() {
    empathy::Font::load(getAssetPath("fonts/FreeType.ttf"));
}

