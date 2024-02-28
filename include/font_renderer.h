#ifndef FONT_RENDERER_H
#define FONT_RENDERER_H

#include <grrlib.h>
#include <string>

#include "vector.h"

namespace GDWii {
    class FontRenderer {
    public:
        void RenderToScreen(GDWii::Vector position, GRRLIB_ttfFont* font, std::string text, int fontSize, u32 color) {
            GRRLIB_PrintfTTF(position.x, position.y, font, text.c_str(), fontSize, color);
        }
    };
}

#endif