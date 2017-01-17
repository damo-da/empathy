#ifndef DEMPATHY_LINEAR_CALMING_1_H
#define DEMPATHY_LINEAR_CALMING_1_H

#define CALMING_COLLECT_NAME "CALMING_COLLECT_NAME"

#include "../JSONBrain/JSONBrain.h"
#include <iostream>

namespace empathy {
    namespace brain {

        class Calming_1: public JSONBrain {
        protected:
            virtual void runLineNumber(std::string lineID, std::string callerID, cJSON *overrideData) override;

            std::string name;
        public:
            virtual void onReceiveEvent(empathy::radio::Event &event) override;

        public:

            Calming_1();

            const std::string &getName() const;

            void setName(const std::string &name);
        };

    }
}

#endif //DEMPATHY_LINEAR_CALMING_1_H
