#ifndef DEMPATHY_LINEAR_FONT_H
#define DEMPATHY_LINEAR_FONT_H

#include <iostream>
#include <ft2build.h>
#include FT_FREETYPE_H

namespace empathy{
 class Font {


 public:
     static int load(std::string fontfile);

     static void flush();

     static void initialize();

     static FT_Face * getFace(){return face;}
 private:
     static FT_Library * ft;
     static FT_Face * face;

     static bool initialized;
};

}


#endif //DEMPATHY_LINEAR_FONT_H
