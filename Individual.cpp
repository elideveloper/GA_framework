#include "Individual.h"

#include <random>

void cross(Individual* mom, Individual* dad)
{
	if (mom->genome.size() < 2) return;
	int mid = (mom->genome.size() == 2) ? 1 : rand() % (mom->genome.size() - 1) + 1;
	Attribute* tmp = nullptr;
	for (int i = 0; i < mom->genome.size(); i++) {
		if (i < mid) {
			tmp = mom->genome[i];
			mom->genome[i] = dad->genome[i];
			dad->genome[i] = tmp;
		}
		else {
			tmp = dad->genome[i];
			dad->genome[i] = mom->genome[i];
			mom->genome[i] = tmp;
		}
	}
}

Individual::Individual()
{}

Individual::Individual(const Genome& genome)
{
	for (Attribute* a : genome) this->genome.push_back(a->clone());
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

void Individual::randomize()
{
	for (Attribute* a : this->genome) a->randomize();
}

Individual* Individual::generateRandomOf(const Individual& ind)
{
	Individual* i = new Individual(ind);
	i->randomize();
	return i;
}

void Individual::mutate()
{
	this->genome[rand() % this->genome.size()]->randomize();
}
