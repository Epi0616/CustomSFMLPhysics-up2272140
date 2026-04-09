#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

#include "PhysicsObject.h"

class Circle : public PhysicsObject
{
private:
	float radius;

public:
	sf::CircleShape render;

	Circle(float r);

	Circle(float r, sf::Color color);

	void SetRadius(float r);

	float GetRadius();

	void CheckBounds(float width, float height) override;

	void UpdateRenderPosition() override;

	void Draw(sf::RenderWindow& window) override;

	float ReturnAreaData() override;
};