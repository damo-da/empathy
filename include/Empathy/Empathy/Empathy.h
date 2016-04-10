#ifndef EMPATHY
#define EMPATHY

#include <GL/glew.h>
#include "../empathy.h"
#include "../RadioStation/BroadcastStation.h"

#include <vector>
namespace empathy{

    /* The base application independent of all any flavors.
     *
     * So how'd your own flavor?
     * 1. Override this class.
     * 3. override getTime() to return a time
     * 4. override the terminate() to call upon the termination
     * 5. override the run() function. This function is used to begin the app at user's will.
     *
     * Now, let's call your flavor `Salamander`.
     * You'd want to
     *
     *     Salamander * sal=new Salamander();
     *     JSONBrain * brain= new JSONBrian("instructions_file.json");
     *     brain->addTo(sal);
     *     sal->run();
     *
     * in your `main()` function.
     *
     * If you want the audio, set the <MoonLight> using <setMoonLight()> method on your `Salamander`.
     * *NOTE*: you can't directly play the audio using <MoonLight>. See <MoonLight> for more info.
     */
    class Empathy{
    protected:
        /* Gets the current time for the game. */
        virtual GLfloat  getTime()=0;


        /* Terminator. More like destructor, but a terminator. */
        virtual void flush();
    public:
        /* The method called to activate <Empathy>. */
        virtual void run()=0;

        /* The constructor. */
        Empathy();

        /* Adds a brain to the Empathy app.
         *
         * Deprecated to use this method directly.
         * Recommended to use brain->addTo(empathy).
         *
         * Call this function from the overridden addTo() method on the brain only.
         */
        void addBrain(brain::Brain * brain);


        GLuint getScreenSize() const {
            return sc_size;
        }

        GLuint getMarginTop() const {
            return marginTop;
        }

        GLuint getMarginLeft() const {
            return marginLeft;
        }

        /* set the OpenGL screen sizes. */
        void setScreenSize(int);

        /* set the OpenGL screen margins. */
        void setScreenMargins(int,int);

    protected:

        /* init the flavor-independent system ready. */
        virtual void init();

        /* Set the audio handler. For more information, see <MoonLight>. */
        void setMoonLight(moonlight::MoonLight *m){moonLight=m;}

        /* The gameloop.
         *
         * **Warning:** Loop only. Does not contain the `while (not gameOver)` condition.
         * Just the code inside the `while` loop.
         * */
        virtual void loop();

    public:
        virtual bool shouldClose(){
            return _shouldClose;
        }
        void makeReadyToClose(){
            _shouldClose=true;
        }
    private:
        bool _shouldClose;

    private:
        /* Get all brains added in the instance.
         *
         * Called from the init() function to add brains to the <You> instance.
         */
        const std::vector<brain::Brain *> &getBrains() const {
            return brains;
        }

        /* User added <Brain> instances.*/
        std::vector<brain::Brain *> brains;

        /* the audio controller */
        moonlight::MoonLight * moonLight;

        /* The OpenGL Screen Size. */
        GLuint sc_size;
        GLuint marginTop,marginLeft;

        /* Initialize GLEW */
        void initGlew();

        /* Initialize the shaders.
         *
         * (More like: create the shaders).
         * */
        void initShaders();

        /* Initialize OpenGL. */
        void initGL();

        /* Initialize the <You> instance. */
        void initYou();

        /* The <You>, the virtual friend who connects with the user. */
        empathy::You * you;

    public:
        static Empathy *instance;

        static Empathy * getInstance(){return instance;}
    };

}

#endif