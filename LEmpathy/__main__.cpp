#include "lempathy.hpp"
#include "../Empathy/You/Brain/DummyBrain/DummyBrain.h"

using namespace std;

int  main(){
	LEmpathy * empathy=new LEmpathy();

    empathy->addBrain(new DummyBrain());

    empathy->addBrain(new DummyBrain());

	empathy->run();
}