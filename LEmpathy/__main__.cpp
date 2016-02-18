#include "lempathy.hpp"


#include "../Empathy/You/Brain/JSONBrain/JSONBrain.h"


using namespace std;


int  main(){
	LEmpathy * empathy=new LEmpathy();

    JSONBrain * brain=new JSONBrain("assets/brains/CanonInD.json");
    brain->addTo(empathy);

	empathy->run();
}