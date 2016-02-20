//
// Created by damo on 2/3/16.
//

#ifndef EMPATHY_FADEINOUT_H
#define EMPATHY_FADEINOUT_H

#include "../life_event.h"
namespace empathy {
    namespace life_event {
        class FadeInOut : public LifeEvent {

        public:
            virtual void onDestroy() override;

            virtual void onInit() override;

        protected:
            virtual void onCreate(GLfloat delTime) override;

            virtual void onRun(GLfloat delTime) override;

            virtual void onFinish(GLfloat delTime) override;

            GLfloat getX();

            GLfloat getY();

        private:
            GLfloat scale;
            GLfloat posX, posY;
            GLfloat rotation;

        };
    }
}

#endif //EMPATHY_FADEINOUT_H
