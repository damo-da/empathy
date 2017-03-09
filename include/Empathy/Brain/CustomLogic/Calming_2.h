#ifndef EMPATHY_LINEAR_CALMING_2_H
#define EMPATHY_LINEAR_CALMING_2_H

#include "../JSONBrain/JSONBrain.h"

namespace empathy {
    namespace brain {

        class Calming_2 : public JSONBrain{
        public:
            Calming_2();

        protected:
            void runLineNumber(std::string lineID, std::string callerID, cJSON *override) override;

            void executeJson(const std::string action, cJSON *json, cJSON *override) override;

        };
    }
}


#endif //EMPATHY_LINEAR_CALMING_2_H
