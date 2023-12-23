#ifndef SPRITELOADING_H
#define SPRITELOADING_H

#include <grrlib.h>
#include "Object.h"

namespace SpriteLoading {
    void SetSprite(object obj, GRRLIB_texImg* img) {
        obj.image = img;
    }
}

#endif