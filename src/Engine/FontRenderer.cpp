#include "Engine/FontRenderer.h"
#include "FontRenderer.h"

namespace GDWii {
    void FontRenderer::printToScreen(Vector2* position, GRRLIB_ttfFont* font, char* text, int fontSize, u32 color) {
        GRRLIB_PrintfTTF(position->x, position->y, font, text, fontSize, color);
    }
}