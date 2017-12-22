#include "Rect.h"

#include <random>

Rect::Rect(int w, int h) : w(w), h(h)
{}

Rect::Rect(const Rect& rect) : w(rect.w), h(rect.h)
{}

Rect& Rect::operator=(const Rect& rect)
{
	this->w = rect.w;
	this->h = rect.h;
	return *this;
}

int Rect::getH() const
{
	return this->h;
}

int Rect::getSquare() const
{
	return this->w * this->h;
}

void Rect::randomize()
{
	this->h = rand() % 100 + 1;
	this->w = rand() % 100 + 1;
}

Attribute* Rect::clone()
{
	return new Rect(*this);
}
