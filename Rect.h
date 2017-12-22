#pragma once

#include "Attribute.h"

class Rect : public Attribute {
	int w;
	int h;
public:
	Rect(int w, int h);
	Rect(const Rect& rect);
	Rect& operator=(const Rect& rect);

	int getH() const;

	int getSquare() const;

	virtual void randomize() override;
	virtual Attribute* clone() override;
};