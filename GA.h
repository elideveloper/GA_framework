#pragma once

#include "Individual.h"

class GA {
	unsigned int generationSize;
	unsigned int genomeLength;
	Individual* individualInstance;

	void sortGeneration(Generation& generation);
public:
	GA();
	GA(unsigned int generationSize, unsigned int genomeLength, Attribute* attrInstance);

	// numCross
	// probabMutate

	// init stop conditions
	// run GA and get result

	Generation createRandomGeneration();
	Individual* findBest();
};
