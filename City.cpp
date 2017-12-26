#include "City.h"

#include <iostream>
#include <string> 
#include <math.h>

City::City() : x(0), y(0)
{}

City::City(int x, int y) : x(x), y(y)
{}

City::City(const City& city) : x(city.x), y(city.y)
{}

City& City::operator=(const City& city)
{
	this->x = city.x;
	this->y = city.y;
	return *this;
}

City::~City()
{}

int City::getX() const
{
	return this->x;
}

int City::getY() const
{
	return this->y;
}

double City::getDist(const City& city) const
{
	return sqrt((x - city.x)*(x - city.x) + (y - city.y)*(y - city.y));
}

Attribute* City::randomize()
{
	return this;
}

Attribute* City::clone()
{
	return new City(*this);
}

std::string City::getID()
{
	return std::to_string(this->x) + std::to_string(this->y);
}

void City::print()
{
	std::cout << "x = " << this->x << "; y = " << this->y << std::endl;
}