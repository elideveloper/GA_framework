#include "GA.h"

#include <algorithm>
#include <iostream>

double GA::sortAndGetMinError(Generation& generation)
{
	std::sort(generation.begin(), generation.end(), [](const Individual* ind1, const Individual* ind2)->bool {
		return evaluateIndividual(ind1) < evaluateIndividual(ind2);
	});
	return evaluateIndividual(generation[0]);
}

GA::GA() : populationSize(0), genomeLength(0), individualInstance(nullptr), acceptableError(0.0), maxGenerations(0), numCross(0), mutationProb(0.0)
{}

GA::GA(unsigned int populationSize, unsigned int genomeLength, Attribute* attrInstance, double acceptableError, unsigned int maxGenerations, unsigned int numCross, double mutationProb)
	: populationSize(populationSize), genomeLength(genomeLength), acceptableError(acceptableError), maxGenerations(maxGenerations), numCross(numCross), mutationProb(mutationProb)
{
	Genome genome; genome.reserve(genomeLength);
	for (int i = 0; i < genomeLength; i++) genome.push_back(attrInstance->clone()->randomize());
	this->individualInstance = new Individual(genome);
}

Generation GA::createRandomGeneration()
{
	Generation generation; generation.reserve(this->populationSize);
	for (int j = 0; j < this->populationSize; j++) generation.push_back(Individual::generateRandomOf(this->individualInstance));
	this->sortAndGetMinError(generation);
	return generation;
}

Individual* GA::findBest()
{
	Generation gen = createRandomGeneration();
	for (int i = 0; i < this->maxGenerations; i++) {
		crossIndividuals(gen[1], gen[2], this->mutationProb);
		crossIndividuals(gen[3], gen[4], this->mutationProb);
		for (int j = 5; j < this->populationSize; j++) {
			gen[j]->randomize();
		}
		if (this->sortAndGetMinError(gen) <= this->acceptableError) break;
	}
	for (int i = 1; i < this->populationSize; i++) {
		delete gen[i];
	}
	return gen[0];
}
