//
// Created by bad on 11/3/16.
//

#ifndef DEMPATHY_LINEAR_TEXT_H
#define DEMPATHY_LINEAR_TEXT_H

#include "../../empathy.h"
#include "../LifeEvent.h"
#include "../../Utils/Color.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include "glm/glm.hpp"
#include "../../Shader/TextShader.h"

namespace empathy{
    namespace life_event{
        class Text : public LifeEvent, public Color{
           struct Character {
                GLuint     TextureID;  // ID handle of the glyph texture
                glm::ivec2 Size;       // Size of glyph
                glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
                GLuint     Advance;    // Offset to advance to next glyph
            };

            static FT_Library ft;
            static FT_Face face;
            std::map<GLchar, Character> Characters;
            static bool initialized;

            GLuint VAO, VBO;

            void RenderText(std::string text, GLfloat scale);

            void initializeResources();

            glm::vec2 getTextLength(std::string text, GLfloat scale);

            GLfloat centerX, centerY;

        public:
            Text();

            virtual void onDestroy() override;

            virtual void onInit() override;

            virtual void draw() override;

        protected:
            virtual void onCreate(GLfloat delTime) override;

            virtual void onRun(GLfloat delTime) override;

            virtual void onFinish(GLfloat delTime) override;

        public:
            virtual void decodeJson(std::string key, cJSON *value) override;
        };

    }
}


#endif //DEMPATHY_LINEAR_TEXT_H
