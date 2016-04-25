#include "MathWave_FromString.h"

GLfloat empathy::life_event::MathWave_FromString::getY(GLfloat theta) {
    yParser.DefineConst("time",theta);
    return (GLfloat) (yParser.Eval());
}

GLfloat empathy::life_event::MathWave_FromString::getX(GLfloat theta) {
    xParser.DefineConst("time",theta);
    return (GLfloat) (xParser.Eval());
}


empathy::life_event::MathWave_FromString::MathWave_FromString() :
        MathWave(),
        xParser(),
        yParser()
{

    //by default, x = time
    xParser.SetExpr("time");
    yParser.SetExpr("time");
}

void empathy::life_event::MathWave_FromString::decodeJson(const std::string key, cJSON *value) {
    MathWave::decodeJson(key, value);

    if(key=="mathwave_x"){
        xParser.SetExpr(value->valuestring);
    }else if(key=="mathwave_y"){
        yParser.SetExpr(value->valuestring);
    }else{
        //add constants
        if(key.find("mathwave_")==0){
            unsigned long prefixLength=std::string("mathwave_").size();
            std::string cat(key);
            cat.erase(0,prefixLength);

            xParser.DefineConst(cat,value->valuedouble);
            yParser.DefineConst(cat,value->valuedouble);
        }
    }
}