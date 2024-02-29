#ifndef IMAGE_RENDERER_H
#define IMAGE_RENDERER_H

#include <grrlib.h>
#include <wiiuse/wpad.h>

#include "vector.h"
#include "font_renderer.h"

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
        Sprite() = default;
    };

    class ImageRenderer {
    public:
        /*
        Render a Image to the Screen
        @param sprite The Sprite Object to Render
        */
        void RenderImage(GDWii::Sprite sprite) {
            GRRLIB_DrawImg(sprite.position.x, sprite.position.y, sprite.image, sprite.rotationAngle, sprite.scale.x, sprite.scale.y, sprite.color);
        }
        /*
        Render a Image to the Screen
        @param img The Image to Render
        @param position Where the Image is placed on screen
        @param rotationAngle The angle at which the image is rotated
        @param scale The scale of the image (Set to 1, 1 by default)
        @param color The color filter of the image (Set to WHITE by default)
        */
        void RenderImage(GRRLIB_texImg* img, GDWii::Vector position, float rotationAngle, GDWii::Vector scale = GDWii::Vector(1, 1), u32 color = WHITE) {
            GRRLIB_DrawImg(position.x, position.y, img, rotationAngle, scale.x, scale.y, color);
        }
        /*
        Render the WiiMote IR Cursor on Screen
        @param ir The IR Controller
        @param color The color of the Cursor
        */
        void PlotWiimoteIR(ir_t ir, u32 color) {
            GRRLIB_Plot(ir.sx, ir.sy, color);
            GRRLIB_Plot(ir.sx + 1, ir.sy, color);
            GRRLIB_Plot(ir.sx, ir.sy + 1, color);
            GRRLIB_Plot(ir.sx + 1, ir.sy + 1, color);
        }
    };
}

#endif