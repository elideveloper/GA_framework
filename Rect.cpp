#include "Rect.h"

#include <iostream>
#include <string> 
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

Rect::~Rect()
{}

int Rect::getH() const
{
	return this->h;
}

int Rect::getW() const
{
	return this->w;
}

int Rect::getArea() const
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

std::string Rect::getID()
{
	return std::to_string(this->h) + std::to_string(this->w) + std::to_string(this->getArea());
}

void Rect::print()
{
	std::cout << "h = " << this->h << "; w = " << this->w << "; S = " << this->getArea() << std::endl;
}
