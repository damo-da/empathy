#ifndef DEMPATHY_LINEAR_EMOTIONVECTOR_H
#define DEMPATHY_LINEAR_EMOTIONVECTOR_H

#define EMPATHY_EVENT_EMOTION_COLLECTED "EMPATHY_EVENT_EMOTION_COLLECTED"

#include <iostream>

#include "../Libs/cJSON/cJSON.h"

namespace empathy {

    class EmotionVector {
    public:
        float getHappiness() const;

        void setHappiness(float happiness);

        float getSadness() const;

        void setSadness(float sadness);

        float getContempt() const;

        void setContempt(float contempt);

        float getDisgust() const;

        void setDisgust(float disgust);

        float getFear() const;

        void setFear(float fear);

        float getNeutral() const;

        void setNeutral(float neutral);

        float getSurprise() const;

        void setSurprise(float surprise);

        float getAnger() const;

        void setAnger(float anger);

    private:
        float happiness;
        float sadness;
        float contempt;
        float disgust;
        float fear;
        float neutral;
        float surprise;
        float anger;

        static EmotionVector * resultVector; // this will be used to store the results and hence,
                                    // the more accurate emotion of the user.

    public:
        EmotionVector();

        //Send the cJSON root structure to convert it into EmotionVectors
        EmotionVector(cJSON *vector);

        static void processVector(EmotionVector& vector);
        static std::string getDominantEmotion();

        static bool isHappy();

    };
}


#endif //DEMPATHY_LINEAR_EMOTIONVECTOR_H
