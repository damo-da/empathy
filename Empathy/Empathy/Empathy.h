#ifndef EMPATHY
#define EMPATHY

#include <GL/glew.h>

#include "../e.h"

#include "../RadioStation/BroadcastStation.h"

#include <vector>
namespace empathy{

    class Empathy{
    public:
        empathy::moonlight::MoonLight * moonLight;

        virtual GLfloat  getTime()=0;
        virtual void terminate()=0;
        virtual void run()=0;


        //init the cross-platform system ready.
        virtual void init();

        //The constructor
        Empathy();

        void setMoonLight(empathy::moonlight::MoonLight *m){moonLight=m;}

        void loop();

        void setScreenSize(int,int);

        void flush();

        empathy::You * you;

        static empathy::radio::BroadcastStation broadcastStation;

        void addBrain(empathy::brain::Brain * brain);


        const std::vector<empathy::brain::Brain *> &getBrains() const {
            return brains;
        }

        std::vector<empathy::brain::Brain *> brains;

    private:
        //Screen Size
        uint sc_size_x,sc_size_y;

        void initGlew();
        void initShaders();
        void initGL();
        void initYou();
    };

}

#endif