#include <stdio.h>
#include <stdlib.h>

#include <grrlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>

#include "FreeMonoBold_ttf.h"

int main(int argc, char* argv[]) {
    GRRLIB_Init();
    WPAD_Init();

    GRRLIB_ttfFont* font = GRRLIB_LoadTTF(FreeMonoBold_ttf, FreeMonoBold_ttf_size);
    
    while(1) {
        WPAD_ScanPads();
        u32 wPadDown = WPAD_ButtonsDown(0);
        u32 wPadHeld = WPAD_ButtonsHeld(0);

        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break;

        GRRLIB_PrintfTTF(200, 200, font, "hello world!", 24, 0xFFFFFFFF);

        GRRLIB_Render();
    }

    GRRLIB_Exit();
    exit(0);
}