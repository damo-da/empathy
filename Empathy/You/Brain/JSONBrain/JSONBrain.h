//
// Created by damo on 2/15/16.
//

#ifndef EMPATHY_JSONBRAIN_H
#define EMPATHY_JSONBRAIN_H


#include "../Brain.h"
#include "../../../Libs/cJSON/cJSON.h"

#include <map>
class JSONBrain : public Brain{

public:
    JSONBrain(std::string fileName);

    virtual void terminate() override;

protected:
    virtual void runLineNumber(std::string lineID, std::string callerID) override;

    virtual void executeJson(const std::string action,cJSON * json);

    virtual LifeEvent * createEventFromString(const std::string name);
private:
    cJSON * root;

    void createLifeEventFromJson(const std::string action,cJSON * json);

    std::map<std::string,std::vector<cJSON*>> steps;
public:
    virtual void addTo(Empathy *binder) override;

};


#endif //EMPATHY_JSONBRAIN_H
