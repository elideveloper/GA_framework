#pragma once

#include "Individual.h"

class GA {
	unsigned int generationSize;

	void sortGeneration(Generation& generation, individEvaluator f);
public:
	GA();
	GA(unsigned int genSize);

	// init stop conditions
	// run GA and get result

	// create generation m b
	Generation createRandomGeneration(const Individual& ind, individEvaluator f);
};
