//
// Created by damo on 2/15/16.
//

#ifndef EMPATHY_JSONBRAIN_H
#define EMPATHY_JSONBRAIN_H


#include "Brain.h"
#include "../../Libs/cJSON/cJSON.h"

#include <map>
class JSONBrain : public Brain{

public:
    JSONBrain(std::string fileName);

    virtual void terminate() override;

protected:
    virtual void runLineNumber(std::string lineID, std::string callerID) override;

    void executeJson(const std::string action,cJSON * json);
private:
    cJSON * root;

    std::map<std::string,std::vector<cJSON*>> steps;
public:
    virtual void addTo(EmpathyBinder *binder) override;
};


#endif //EMPATHY_JSONBRAIN_H
