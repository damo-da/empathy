#ifndef EMPATHY_TEXT_SHADER_H
#define EMPATHY_TEXT_SHADER_H


#include <GL/glew.h>
#include <iostream>
#include <vector>
#include "../Utils/Color.h"
#include "../global.h"

namespace empathy {
    namespace shader {

        /* The Default Shader of drawing OpenGL diagrams.
         *
         */
        class TextShader {
        public:
            static GLuint shaderProgram;

            /* Initialize the shader.
             *
             * Called while init() of the You or Empathy class.
             *
             * Compile shaders and create the program.
             */
            static void init();

            /* Activate this shader on OpenGL.
             *
             */
            static void use();

            static void flush();

            /* Set the color of the text. */
            static void setTextColor(Color *color);
        };
    }
}
#endif //EMPATHY_TEXT_SHADER_H
