#pragma once

#include "Individual.h"

class GA {
	unsigned int populationSize;
	unsigned int genomeLength;
	Individual* individualInstance;
	double acceptableError;
	unsigned int maxGenerations;
	double mutationProb;
	unsigned int numCross;

	double sortAndGetMinError(Generation& generation);
public:
	GA();
	GA(unsigned int populationSize, unsigned int genomeLength, Attribute* attrInstance, double acceptableError, unsigned int maxGenerations, unsigned int numCross, double mutationProb);


	Generation createRandomGeneration();
	Individual* findBest();
};
