#ifndef IMAGE_RENDERER_H
#define IMAGE_RENDERER_H

#include <grrlib.h>
#include <wiiuse/wpad.h>

#include "vector.h"

namespace GDWii {
    class Sprite {
    public:
        GRRLIB_texImg* image;
        GDWii::Vector position;
        float rotationAngle;
        GDWii::Vector scale;
        u32 color;
        Sprite(GRRLIB_texImg* img, GDWii::Vector pos, float rot, GDWii::Vector sc, u32 col) {
            image = img;
            position = pos;
            rotationAngle = rot;
            scale = sc;
            color = col;
        }
    };

    class ImageRenderer {
    public:
        void RenderImage(GDWii::Sprite sprite) {
            GRRLIB_DrawImg(sprite.position.x, sprite.position.y, sprite.image, sprite.rotationAngle, sprite.scale.x, sprite.scale.y, sprite.color);
        }
        void RenderImage(GRRLIB_texImg* img, GDWii::Vector position, float rotationAngle, GDWii::Vector scale, u32 color) {
            GRRLIB_DrawImg(position.x, position.y, img, rotationAngle, scale.x, scale.y, color);
        }
        
    };
}

#endif