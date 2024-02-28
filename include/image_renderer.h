#ifndef IMAGE_RENDERER_H
#define IMAGE_RENDERER_H

#include <grrlib.h>

#include "vector.h"

namespace GDWii {
    class ImageRenderer {
    public:
        void RenderImage(GRRLIB_texImg* img, GDWii::Vector position, float rotationAngle, GDWii::Vector scale, u32 color) {
            GRRLIB_DrawImg(position.x, position.y, img, rotationAngle, scale.x, scale.y, color);
        }
    };
}

#endif