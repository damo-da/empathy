#include "lempathy.hpp"
#include "../Empathy/You/Brain/DummyBrain/DummyBrain.h"

using namespace std;

int  main(){
	LEmpathy * empathy=new LEmpathy();

    DummyBrain *brain1=new DummyBrain();
    empathy->addBrain(brain1);

    DummyBrain *brain2=new DummyBrain();
//    brain2->setDelay(1.1f);
    empathy->addBrain(brain2);

	empathy->run();
}