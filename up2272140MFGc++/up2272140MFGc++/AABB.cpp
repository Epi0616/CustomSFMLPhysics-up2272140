#include "AABB.h"

AABB::AABB() {}

bool AABB::Intersect(AABB other)
{
	return !(other.min.x > max.x ||
			 other.max.x < min.x ||
		     other.max.y < min.y ||
			 other.min.y > max.y);
}

void AABB::SetWidthHeight(float width, float height)
{
	this->width = width;
	this->height = height;
}

void AABB::SetEqualExtents(float length) 
{
	width = length;
	height = length;
}

void AABB::SetBounds(MyVector2 pos)
{
	max.x = pos.x + (width / 2);
	max.y = pos.y + (height / 2);
	min.x = pos.x - (width / 2);
	min.y = pos.y - (height / 2);
}