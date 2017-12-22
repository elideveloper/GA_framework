#pragma once

#include <vector>

struct Attribute {
public:
	virtual void randomize() = 0;
};

typedef std::vector<Attribute*> Genome;