#include "Game.h"

#include <stdlib.h>

#include <grrlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>

#include "FreeMonoBold_ttf.h"

namespace GDWii {
    void Game::start() {
        GRRLIB_Init();
        WPAD_Init();

        FontRenderer* fontRenderer = new FontRenderer();

        GRRLIB_ttfFont* font = GRRLIB_LoadTTF(FreeMonoBold_ttf, FreeMonoBold_ttf_size);
        
        while(1) {
            WPAD_ScanPads();
            u32 wPadDown = WPAD_ButtonsDown(0);
            u32 wPadHeld = WPAD_ButtonsHeld(0);

            if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break;

            this->fontRenderer->printToScreen(new Vector2(200.f, 200.f), font, "Hello world!!", 24, LIME);

            GRRLIB_Render();
        }

        GRRLIB_Exit();
        exit(0);
    }
}