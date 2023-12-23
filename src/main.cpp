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
#include "player2_png.h"
#include "GJ_square02_png.h"

#include "FreeMonoBold_ttf.h"

// Other Includes
#include "Vector2.h"
#include "Object.h"
#include "SpriteLoading.h"

void ObjectChecks(object &player) {
	vector2 oldPos = player.position;
	for(auto &obj : objectList)
	{
		obj->position = Vector2.Add(obj->position, obj->velocity);
		if (obj->isPlayer == false) {
			switch (obj->collisionType) {
			case 1: //collision type 1 is a box
				if (obj->position.x + obj->hitboxVal1.x <= player.position.x + player.hitboxVal2.x && obj->position.x + obj->hitboxVal2.x >= player.position.x + player.hitboxVal1.x && obj->position.y + obj->hitboxVal1.y <= player.position.y + player.hitboxVal2.y && obj->position.y + obj->hitboxVal2.y >= player.position.y + player.hitboxVal1.y) {
					player.velocity = Vector2.New(0, 0);
				}
				break;
			}

		}
		GRRLIB_DrawImg((int)obj->position.x, (int)obj->position.y, obj->image, 0, obj->imgScale.x, obj->imgScale.y, 0xFFFFFFFF);
	}
}

int main(int argc, char* argv[]) {
	ir_t ir1;

	GRRLIB_Init();
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

	GRRLIB_texImg* test_png = GRRLIB_LoadTexturePNG(player_png);
	GRRLIB_texImg* test_png_2 = GRRLIB_LoadTexturePNG(player2_png);
	GRRLIB_texImg* test_ground_png = GRRLIB_LoadTexturePNG(GJ_square02_png);

	GRRLIB_ttfFont* testFont = GRRLIB_LoadTTF(FreeMonoBold_ttf, FreeMonoBold_ttf_size);

	object Player = Object.New(test_png, Vector2.New(0, 0), Vector2.New(0, 0), Vector2.New(20, 20));
	Player.velocity = Vector2.New(0, 5);
	Player.isPlayer = true;
	object TestGround = Object.New(test_ground_png, Vector2.New(0, 430), Vector2.New(0, 0), Vector2.New(80, 80));

	srand(time(NULL));

	while (1) {
		WPAD_SetVRes(0, 640, 480);
		WPAD_ScanPads();
		u32 wpaddown = WPAD_ButtonsDown(0);
		u32 wpadheld = WPAD_ButtonsHeld(0);
		WPAD_IR(WPAD_CHAN_0, &ir1);

		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) break; // Draw after this
		GRRLIB_FillScreen(0x000000FF);
		GRRLIB_PrintfTTF(200, 200, testFont, "Hello TTF Font", 36, ((rand() % 0xFFFFFF) << 8) | 0xFF);

		//Player.position = Vector2.Add(Player.position, velocity);

		ObjectChecks(Player);
		if (wpaddown & WPAD_BUTTON_A) {
			SpriteLoading::SetSprite(Player, test_png_2);
		}
		//GRRLIB_Rectangle(0, 430, 640, 50, 0xFFFFFFFF, true);
		//GRRLIB_DrawImg((int)Player.position.x, (int)Player.position.y, Player.image, 0, Player.scale.x, Player.scale.y, 0xFFFFFFFF);
		//GRRLIB_DrawImg((int)TestGround.position.x, (int)TestGround.position.y, TestGround.image, 0, TestGround.scale.x, TestGround.scale.y, 0xFFFFFFFF);

		GRRLIB_Render();
	}
	GRRLIB_Exit();
	exit(0);
}