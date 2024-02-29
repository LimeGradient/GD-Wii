#ifndef PLAYER_H
#define PLAYER_H

#include "image_renderer.h"

namespace GDWii {
    class Player {
    public:
        GDWii::Vector velocity;
        GDWii::Sprite sprite;
        Player(GDWii::Sprite spr) {
            sprite = spr;
        }
        Player() = default;
        void Init(GDWii::ImageRenderer imageRenderer) { 
            imageRenderer.RenderImage(sprite.image, velocity, sprite.rotationAngle, sprite.scale, sprite.color);
        }
    };
}

#endif