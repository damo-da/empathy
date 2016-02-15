#include "lempathy.hpp"
#include "../Empathy/Packages/CanonInD/CanonInD.h"
#include "../Empathy/Utils/string_utils.h"

using namespace std;

int  main(){
	LEmpathy * empathy=new LEmpathy();

    CanonInD * canon=new CanonInD();
    canon->addTo(empathy);
    empathy->addBrain(canon);

	empathy->run();
}