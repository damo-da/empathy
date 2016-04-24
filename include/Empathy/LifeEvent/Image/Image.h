//
// Created by geek on 4/16/16.
//

#ifndef DEMPATHY_LINEAR_IMAGE_H
#define DEMPATHY_LINEAR_IMAGE_H


#include "../LifeEvent.h"

namespace empathy{
    namespace life_event{
        class Image : public LifeEvent{
        public:
            std::vector<unsigned char> image;
            unsigned width,height;
            double u3,v3;
        protected:
        public:
            virtual void onDestroy() override;

            virtual void onInit() override;

            virtual void onCreate(GLfloat delTime) override;

            virtual void onRun(GLfloat delTime) override;

            virtual void onFinish(GLfloat delTime) override;

            virtual void draw() override;

            Image();
        };
    }
}



#endif //DEMPATHY_LINEAR_IMAGE_H
