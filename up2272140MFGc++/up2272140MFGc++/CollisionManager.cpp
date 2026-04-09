#include "CollisionManager.h"

void BroadPhase(std::vector<PhysicsObject> physObjs)
{
	for (int i = 0; i < physObjs.size(); i++)
	{
		for (int j = i + 1; j < physObjs.size(); j++) 
		{



		}
	}
}

void NarrowPhase(std::vector<CollisionEvent> events)
{
	for (CollisionEvent event : events) 
	{
		PhysicsObject* a = event.obj1;
		PhysicsObject* b = event.obj2;

		if (a->type == ObjectType::Circle && b->type == ObjectType::Circle)
		{
			MyVector2 direction = b->GetPosition() - a->GetPosition();
			float dist = direction.magnitude();
			float totalRadius = a->ReturnAreaData() + b->ReturnAreaData();

			if (dist < totalRadius) 
			{
				float overlap = dist - totalRadius;
				MyVector2 normalDir = direction.normalize();
				a->SetPosition(a->GetPosition() + (normalDir * (overlap / 2)));
				b->SetPosition(b->GetPosition() - (normalDir * (overlap / 2)));

				float mSum = a->GetMass() + b->GetMass();
				MyVector2 vDiff = b->GetVelocity() - a->GetVelocity();

				float numA = 2 * b->GetMass() * vDiff.dot(direction);
				float denA = mSum * dist * dist;

				MyVector2 deltaV = direction;
				deltaV = deltaV * (numA / denA);
				a->SetVelocity(a->GetVelocity() + deltaV);


				float numB = 2 * a->GetMass() * vDiff.dot(direction);	

				MyVector2 deltaVB = -direction;
				deltaVB = deltaVB * (numB / denA);
				b->SetVelocity(b->GetVelocity() + deltaVB);
			}

		}
	}
}
