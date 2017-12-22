#pragma once

#include <vector>

struct Attribute {
public:
	virtual Attribute* clone() = 0;
	virtual void randomize() = 0;
};

typedef std::vector<Attribute*> Genome;