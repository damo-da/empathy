//
// Created by damo on 2/6/16.
//

#ifndef EMPATHY_DUMMYBRAIN_H
#define EMPATHY_DUMMYBRAIN_H


#include "../Brain.h"
namespace empathy {
    namespace brain {

        class DummyBrain : public Brain {

            virtual void runLineNumber(std::string lineID, std::string callerID) override;

        public:
            DummyBrain();
        };
    }
}


#endif //EMPATHY_DUMMYBRAIN_H
