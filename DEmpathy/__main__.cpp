#include "DEmpathy.h"


#include "../Empathy/Brain/JSONBrain/JSONBrain.h"
#include "tests/CWave_Test.h"


using namespace std;


int  main(){
	DEmpathy * empathy=new DEmpathy();

//    CWave_Test * brain=new CWave_Test();
    JSONBrain * brain=new JSONBrain("assets/brains/CanonInD.json");
    brain->addTo(empathy);

	empathy->run();
}