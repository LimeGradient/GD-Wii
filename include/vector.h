#ifndef VECTOR_H
#define VECTOR_H

#include <gccore.h>

namespace GDWii
{
    class Vector {
    public:
        float x;
        float y;
        Vector(float posX, float posY) {
            x = posX;
            y = posY;
        }
        Vector() = default;

        guVector GDVectorToGUVector(Vector vector) {
            guVector vec = {vector.x, vector.y, 0.0f};
            return vec;
        }
    };
} // namespace GDWii


#endif