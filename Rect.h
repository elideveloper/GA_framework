#pragma once

#include "Attribute.h"

class Rect : public Attribute {
	int w;
	int h;
public:
	Rect();
	Rect(int w, int h);
	Rect(const Rect& rect);
	Rect& operator=(const Rect& rect);
	~Rect();
	int getH() const;
	int getW() const;
	int getArea() const;

	virtual Attribute* randomize() override;
	virtual Attribute* clone() override;
	virtual std::string getID() override;

	virtual void print() override;
};