#ifndef VECTOR_H
#define VECTOR_H

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
    };
} // namespace GDWii


#endif