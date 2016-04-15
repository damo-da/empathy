//
// Created by damo on 1/31/16.
//

#ifndef EMPATHY_SHADER_H
#define EMPATHY_SHADER_H


#include <GL/glew.h>
#include <iostream>
#include <vector>
#include "../Utils/Color.h"
#include "../empathy.h"

namespace empathy {
    namespace shader {

        /* The Default Shader of drawing OpenGL diagrams.
         *
         */
        class DefaultShader {
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

            /* Set the color of the fragmentColor. */
            static void setVertexColor(Color *color);
        };
    }
}
#endif //EMPATHY_SHADER_H
