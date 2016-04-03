#include "DEmpathy.h"



#include "Empathy/Brain/JSONBrain/JSONBrain.h"
#include "Empathy/Brain/DummyTouchBrain/DummyTouchBrain.h"

using namespace std;


int  main(){
	DEmpathy * empathy=new DEmpathy();

//    CWave_Test * brain=new CWave_Test();
    empathy::brain::JSONBrain * brain=new empathy::brain::JSONBrain("brains/CanonInD.json");
    brain->addTo(empathy);

    (new empathy::brain::DummyTouchBrain())->addTo(empathy);

	empathy->run();
}