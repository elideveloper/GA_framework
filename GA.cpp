#include "GA.h"

#include <algorithm>
#include <iostream>
//#include <unordered_map>

double GA::sortAndGetMinError(Generation& generation)
{
	/*std::unordered_map<Individual*, double> scores;
	for (Individual* i : generation) {
		scores.insert({ i, evaluateIndividual(i) });
	}
	std::sort(generation.begin(), generation.end(), [scores](Individual* ind1, Individual* ind2)->bool {
		return scores.find(ind1)->second < scores.find(ind2)->second;
	});*/
	
	std::sort(generation.begin(), generation.end(), [](const Individual* ind1, const Individual* ind2)->bool {
		return evaluateIndividual(ind1) < evaluateIndividual(ind2);
	});
	return evaluateIndividual(generation[0]);
}

GA::GA() : populationSize(0), genomeLength(0), individualInstance(nullptr), acceptableError(0.0), maxGenerations(0), numElite(0), numNewcomers(0), mutationProb(0.0)
{}

GA::GA(unsigned int populationSize, unsigned int genomeLength, Attribute* attrInstance, double acceptableError, unsigned int maxGenerations, double elitePercentage, double newcomersPercentage, double mutationProb)
	: populationSize(populationSize), genomeLength(genomeLength), acceptableError(acceptableError), maxGenerations(maxGenerations), 
	numElite(populationSize * boundBetween(0.0, 1.0, elitePercentage)), numNewcomers(populationSize * boundBetween(0.0, 1.0, newcomersPercentage)), mutationProb(boundBetween(0.0, 1.0, mutationProb))
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
	int j;
	for (int i = 0; i < this->maxGenerations; i++) {
		// вместо пула для скрещивания пока просто вся элита
		for (j = this->numElite; j < this->populationSize - this->numNewcomers; j++) gen[j]->turnToChildOf(gen[rand() % this->numElite], gen[rand() % this->numElite], this->mutationProb);
		for (j; j < this->populationSize; j++) gen[j]->randomize();
		if (this->sortAndGetMinError(gen) <= this->acceptableError) break;
	}
	for (int i = 1; i < this->populationSize; i++) delete gen[i];
	return gen[0];
}
