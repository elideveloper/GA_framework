#pragma once

#include "Individual.h"

class GA {
	unsigned int populationSize;
	unsigned int genomeLength;
	Individual* individualInstance;
	double acceptableError;
	unsigned int maxGenerations;

	void sortGeneration(Generation& generation);
public:
	GA();
	GA(unsigned int populationSize, unsigned int genomeLength, Attribute* attrInstance, double acceptableError, unsigned int maxGenerations);

	// numCross
	// probabMutate

	Generation createRandomGeneration();
	Individual* findBest();
};
