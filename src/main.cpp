#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <grrlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <ogc/tpl.h>
#include <fat.h>

#include "player_png.h"
#include "GJ_square02_png.h"

int main(int argc, char* argv[]) {
	ir_t ir1;

	GRRLIB_Init();
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
	
	GRRLIB_texImg *test_png = GRRLIB_LoadTexturePNG(GJ_square02_png);

	while (1) {
		WPAD_SetVRes(0,640,480);
		WPAD_ScanPads();
		u32 wpaddown = WPAD_ButtonsDown(0);
        u32 wpadheld = WPAD_ButtonsHeld(0);
		WPAD_IR(WPAD_CHAN_0, &ir1);

		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break; // Draw after this
		GRRLIB_FillScreen(0x000000FF); 
		GRRLIB_DrawImg(10,50,test_png,0,1,1,0xFFFF00FF);
		GRRLIB_Plot(ir1.sx, ir1.sy, 0xFFFF00FF);
        GRRLIB_Plot(ir1.sx + 1, ir1.sy, 0xFFFF00FF);
        GRRLIB_Plot(ir1.sx, ir1.sy + 1, 0xFFFF00FF);
        GRRLIB_Plot(ir1.sx + 1, ir1.sy + 1, 0xFFFF00FF);
		GRRLIB_Render();
	}
	GRRLIB_Exit();
	exit(0);
}