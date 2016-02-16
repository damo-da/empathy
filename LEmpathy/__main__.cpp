#include "lempathy.hpp"
#include "../Empathy/Packages/CanonInD/CanonInD.h"
#include "../Empathy/Utils/string_utils.h"
#include "../Empathy/You/Brain/JSONBrain.h"
#include "../Empathy/Utils/file_utils.h"
#include <vector>

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