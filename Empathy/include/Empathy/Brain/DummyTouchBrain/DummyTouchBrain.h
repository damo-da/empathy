//
// Created by damo on 2/24/16.
//

#ifndef EMPATHY_DUMMYTOUCHBRAIN_H
#define EMPATHY_DUMMYTOUCHBRAIN_H

#include "../../empathy.h"
#include "../Brain.h"
namespace empathy{
    namespace brain{
        class DummyTouchBrain : public Brain{
        public:
            DummyTouchBrain();

            virtual void onReceiveEvent(empathy::radio::Event &event) override;

        protected:
            virtual void runLineNumber(std::string lineID, std::string callerID) override;
        };
    }


}


#endif //EMPATHY_DUMMYTOUCHBRAIN_H
