#include "you.hpp"

void You::addEvent(LifeEvent * e) {
	lifeEvents->push_back(e);
}
void You::removeEvent(LifeEvent * e) {
	for (int i = 0; i < lifeEvents->size(); i++) {
		if ( (*lifeEvents)[i]->getId() == e->getId()) {

			(*lifeEvents)[i]->destroy();

			lifeEvents->erase(lifeEvents->begin() + i);

			i--;
		}
	}
}

void You::clearEvents() {

	while(lifeEvents->size()>0){
		LifeEvent * event = (*lifeEvents)[0];

		removeEvent(event);
	}
}