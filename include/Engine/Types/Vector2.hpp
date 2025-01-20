#pragma once

#include <gccore.h>

namespace GDWii {
    class Vector2 {
    public:
        Vector2(float posX, float posY) {
            this->x = posX;
            this->y = posY;
        }

        guVector toGUVector() {
            guVector vec = {this->x, this->y, 0.0f};
            return vec;
        }

        float x, y;
    };
}