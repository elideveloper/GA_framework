#include "Individual.h"

#include <random>

Individual::Individual()
{}

Individual::Individual(const Genome& genome)
{
	for (Attribute* a : genome) this->genome.push_back(a->clone());
}

Individual::~Individual()
{
	for (Attribute* a : this->genome) delete a;
}

Individual::Individual(const Individual& ind)
{
	for (Attribute* a : ind.genome) this->genome.push_back(a->clone());
}

Individual& Individual::operator=(const Individual& ind)
{
	this->genome.clear(); this->genome.resize(0);
	for (Attribute* a : ind.genome) this->genome.push_back(a->clone());
	return *this;
}

void Individual::print()
{
	for (Attribute* a : this->genome) a->print();
}

Individual* Individual::randomize()
{
	for (Attribute* a : this->genome) a->randomize();
	return this;
}

Individual* Individual::generateRandomOf(const Individual* ind)
{
	return (new Individual(*ind))->randomize();
}

void Individual::mutate()
{
	this->genome[rand() % this->genome.size()]->randomize();
}

void crossIndividuals(Individual* mom, Individual* dad, double mutationProb)
{
	if (mom->genome.size() > 1) {
		int mid = (mom->genome.size() == 2) ? 1 : rand() % (mom->genome.size() - 1) + 1;
		for (int i = 0; i < mom->genome.size(); i++) {
			if (i < mid) swapAttributes(dad->genome[i], mom->genome[i]);
			else swapAttributes(mom->genome[i], dad->genome[i]);
		}
	}
	if (mom->genome.size() > 0) {
		if ((rand() % (10000 + 1)) * 0.0001 <= mutationProb) mom->mutate();
		if ((rand() % (10000 + 1)) * 0.0001 <= mutationProb) dad->mutate();
	}
}