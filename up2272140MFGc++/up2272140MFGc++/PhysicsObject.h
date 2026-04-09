#pragma once
#include "MyVector2.h"

enum class ObjectType{ Circle };

class PhysicsObject 
{
protected:
	
	float mass;
	MyVector2 velocity;
	MyVector2 acceleration;
	MyVector2 position;

public:

	ObjectType type;

	void SetMass(float m) { mass = m; }
	void SetVelocity(float x, float y) { velocity.x = x, velocity.y = y; }
	void SetVelocity(MyVector2 v) { velocity = v; }
	void SetVelocityX(float x) { velocity.x = x; }
	void SetVelocityY(float y) { velocity.y = y; }
	void SetAcceleration(float x, float y) { acceleration.x = x, acceleration.y = y; }
	void SetAcceleration(MyVector2 v) { acceleration = v; }
	void SetAccelerationX(float x) { acceleration.x = x; }
	void SetAccelerationY(float y) { acceleration.y = y; }
	void SetPosition(float x, float y) { position.x = x, position.y = y; }
	void SetPosition(MyVector2 v) { position = v; }
	void SetPositionX(float x) { position.x = x; }
	void SetPositionY(float y) { position.y = y; }

	float GetMass() { return mass; }
	MyVector2 GetVelocity() { return velocity; }
	float GetVelocityX() { return velocity.x; }
	float GetVelocityY() { return velocity.y; }
	MyVector2 GetAcceleration() { return acceleration; }
	float GetAccelerationX() { return acceleration.x; }
	float GetAccelerationY() { return acceleration.y; }
	MyVector2 GetPosition() { return position; }
	float GetPositionX() { return position.x; }
	float GetPositionY() { return position.y; }

	void ApplyAccelerationAndVelocity(float dt)
	{ 
		velocity = velocity + acceleration * dt;
		position = position + velocity * dt;
	}

	void InvertVelocity() { velocity = velocity * -1.0f; }
	void InvertVelocityX() { velocity.x = velocity.x * -1.0f; }
	void InvertVelocityY() { velocity.y = velocity.y * -1.0f; }

	virtual void CheckBounds(float width, float height) {}
	virtual void UpdateRenderPosition() {}
	virtual void Draw(sf::RenderWindow &window) {}
	virtual float ReturnAreaData() { return 0; }
};