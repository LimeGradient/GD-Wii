// Standard C/C++ Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <list>

// Wii Includes
#include <grrlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <ogc/tpl.h>
#include <fat.h>

#include "images.h"

// Custom Includes
#include "font_renderer.h"
#include "vector.h"

int main(int argc, char* argv[]) {
	ir_t ir1;

	GRRLIB_Init();
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

	GRRLIB_ttfFont* freeMonoBold = GRRLIB_LoadTTF(FreeMonoBold_ttf, FreeMonoBold_ttf_size);

	GDWii::FontRenderer fontRenderer = GDWii::FontRenderer();

	srand(time(NULL));

	while (1) {
		WPAD_SetVRes(0, 640, 480);
		WPAD_ScanPads();
		u32 wpaddown = WPAD_ButtonsDown(0);
		u32 wpadheld = WPAD_ButtonsHeld(0);
		WPAD_IR(WPAD_CHAN_0, &ir1);

		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break; // Draw after this
		GRRLIB_FillScreen(0x000000FF);
		fontRenderer.RenderToScreen(GDWii::Vector(200, 200), freeMonoBold, "Hello Font Renderer", 24, 0xB30F15 | 0xF);

		GRRLIB_Render();
	}
	GRRLIB_Exit();
	exit(0);
}