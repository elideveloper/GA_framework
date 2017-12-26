#pragma once

#include "Attribute.h"

class City : public Attribute {
	int x;
	int y;
public:
	City();
	City(int w, int h);
	City(const City& city);
	City& operator=(const City& city);
	~City();

	int getX() const;
	int getY() const;

	double getDist(const City& city) const;

	virtual Attribute* randomize() override;
	virtual Attribute* clone() override;
	virtual std::string getID() override;

	virtual void print() override;
};
