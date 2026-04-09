#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

#include<iostream>

class MyVector2 
{
public:
	float x;
	float y;

	MyVector2(float x, float y) { this->x = x, this->y = y; }
	MyVector2() { x = 0.0f, y = 0.0f; }

	MyVector2 zero() { return MyVector2(); }

	MyVector2 ToMyVector2(sf::Vector2f v) { return MyVector2(v.x, v.y); }

	void PrintVector() { std::cout << x << " , " << y << std::endl; }

	MyVector2 operator+(const MyVector2 &b) { return MyVector2(x + b.x, y + b.y); }

	MyVector2 operator-(const MyVector2 &b) { return MyVector2(x - b.x, y - b.y); }

	MyVector2 operator*(const MyVector2 &b) { return MyVector2(x * b.x, y * b.y); }

	MyVector2 operator*(const float &s) { return MyVector2(x * s, y * s); }

	MyVector2 operator/(const float &s) 
	{
		if (s == 0.0f) { return MyVector2(); }
		return MyVector2(x / s, y / s);
	}

	MyVector2 operator-() { return MyVector2(-x, -y); }

	operator sf::Vector2f() { return sf::Vector2f(x, y); }
	
	float magnitude() { return std::sqrt(x * x + y * y); }

	MyVector2 normalize()
	{
		float m = magnitude();
		if (m == 0) { return MyVector2(); }
		return MyVector2(x / m, y / m);
	}

	float dot(MyVector2 b) { return x * b.x + y * b.y; }
};