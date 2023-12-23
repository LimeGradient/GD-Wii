#ifndef OBJECT_H
#define OBJECT_H

#include <list>

#include <grrlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <ogc/tpl.h>
#include <fat.h>

#include "Vector2.h"

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
	vector2 velocity;
	bool isPlayer = false;

}object;

std::list<object*> objectList = {};

typedef struct {
	object New(GRRLIB_texImg* image, vector2 position, vector2 hitboxVal1, vector2 hitboxVal2, int collisionType = 1, vector2 imgScale = Vector2.New(1,1), vector2 velocity = Vector2.New(0,0), float rotation = 0, vector2 pivot = Vector2.New(0, 0), bool hasCollision = true, bool isTrigger = false) {
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
		_object.velocity = velocity;
	    objectList.push_back(&_object);
		return _object;
	}

}ObjectFunctions;
ObjectFunctions Object;

#endif