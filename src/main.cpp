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

typedef struct {
	float x;
	float y;
}vector2;
//Struct of vector2, called whenever delcaring variable of vector2.

vector2 Vector2(float x, float y) {
	vector2 _vector2;
	_vector2.x = x;
	_vector2.y = y;
	return _vector2;
}
//Call to set a vector2 x and y at the same time.

int main(int argc, char* argv[]) {
	ir_t ir1;

	GRRLIB_Init();
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
	
	GRRLIB_texImg *test_png = GRRLIB_LoadTexturePNG(player_png);

	vector2 velocity = Vector2(5,5);
	vector2 position = Vector2(0,0);
	position.x = 0;
	position.y = 0;
	while (1) {
		WPAD_SetVRes(0,640,480);
		WPAD_ScanPads();
		u32 wpaddown = WPAD_ButtonsDown(0);
        u32 wpadheld = WPAD_ButtonsHeld(0);
		WPAD_IR(WPAD_CHAN_0, &ir1);

		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break; // Draw after this
		GRRLIB_FillScreen(0x000000FF); 
		GRRLIB_Rectangle(0,430,640,50, 0xFFFFFFFF,true);
		GRRLIB_DrawImg((int)position.x, (int)position.y,test_png,0,1,1,0xFFFF00FF);
		position.x += velocity.x;
		position.y += velocity.y;
		GRRLIB_Render();
	}
	GRRLIB_Exit();
	exit(0);
}