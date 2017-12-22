#include "GA.h"

#include <algorithm>
#include <iostream>

void GA::sortGeneration(Generation& generation, individEvaluator f)
{
	std::sort(generation.begin(), generation.end(), [f](Individual* ind1, Individual* ind2)->bool {
		std::cout << evaluateIndividual(ind1) << std::endl;
		std::cout << evaluateIndividual(ind2) << std::endl;
		return f(ind1) < f(ind2);
	});
}

GA::GA() : generationSize(0)
{}

GA::GA(unsigned int genSize) : generationSize(genSize)
{}

Generation GA::createRandomGeneration(const Individual& ind, individEvaluator f)
{
	Generation gen;
	gen.reserve(this->generationSize);
	for (int j = 0; j < this->generationSize; j++) gen.push_back(ind.getRandomCopy());
	for (const Individual* i : gen) {
		std::cout << "address: " << i << std::endl;
		std::cout << evaluateIndividual(i) << std::endl;
	}
	this->sortGeneration(gen, f);
	std::cout << "after sorting" << std::endl;
	for (const Individual* i : gen) {
		std:: cout << evaluateIndividual(i) << std::endl;
	}
	return gen;
}
