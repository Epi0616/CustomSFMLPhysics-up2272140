#pragma once
#include "PhysicsObject.h"

class CollisionEvent
{
public:
	PhysicsObject* obj1;
	PhysicsObject* obj2;
	MyVector2 direction;

	CollisionEvent(PhysicsObject* a, PhysicsObject* b)
	{
		obj1 = a;
		obj2 = b;

	}
	
	
};