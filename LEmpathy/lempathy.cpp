#include "lempathy.hpp"

void LEmpathy::run(){
	
	cout<<"\n\n\n\n\n--------------Program Begin-------------\n\n"<<endl;
	
	init();

	begin();

	cout<<"\n\n--------------Program End-------------\n\n"<<endl;
}

LEmpathy * LEmpathy::instance=nullptr;