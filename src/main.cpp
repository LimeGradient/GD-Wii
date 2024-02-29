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
#include "image_renderer.h"
#include "vector.h"
#include "player.h"

int main(int argc, char* argv[]) {
	ir_t ir1;

	GRRLIB_Init();
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

	GDWii::Sprite playerSprite = GDWii::Sprite(GRRLIB_LoadTexturePNG(player2_png), GDWii::Vector(100, 100), 0, GDWii::Vector(1, 1), WHITE); // The Player Sprite
	GDWii::Sprite backgroundSprite = GDWii::Sprite(GRRLIB_LoadTexturePNG(background_png), GDWii::Vector(50, 50), 0, GDWii::Vector(1, 1), WHITE); // The Background Sprite
	GRRLIB_ttfFont* freeMonoBold = GRRLIB_LoadTTF(FreeMonoBold_ttf, FreeMonoBold_ttf_size);

	GDWii::FontRenderer fontRenderer = GDWii::FontRenderer();
	GDWii::ImageRenderer imageRenderer = GDWii::ImageRenderer();
	GDWii::Player player = GDWii::Player(playerSprite);

	srand(time(NULL));

	while (1) {
		ir_t ir;
		WPAD_SetVRes(0, 640, 480);
		WPAD_ScanPads();
		u32 wpaddown = WPAD_ButtonsDown(0);
		u32 wpadheld = WPAD_ButtonsHeld(0);
		WPAD_IR(WPAD_CHAN_0, &ir);

		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break; // Draw after this
		GRRLIB_FillScreen(0x000000FF);
		imageRenderer.RenderImage(backgroundSprite); // Leave this in the very back of code so everything gets rendered in front

		fontRenderer.RenderToScreen(GDWii::Vector(200, 200), freeMonoBold, "GD but on the Wii", 24, WHITE);
		player.Init(imageRenderer); // Quick way to move player
		player.velocity.x += 3.0f;
		player.SetGravity(3);
		imageRenderer.PlotWiimoteIR(ir, LIME); // Make a square where the wii cursor is

		GRRLIB_Render();
	}
	GRRLIB_Exit();
	exit(0);
}