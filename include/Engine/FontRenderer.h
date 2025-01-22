#pragma once

#include <grrlib.h>

#include "Types/Vector2.h"

#define BLACK   0x000000FF
#define MAROON  0x800000FF
#define GREEN   0x008000FF
#define OLIVE   0x808000FF
#define NAVY    0x000080FF
#define PURPLE  0x800080FF
#define TEAL    0x008080FF
#define GRAY    0x808080FF
#define SILVER  0xC0C0C0FF
#define RED     0xFF0000FF
#define LIME    0x00FF00FF
#define YELLOW  0xFFFF00FF
#define BLUE    0x0000FFFF
#define FUCHSIA 0xFF00FFFF
#define AQUA    0x00FFFFFF
#define WHITE   0xFFFFFFFF

namespace GDWii {
    class FontRenderer {
    public:
        FontRenderer() = default;

        void printToScreen(Vector2* position, GRRLIB_ttfFont* font, char* text, int fontSize, u32 color);
    };
}