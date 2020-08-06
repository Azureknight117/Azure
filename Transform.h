#pragma once

#include "Vector2D.h"

class Transform {

public:
	float x, y;
	Transform(float X = 0, float Y = 0): x(X), y(Y){}

	inline void TranslateX(float X) { x += X; }
	inline void TranslateY(float Y) { y += Y; }
	void Translate(Vector2D v) { x += v.x, y += v.y; }

private:
};
