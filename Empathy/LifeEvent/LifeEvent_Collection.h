//
// Created by damo on 2/5/16.
//

#ifndef EMPATHY_LIFEEVENT_COLLECTION_H
#define EMPATHY_LIFEEVENT_COLLECTION_H


#include "life_event.hpp"
#include <vector>

class LifeEvent_Collection : public LifeEvent{


public:
    LifeEvent_Collection();


    virtual void onInit() override;

    virtual void onDestroy() override;

    virtual void draw() override;

    virtual void passTime(GLfloat delTime) override;

public:
    const std::vector<LifeEvent *> &getCollection() const {
        return collection;
    }

    void addToCollection(LifeEvent * event);

    void removeFromCollection(LifeEvent * event);

    void clearCollection();

    void removeCompletedFromCollection();
private:
    std::vector<LifeEvent *> collection;

};


#endif //EMPATHY_LIFEEVENT_COLLECTION_H
