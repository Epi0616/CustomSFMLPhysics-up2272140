#include "Circle.h"

Circle::Circle(float r)
{
	radius = r;
	render = sf::CircleShape(r);
	MyVector2 c = { radius / 2, radius / 2 };
	render.setOrigin(c);
	type = ObjectType::Circle;
}

Circle::Circle(float r, sf::Color color) 
{
	radius = r;
	render = sf::CircleShape(r);
	MyVector2 c = { radius / 2, radius / 2 };
	render.setOrigin(c);
	render.setFillColor(color);
	type = ObjectType::Circle;
}

void Circle::SetRadius(float r) { radius = r; }

float Circle::GetRadius() { return radius; }

void Circle::CheckBounds(float width, float height)
{
	if (position.x > width - radius || position.x < 0.0f) { InvertVelocityX(); }

	if (height - position.y > height - radius || height - position.y < 0.0f) { InvertVelocityY(); }
}

void Circle::UpdateRenderPosition() 
{
	render.setPosition({ GetPositionX() , (800 - GetPositionY()) });
}

void Circle::Draw(sf::RenderWindow& window)
{
	window.draw(render);
}

float Circle::ReturnAreaData() { return radius; }