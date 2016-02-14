#include "lempathy.hpp"
#include "../Empathy/You/Brain/DummyBrain/DummyBrain.h"
#include "../Empathy/Utils/string_utils.h"
#include "../Empathy/You/Brain/MusicalBrain/MusicalBrain.h"

using namespace std;

int  main(){
	LEmpathy * empathy=new LEmpathy();

    DummyBrain *brain1=new DummyBrain();
    empathy->addBrain(brain1);

    MusicalBrain * musicalBrain=new MusicalBrain();
    musicalBrain->setFrequency(1.0f);
    musicalBrain->setMusic("0As 0As 0As, 0Bs, 0Cs");
    empathy->addBrain(musicalBrain);

	empathy->run();
}