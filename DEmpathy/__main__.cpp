#include "DEmpathy.h"


#include "../Empathy/empathy.h"
#include "../Empathy/Brain/JSONBrain/JSONBrain.h"
using namespace std;


int  main(){
	DEmpathy * empathy=new DEmpathy();

//    CWave_Test * brain=new CWave_Test();
    empathy::brain::JSONBrain * brain=new empathy::brain::JSONBrain("assets/brains/CanonInD.json");
    brain->addTo(empathy);

	empathy->run();
}