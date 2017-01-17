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

            Calming_1();
        };

    }
}

#endif //DEMPATHY_LINEAR_CALMING_1_H
