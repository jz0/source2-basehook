#pragma once

class Color
{
public:
	Color();
	Color(BYTE r, BYTE g, BYTE b, BYTE a = 255)
	{
		this->r = r,
			this->g = g,
			this->b = b,
			this->a = a;
	}
	BYTE r, g, b, a;

	BYTE& operator[](int i)
	{
		return *(BYTE*)((int)this + i);
	}
};
