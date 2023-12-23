#ifndef VECTOR2_H
#define VECTOR2_H

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

#endif