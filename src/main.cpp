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

// Image Includes
#include "player_png.h"
#include "GJ_square02_png.h"

typedef struct {
	float x;
	float y;
}vector2;

typedef struct {
	vector2 New(float x, float y) {
		vector2 _vector2;
		_vector2.x = x;
		_vector2.y = y;
		return _vector2;
	}
	vector2 Add(vector2 first, vector2 second) {
		vector2 _vector2 = first;
		_vector2.x += second.x;
		_vector2.y += second.y;
		return _vector2;
	}
}Vector2Functions;
Vector2Functions Vector2;
typedef struct {
	vector2 position;
	vector2 imgScale;
	vector2 pivot;
	float rotation;
	bool hasCollision;
	bool isTrigger;
	GRRLIB_texImg* image;
	vector2 hitboxVal1;
	vector2 hitboxVal2;
	int collisionType;

}object;

std::list<object> objectList = {};

typedef struct {
	object New(GRRLIB_texImg* image, vector2 position, vector2 hitboxVal1, vector2 hitboxVal2, int collisionType = 0, vector2 imgScale = Vector2.New(1,1), vector2 pivot = Vector2.New(0, 0), float rotation = 0, bool hasCollision = true, bool isTrigger = false) {
		object _object;
		_object.image = image;
		_object.position = position;
		_object.imgScale = imgScale;
		_object.pivot = pivot;
		_object.rotation = rotation;
		_object.hasCollision = hasCollision;
		_object.isTrigger = isTrigger;
		_object.hitboxVal1 = hitboxVal1;
		_object.hitboxVal2 = hitboxVal2;
		_object.collisionType = collisionType;
	    objectList.push_back(_object);
		return _object;
	}

}ObjectFunctions;
ObjectFunctions Object;

void ObjectChecks(object player) {
	for(object obj : objectList)
	{
		GRRLIB_DrawImg((int)obj.position.x, (int)obj.position.y, obj.image, 0, obj.imgScale.x, obj.imgScale.y, 0xFFFFFFFF);
	}
}

int main(int argc, char* argv[]) {
	ir_t ir1;

	GRRLIB_Init();
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

	GRRLIB_texImg* test_png = GRRLIB_LoadTexturePNG(player_png);
	GRRLIB_texImg* test_ground_png = GRRLIB_LoadTexturePNG(GJ_square02_png);


	vector2 velocity = Vector2.New(5, 5);

	object Player = Object.New(test_png, Vector2.New(0, 0), Vector2.New(0, 0), Vector2.New(20, 20));

	object TestGround = Object.New(test_ground_png, Vector2.New(0, 430), Vector2.New(0, 0), Vector2.New(80, 80));

	while (1) {
		WPAD_SetVRes(0, 640, 480);
		WPAD_ScanPads();
		u32 wpaddown = WPAD_ButtonsDown(0);
		u32 wpadheld = WPAD_ButtonsHeld(0);
		WPAD_IR(WPAD_CHAN_0, &ir1);

		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break; // Draw after this
		GRRLIB_FillScreen(0x000000FF);

		Player.position = Vector2.Add(Player.position, velocity);

		ObjectChecks(Player);
		//GRRLIB_Rectangle(0, 430, 640, 50, 0xFFFFFFFF, true);
		//GRRLIB_DrawImg((int)Player.position.x, (int)Player.position.y, Player.image, 0, Player.scale.x, Player.scale.y, 0xFFFFFFFF);
		//GRRLIB_DrawImg((int)TestGround.position.x, (int)TestGround.position.y, TestGround.image, 0, TestGround.scale.x, TestGround.scale.y, 0xFFFFFFFF);

		GRRLIB_Render();
	}
	GRRLIB_Exit();
	exit(0);
}