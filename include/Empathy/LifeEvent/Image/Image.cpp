//
// Created by geek on 4/16/16.
//

#include <cstring>
#include "Image.h"
#include "../../Libs/lodepng/lodepng.h"
#include "../../global.h"

using namespace std;


empathy::life_event::Image::Image() :
        LifeEvent(),
        image(),
        width(),
        height(),
        u3(),
        v3()
{

}


void empathy::life_event::Image::draw() {

    // Draw the texture on a quad, using u3 and v3 to correct non power of two texture size.
    glBegin(GL_QUADS);
    glTexCoord2d( 0,  0); glVertex2f(    0,      0);
    glTexCoord2d(u3,  0); glVertex2f(width,      0);
    glTexCoord2d(u3, v3); glVertex2f(width, height);
    glTexCoord2d( 0, v3); glVertex2f(    0, height);
    glEnd();

    std::cout<<"IMAGE DRAWING"<<std::endl;
    cout<<"U3, V3 are "<<u3<<" and "<<v3<<endl;
    cout<<"width, height are "<<width<<" and "<<height<<endl;


}


void empathy::life_event::Image::onCreate(GLfloat delTime) {
    LifeEvent::onCreate(delTime);
}

void empathy::life_event::Image::onRun(GLfloat delTime) {

}

void empathy::life_event::Image::onFinish(GLfloat delTime) {
    LifeEvent::onFinish(delTime);
}

void empathy::life_event::Image::onInit() {
    LifeEvent::onInit();

    unsigned int w,h;
    std::string realPath=getAssetPath("img/linux.png");

    const char * path=realPath.c_str();

    lodepng::decode(image,w,h,path);

    width=w;height=h;

    if(width>300)width=300;
    if(height>300)height=300;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Make some OpenGL properties better for 2D and enable alpha channel.
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);


    // Texture size must be power of two for the primitive OpenGL version this is written for. Find next power of two.
    size_t u2 = 1; while(u2 < width) u2 *= 2;
    size_t v2 = 1; while(v2 < height) v2 *= 2;
    // Ratio for power of two version compared to actual version, to render the non power of two image with proper size.
    u3 = (double)width / u2;
    v3 = (double)height / v2;

    // Make power of two version of the image.
    std::vector<unsigned char> image2(u2 * v2 * 4);
    for(size_t y = 0; y < height; y++)
        for(size_t x = 0; x < width; x++)
            for(size_t c = 0; c < 4; c++)
            {
                image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];
            }

    // Enable the texture for OpenGL.
    glEnable(GL_TEXTURE_2D);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image2[0]);

    bool done = false;

    glColor4ub(255, 255, 255, 255);

    u3=0.1;
    v3=0.1;
}


void empathy::life_event::Image::onDestroy() {
    LifeEvent::onDestroy();
}



