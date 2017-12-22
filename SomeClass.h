#pragma once

#include "Individual.h"

#include <vector>

class SomeClass : public Individual {
	std::vector<int> digits;

public:
	SomeClass();

	virtual void randomize() final;

};