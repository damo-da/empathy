//
// Created by damo on 2/6/16.
//

#ifndef EMPATHY_DUMMYBRAIN_H
#define EMPATHY_DUMMYBRAIN_H


#include "../Brain.h"
namespace empathy {

    namespace brain {

        /*
         * It's a dummy brain. What do you want from a dummy?
         */
        class DummyBrain : public Brain {

            /* @inherit */
            virtual void runLineNumber(std::string lineID, std::string callerID,cJSON * override=nullptr) override;

        public:
            /* Constructor */
            DummyBrain();
        };
    }
}


#endif //EMPATHY_DUMMYBRAIN_H
