//
// Created by damo on 2/15/16.
//

#ifndef EMPATHY_JSONBRAIN_H
#define EMPATHY_JSONBRAIN_H


#include "../Brain.h"
#include "../../Libs/cJSON/cJSON.h"

#include <map>
namespace empathy {
    namespace brain {

        /* Create a Brain by parsing a JSON file using <JSONBrain>.
         *
         * Here's the simple rule to parse any file:
         *
         *     Brain * brain=new JSONBrain("myjsonfile.json");
         *     brain->addTo(empathy);//empathy's your app
         *
         * And the script executes!
         *
         * How to make a JSON instruction file? See <doc/json_brain_rules>.
         */
        class JSONBrain : public Brain {


        public:
            /* Constructor.
             *
             * @fileName the path of the json file to be parsed.
             */
            JSONBrain(std::string fileName);

            /* @inherit */
            virtual void terminate() override;

        protected:
            /* @inherit
             * */
            virtual void runLineNumber(std::string lineID, std::string callerID,cJSON * override=nullptr) override;

            /* Execute a certain JSON action.
             *
             * @action the name of action: create, goto, audio or anything else
             * @json the json data.
             *
             */
            virtual void executeJson(const std::string action, cJSON *json,cJSON * override= nullptr);

            /* Create a <LifeEvent> using it's name.
             *
             * Suppose you have a JSON action like this:
             * `{"type":"create","create":"cwave","colorRed":0.8}`
             * What you'd want this to do is to create an instance of CWave.
             *
             * So, <executeJson> receives this JSON action, and asks this method to create an empty instance
             * of CWave. JUST create an empty instance. Nothing more.
             *
             * @name the name of the object to be created.
             */
            virtual empathy::life_event::LifeEvent *createEventFromString(const std::string name);

        private:
            /* The parsed JSON file is stored in @root. */
            cJSON *root;

            /* <root> is parsed to <steps>. */
            std::map<std::string, std::vector<cJSON *>> steps;
        };
    }
}


#endif //EMPATHY_JSONBRAIN_H
