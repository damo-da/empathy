#include "Font.h"
using namespace std;


int empathy::Font::load(std::string fontfile) {
    if (initialized) return 0;

    initialize();

    ft = new FT_Library();
    face = new FT_Face();

    cout << "Loading font " << fontfile<<endl;

    if (FT_Init_FreeType(ft))
    {
        std::cerr << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
        return 1;
    }

    if (int error=FT_New_Face(*ft, fontfile.c_str(), 0, face))
    {
        std::cerr << "ERROR::FREETYPE: Failed to load font " << error << std::endl;

        return 2;
    }

    FT_Set_Pixel_Sizes(*face, 0, 50);

    if (FT_Load_Char(*face, 'X', FT_LOAD_RENDER))
    {
        std::cerr << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;

        return 3;
    }

    initialized = true;
}

void empathy::Font::flush() {

    if(!initialized) return;

    FT_Done_Face(*face);

    FT_Done_FreeType(*ft);

    delete face;
    delete ft;

    cout << "Fonts flushed" << endl;
}

FT_Face * empathy::Font::face = 0;
FT_Library * empathy::Font::ft = 0;
bool empathy::Font::initialized = false;

void empathy::Font::initialize() {









}
