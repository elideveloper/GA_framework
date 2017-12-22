#include "GA.h"

#include <algorithm>
#include <iostream>

// нужна ли эта йункция если один метод только вызывается внутри?!
void GA::sortGeneration(Generation& generation)
{
	std::sort(generation.begin(), generation.end(), [](const Individual* ind1, const Individual* ind2)->bool {
		return evaluateIndividual(ind1) < evaluateIndividual(ind2);
	});
}

GA::GA() : generationSize(0)
{}

GA::GA(unsigned int genSize) : generationSize(genSize)
{}

Generation GA::createRandomGeneration(const Individual& ind)
{
	Generation gen;
	gen.reserve(this->generationSize);
	for (int j = 0; j < this->generationSize; j++) gen.push_back(Individual::generateRandomOf(ind));
	this->sortGeneration(gen);
	return gen;
}

Individual* GA::findBest(const Individual& ind)
{
	// может при создании первого поколения сохранять переданный геном первым элементом массива, то есть делать копию этого индивида
	Generation gen = createRandomGeneration(ind);
	for (int i = 0; i < 10000; i++) {
		cross(gen[1], gen[2]);
		cross(gen[3], gen[4]);
		for (int j = 5; j < this->generationSize; j++) {
			gen[j]->randomize();
		}
		this->sortGeneration(gen);
	}
	// release memory
	return gen[0];
}
