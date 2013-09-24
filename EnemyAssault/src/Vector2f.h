#pragma once

class Vector2f
{
public:
	Vector2f(void) {};
	~Vector2f(void) {};

	Vector2f(float x, float y) : x(x), y(y) {};

	inline const Vector2f operator= (const Vector2f that)  
	{
		this->x = that.x;
		this->y = that.y;
		return *this;
	};

	inline const Vector2f operator+ (const Vector2f that)
	{
		return Vector2f(this->x + that.x, this->y + that.x);
	};

	inline const Vector2f operator- (const Vector2f that)
	{
		return Vector2f(this->x - that.x, this->y - that.x);
	};

	float x, y;
};

