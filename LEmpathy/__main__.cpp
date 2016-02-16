#include "lempathy.hpp"


#include "../Empathy/You/Brain/JSONBrain/JSONBrain.h"


using namespace std;


int  main(){
	LEmpathy * empathy=new LEmpathy();

//    CanonInD * canon=new CanonInD();
//    canon->addTo(empathy);
//    empathy->addBrain(canon);


    JSONBrain * brain=new JSONBrain("assets/brains/CanonInD.json");
    brain->addTo(empathy);

	empathy->run();
}