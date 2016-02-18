#include "DEmpathy.h"


#include "../Empathy/You/Brain/JSONBrain/JSONBrain.h"


using namespace std;


int  main(){
	DEmpathy * empathy=new DEmpathy();

    JSONBrain * brain=new JSONBrain("assets/brains/CanonInD.json");
    brain->addTo(empathy);

	empathy->run();
}