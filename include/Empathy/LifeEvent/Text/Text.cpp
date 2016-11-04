//
// Created by bad on 11/3/16.
//

#include "Text.h"
#include <iostream>

using namespace std;

empathy::life_event::Text::Text() :
        LifeEvent(),
        Color(0.5f, 0.8f, 0.2f, 0.8f),
        centerX(0.0f),
        centerY(0.0f)
{

}

void empathy::life_event::Text::onDestroy() {
    LifeEvent::onDestroy();

    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}

void empathy::life_event::Text::onInit() {
    LifeEvent::onInit();

    initializeResources();
}

void empathy::life_event::Text::onCreate(GLfloat delTime) {
    LifeEvent::onCreate(delTime);
}

void empathy::life_event::Text::onRun(GLfloat delTime) {
//    centerX += 0.001f;
}

void empathy::life_event::Text::onFinish(GLfloat delTime) {
    LifeEvent::onFinish(delTime);
}

void empathy::life_event::Text::draw() {
    shader::TextShader::use();

    RenderText("This is sample text", 0.002f);
}

void empathy::life_event::Text::RenderText(std::string text, GLfloat scale) {
    empathy::shader::TextShader::use();

    GLfloat x = centerX;
    GLfloat y = centerY;

    glm::vec2 length = getTextLength(text, scale);

    x -= length.x /2;
    y -= length.y /2;

    shader::TextShader::setTextColor(this);

    glBindVertexArray(VAO);

    // Iterate through all characters
    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++)
    {
        Character ch = Characters[*c];

        GLfloat xpos = x + ch.Bearing.x * scale;
        GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

        GLfloat w = ch.Size.x * scale;
        GLfloat h = ch.Size.y * scale;
        // Update VBO for each character
        GLfloat vertices[6][4] = {
                { xpos,     ypos + h,   0.0, 0.0 },
                { xpos,     ypos,       0.0, 1.0 },
                { xpos + w, ypos,       1.0, 1.0 },

                { xpos,     ypos + h,   0.0, 0.0 },
                { xpos + w, ypos,       1.0, 1.0 },
                { xpos + w, ypos + h,   1.0, 0.0 }
        };
        // Render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        // Update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // Render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        x += (ch.Advance >> 6) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

FT_Library empathy::life_event::Text::ft = 0;
FT_Face empathy::life_event::Text::face = 0;
//std::map<GLchar, empathy::life_event::Text::Character> empathy::life_event::Text::Characters;
bool empathy::life_event::Text::initialized = false;

void empathy::life_event::Text::initializeResources() {
    if (initialized) {
        cout << "Font already initialized" << endl;
    }else{
        if (FT_Init_FreeType(&ft))
            std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

        string path = getAssetPath("fonts/FreeSans.ttf").c_str();
        if (int error=FT_New_Face(ft, path.c_str(), 0, &face))
            std::cout << "ERROR::FREETYPE: Failed to load font" << error << std::endl;

        FT_Set_Pixel_Sizes(face, 0, 50);

        if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;


        glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Disable byte-alignment restriction
    }

    for (GLubyte c = 0; c < 128; c++)
    {
        // Load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }
        // Generate texture
        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,
                GL_RED,
                GL_UNSIGNED_BYTE,
                face->glyph->bitmap.buffer
        );
        // Set texture options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // Now store character for later use
        Character character = {
                texture,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                (GLuint)face->glyph->advance.x
        };
        Characters.insert(std::pair<GLchar, Character>(c, character));
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    cout<<"font initialization complete"<<endl;

    initialized = true;
}

void empathy::life_event::Text::decodeJson(std::string key, cJSON *value) {
    LifeEvent::decodeJson(key, value);
    Color::decodeJson(key, value);

    if (key == "centerX"){
        centerX = (GLfloat) value->valuedouble;
    }else if(key == "centerY"){
        centerY = (GLfloat) value->valuedouble;
    }
}

glm::vec2 empathy::life_event::Text::getTextLength(std::string text, GLfloat scale) {
    glm::vec2 length;

    for (int i=0; i<text.length(); i++){
        Character mChar = Characters[text[i]];

        length.x += scale * mChar.Size.x;

        GLfloat thisY = mChar.Size.y * scale;
        length.y = (thisY > length.y) ? thisY : length.y;
    }
    return length;
}
