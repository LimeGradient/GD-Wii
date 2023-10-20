// Standard C/C++ Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

// Wii Includes
#include <grrlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <ogc/tpl.h>
#include <fat.h>

// Image Includes
#include "player_png.h"
#include "GJ_square02_png.h"

typedef struct {
	float x;
	float y;
}vector2;

vector2 Vector2(float x, float y) {
	vector2 _vector2;
	_vector2.x = x;
	_vector2.y = y;
	return _vector2;
}

typedef struct {
	vector2 position;
	vector2 scale;
	vector2 pivot;
	float rotation;
	bool hasCollision;
	bool isTrigger;
	GRRLIB_texImg* image;
}object;
//Struct of vector2, called whenever delcaring variable of vector2.

object NewObject(GRRLIB_texImg* image,vector2 position, vector2 scale, vector2 pivot = Vector2(0, 0), float rotation = 0, bool hasCollision = true, bool isTrigger = false) {
	object _object;
	_object.image = image;
	_object.position = position;
	_object.scale = scale;
	_object.pivot = pivot;
	_object.rotation = rotation;
	_object.hasCollision = hasCollision;
	_object.isTrigger = isTrigger;
	return _object;
}

vector2 GetPosition(object Object) {
	return Vector2(Object.position.x, Object.position.y);
}
//Call to set a vector2 x and y at the same time.

int main(int argc, char* argv[]) {
	ir_t ir1;

	GRRLIB_Init();
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

	GRRLIB_texImg* test_png = GRRLIB_LoadTexturePNG(player_png);

	vector2 velocity = Vector2(5, 5);
	vector2 position = Vector2(0, 0);
	position.x = 0;
	position.y = 0;

	object Player = NewObject(test_png,Vector2(0, 0), Vector2(0.5, 0.5));
	while (1) {
		WPAD_SetVRes(0, 640, 480);
		WPAD_ScanPads();
		u32 wpaddown = WPAD_ButtonsDown(0);
		u32 wpadheld = WPAD_ButtonsHeld(0);
		WPAD_IR(WPAD_CHAN_0, &ir1);

		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break; // Draw after this
		GRRLIB_FillScreen(0x000000FF);
		GRRLIB_Rectangle(0, 430, 640, 50, 0xFFFFFFFF, true);
		GRRLIB_DrawImg((int)Player.position.x, (int)Player.position.y, Player.image, 0, 1, 1, 0xFFFF00FF);
		
		GRRLIB_Render();
	}
	GRRLIB_Exit();
	exit(0);
}