#pragma once

#include "Individual.h"

class GA {
	unsigned int generationSize;

	void sortGeneration(Generation& generation);
public:
	GA();
	GA(unsigned int genSize);

	// init stop conditions
	// run GA and get result

	Generation createRandomGeneration(const Individual& ind);
	Individual* findBest(const Individual& ind);
};
