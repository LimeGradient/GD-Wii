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
            velocity.x = 200; 
            imageRenderer.RenderImage(sprite.image, velocity, sprite.rotationAngle, sprite.scale, sprite.color);

            this->SetGravity(1.5);
            if (velocity.y >= 381) { // Hardcoded Y Ground Value goes BRRRRR
                velocity.y = 380;
                onGround = true;
            }
        }

        void SetGravity(float modifier) {
            velocity.y += modifier;
            grav = modifier;
        }

        void Jump() {
            if (onGround) {
                velocity.y -= grav * 36;
                onGround = false;
            }
        }
    };
}

#endif