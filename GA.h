#pragma once

#include "Individual.h"
#include "utility.h"

class GA {
	unsigned int populationSize;
	unsigned int genomeLength;
	Individual* individualInstance;
	double acceptableError;
	unsigned int maxGenerations;
	double mutationProb;
	unsigned int numElite;
	unsigned int numNewcomers;

	double sortAndGetMinError(Generation& generation);
public:
	GA();
	GA(unsigned int populationSize, unsigned int genomeLength, Attribute* attrInstance, double acceptableError, unsigned int maxGenerations, double elitePercentage, double newcomersPercentage, double mutationProb);

	Generation createRandomGeneration();
	Individual* findBest();
};
