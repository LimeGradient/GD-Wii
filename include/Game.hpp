#pragma once

#include "Engine/FontRenderer.hpp"

namespace GDWii {
    class Game {
    public:
        static Game* get() {
            static Game* instance;
            return instance;
        }

        void start();
        
        FontRenderer* fontRenderer = new FontRenderer();
    };
}