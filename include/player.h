#ifndef PLAYER_H
#define PLAYER_H

#include "image_renderer.h"

namespace GDWii {
    class Player {
    public:
        GDWii::Vector velocity;
        GDWii::Sprite sprite;
        float grav;
        bool onGround;
        Player(GDWii::Sprite spr) {
            sprite = spr;
        }
        Player() = default;
        /*
        Initialize the Player Object
        @param imageRenderer The Image Renderer
        */
        void Init(GDWii::ImageRenderer imageRenderer) { 
            imageRenderer.RenderImage(sprite.image, velocity, sprite.rotationAngle, sprite.scale, sprite.color);

            velocity.x += 2.f;

            if (velocity.y >= 381) { // Hardcoded Y Ground Value goes BRRRRR
                velocity.y = 378;
                onGround = true;
            }
        }

        void SetGravity(float modifier) {
            velocity.y += modifier;
            grav = modifier;
        }

        void Jump() {
            if (onGround) {
                velocity.y -= grav * 12;
                onGround = false;
            }
        }
    };
}

#endif