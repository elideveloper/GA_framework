#include "Rect.h"

#include <iostream>
#include <random>

Rect::Rect() : w(0), h(0)
{}

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

int Rect::getW() const
{
	return this->w;
}

int Rect::getSquare() const
{
	return this->w * this->h;
}

Attribute* Rect::randomize()
{
	this->h = rand() % 100 + 1;
	this->w = rand() % 100 + 1;
	return this;
}

Attribute* Rect::clone()
{
	return new Rect(*this);
}

void Rect::print()
{
	std::cout << "h = " << this->h << "; w = " << this->w << "; S = " << this->getSquare() << std::endl;
}
