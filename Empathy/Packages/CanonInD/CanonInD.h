//
// Created by damo on 2/14/16.
//

#ifndef EMPATHY_CANONIND_H
#define EMPATHY_CANONIND_H


#include "../../You/Brain/Brain.h"

class CanonInD : public Brain{
public:
    CanonInD();

    virtual void addTo(EmpathyBinder *binder) override;

protected:
    virtual void runLineNumber(std::string lineID, std::string callerID) override;

};


#endif //EMPATHY_CANONIND_H
