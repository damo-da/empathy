#include "you.hpp"

You::You(GLuint &shader){
	shaderProgram=shader;
}


void You::onReceiveEvent(Event event) {
    Subscriber::onReceiveEvent(event);

    if(event.action==Event::LIFE_EVENT_WAVE_COMPLETE){
        cout<<"Wave complete"<<endl;
    }
}
