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
        /*
        Initialize the Player Object
        @param imageRenderer The Image Renderer
        */
        void Init(GDWii::ImageRenderer imageRenderer) { 
            imageRenderer.RenderImage(sprite.image, velocity, sprite.rotationAngle, sprite.scale, sprite.color);
        }

        void SetGravity(float modifier) {
            velocity.y += modifier;
        }
        
        void CheckCollisions(GDWii::ImageRenderer imageRenderer) {
            for (GDWii::Sprite s : imageRenderer.sprites) {
                if (sprite.position.y == s.position.y) {
                    sprite.position.y = s.position.y;
                }
            }
        }
    };
}

#endif