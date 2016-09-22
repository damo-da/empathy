//
// Created by bad on 9/22/16.
//

#ifndef EMPATHY_BRAIN_EMOTIONBRAIN
#define EMPATHY_BRAIN_EMOTIONBRAIN

#include <cv.hpp>
#include <curl/curl.h>
#include <iostream>
#include <pthread.h>
#include <stack>

#include "../Brain.h"
#include "../../Libs/cJSON/cJSON.h"

namespace empathy{
    namespace brain{
        class EmotionBrain :public Brain{

        public:
            EmotionBrain();

            virtual void terminate() override;

            virtual void onReceiveEvent(empathy::radio::Event &event) override;

        protected:
            virtual void runLineNumber(std::string lineID, std::string callerID,cJSON * override=nullptr) override;

        private:
            static std::string root_path;

            static CURL * curl;
            static std::string readBuffer;

            static void capture_image(std::string name_to_save_as);
            static void upload_image(std::string tmp_name);

            void run_thread();

            static void * runActionInThread(void *);
            static size_t save_curl_response(void *contents, size_t size, size_t nmemb, void *userp);

            std::stack<pthread_t> thread_ids;

            static EmotionBrain* instance;

            static void parse_result();
        };
    }
}



#endif //EMPATHY_BRAIN_EMOTIONBRAIN
