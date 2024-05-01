#ifndef PLAYER_H
#define PLAYER_H

#include "image_renderer.h"

namespace GDWii {
    class Player {
    public:
        GDWii::Vector position = GDWii::Vector(200.f, 0.f);
        GDWii::Vector velocity = GDWii::Vector(200.f, 0.f);
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
            imageRenderer.RenderImage(sprite.image, position, sprite.rotationAngle, sprite.scale, sprite.color);
            // velocity.x += 2.5f;

            if (onGround || position.y >= 300)
                this->SetGravity(.5f);
            if (position.y >= 380) { // Hardcoded Y Ground Value goes BRRRRR
                position.y = 380;
                onGround = true;
            }
        }

        /*
        BEWARE
        I have no fucking clue how jumping works
        it just does
        do NOT fuck with anything here
        */

        void SetGravity(float modifier) {
            position.y += velocity.y;
            grav = modifier;

            if (position.y <= 300) velocity.y = velocity.y * -1;
        }

        void useVelocity() {
            position.y += velocity.y;
        }

        void Jump() {
            if (onGround) {
                float jumpVel = 2.f;
                velocity.y -= jumpVel;
                onGround = false;
            }
        }
    };
}

#endif