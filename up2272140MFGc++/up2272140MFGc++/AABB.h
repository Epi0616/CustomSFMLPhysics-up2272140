#pragma once
#include "MyVector2.h"

class AABB
{
private:
	float width, height;
	MyVector2 max, min;

public:
	AABB();
	
	bool Intersect(AABB other);
	
	void SetBounds(MyVector2 pos);

	void SetEqualExtents(float length);

	void SetWidthHeight(float width, float height);
};