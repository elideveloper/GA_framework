#include "GA.h"

#include <algorithm>
#include <iostream>

// нужна ли эта функция если один метод только вызывается внутри?!
void GA::sortGeneration(Generation& generation)
{
	std::sort(generation.begin(), generation.end(), [](const Individual* ind1, const Individual* ind2)->bool {
		return evaluateIndividual(ind1) < evaluateIndividual(ind2);
	});
}

GA::GA() : generationSize(0), genomeLength(0), individualInstance(nullptr)
{}

GA::GA(unsigned int generationSize, unsigned int genomeLength, Attribute* attrInstance)
	: generationSize(generationSize), genomeLength(genomeLength)
{
	Genome genome; genome.reserve(genomeLength);
	for (int i = 0; i < genomeLength; i++) genome.push_back(attrInstance->clone()->randomize());
	this->individualInstance = new Individual(genome);
}

Generation GA::createRandomGeneration()
{
	Generation generation; generation.reserve(this->generationSize);
	for (int j = 0; j < this->generationSize; j++) generation.push_back(Individual::generateRandomOf(this->individualInstance));
	this->sortGeneration(generation);
	return generation;
}

Individual* GA::findBest()
{
	Generation gen = createRandomGeneration();
	for (int i = 0; i < 10000; i++) {
		crossIndividuals(gen[1], gen[2]);
		crossIndividuals(gen[3], gen[4]);
		for (int j = 5; j < this->generationSize; j++) {
			gen[j]->randomize();
		}
		this->sortGeneration(gen);
	}
	// release memory
	return gen[0];
}
