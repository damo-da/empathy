#include "EmotionVector.h"

empathy::EmotionVector::EmotionVector():
happiness(0),
sadness(0),
anger(0),
surprise(0),
neutral(0),
contempt(0),
disgust(0),
fear(0)
{

}

empathy::EmotionVector::EmotionVector(cJSON *vector)
{
    happiness = (float) cJSON_GetObjectItem(vector, "happiness")->valuedouble;
    sadness = (float) cJSON_GetObjectItem(vector, "sadness")->valuedouble;
    disgust = (float) cJSON_GetObjectItem(vector, "disgust")->valuedouble;
    contempt = (float) cJSON_GetObjectItem(vector, "contempt")->valuedouble;
    anger = (float) cJSON_GetObjectItem(vector, "anger")->valuedouble;
    neutral = (float) cJSON_GetObjectItem(vector, "neutral")->valuedouble;
    fear = (float) cJSON_GetObjectItem(vector, "fear")->valuedouble;
    surprise = (float) cJSON_GetObjectItem(vector, "surprise")->valuedouble;
}

float empathy::EmotionVector::getHappiness() const {
    return happiness;
}

void empathy::EmotionVector::setHappiness(float happiness) {
    empathy::EmotionVector::happiness = happiness;
}

float empathy::EmotionVector::getSadness() const {
    return sadness;
}

void empathy::EmotionVector::setSadness(float sadness) {
    empathy::EmotionVector::sadness = sadness;
}

float empathy::EmotionVector::getContempt() const {
    return contempt;
}

void empathy::EmotionVector::setContempt(float contempt) {
    empathy::EmotionVector::contempt = contempt;
}

float empathy::EmotionVector::getDisgust() const {
    return disgust;
}

void empathy::EmotionVector::setDisgust(float disgust) {
    empathy::EmotionVector::disgust = disgust;
}

float empathy::EmotionVector::getFear() const {
    return fear;
}

void empathy::EmotionVector::setFear(float fear) {
    empathy::EmotionVector::fear = fear;
}

float empathy::EmotionVector::getNeutral() const {
    return neutral;
}

void empathy::EmotionVector::setNeutral(float neutral) {
    empathy::EmotionVector::neutral = neutral;
}

float empathy::EmotionVector::getSurprise() const {
    return surprise;
}

void empathy::EmotionVector::setSurprise(float surprise) {
    empathy::EmotionVector::surprise = surprise;
}

float empathy::EmotionVector::getAnger() const {
    return anger;
}

void empathy::EmotionVector::setAnger(float anger) {
    empathy::EmotionVector::anger = anger;
}

bool empathy::EmotionVector::isHappy() const {
    return empathy::EmotionVector::happiness>0.7;
}
