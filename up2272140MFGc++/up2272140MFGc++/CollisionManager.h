#pragma once
#include "MyVector2.h"
#include "PhysicsObject.h"
#include "Circle.h"
#include "CollisionEvent.h"

void BroadPhase(std::vector<PhysicsObject> physObjs);

void NarrowPhase(std::vector<CollisionEvent> events);
