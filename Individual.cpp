#include "Individual.h"

#include <random>
#include <algorithm>    
#include <set>
#include <iterator>

void Individual::getRecombinationOf(const Individual * mom, const Individual * dad, unsigned int point)
{
	for (int i = 0; i < this->genotype.size(); i++) {
		delete this->genotype[i];
		this->genotype[i] = (i < point) ? mom->genotype[i]->clone() : dad->genotype[i]->clone();
	}
}

Individual::Individual()
{}

Individual::Individual(const Genotype& genotype, bool hasOrderedGenotype)
{
	this->hasOrderedGenotype = hasOrderedGenotype;
	this->genotype.reserve(genotype.size());
	for (Attribute* a : genotype) this->genotype.push_back(a->clone());
}

Individual::~Individual()
{
	for (Attribute* a : this->genotype) delete a;
}

Individual::Individual(const Individual& ind)
{
	this->hasOrderedGenotype = ind.hasOrderedGenotype;
	this->genotype.reserve(ind.getGenotypeLength());
	for (Attribute* a : ind.genotype) this->genotype.push_back(a->clone());
}

Individual& Individual::operator=(const Individual& ind)
{
	this->hasOrderedGenotype = ind.hasOrderedGenotype;
	this->genotype.clear(); this->genotype.reserve(ind.getGenotypeLength());
	for (Attribute* a : ind.genotype) this->genotype.push_back(a->clone());
	return *this;
}

void Individual::print()
{
	for (Attribute* a : this->genotype) a->print();
}

unsigned int Individual::getGenotypeLength() const
{
	return this->genotype.size();
}

Individual* Individual::randomize()
{
	if (this->hasOrderedGenotype) std::random_shuffle(this->genotype.begin(), this->genotype.end());
	else for (Attribute* a : this->genotype) a->randomize();
	return this;
}

Individual* Individual::generateRandomOf(const Individual* ind)
{
	return (new Individual(*ind))->randomize();
}

void Individual::mutate()
{
	if (this->hasOrderedGenotype) swapAttributes(this->genotype[rand() % this->genotype.size()], this->genotype[rand() % this->genotype.size()]);
	else this->genotype[rand() % this->genotype.size()]->randomize();
}

void Individual::turnToChildOf(const Individual* mom, const Individual* dad, double mutationProb)
{
	if (mom->genotype.size() > 1) {
		unsigned int point = (mom->genotype.size() == 2) ? 1 : rand() % (mom->genotype.size() - 1) + 1;
		printf("point: %d\n", point);
		if (this->hasOrderedGenotype) {
			std::set<Attribute*> setMom, setDad, setIntersec, sMom, sDad;
			for (int i = 0; i < point; i++) {
				setMom.insert(mom->genotype[i]);
				setDad.insert(dad->genotype[i]);
			}
			getRecombinationOf(mom, dad, point);
			std::set_intersection(setMom.begin(), setMom.end(), setDad.begin(), setDad.end(), std::inserter(setIntersec, setIntersec.end()));
			// почему либо 0 пересечений либо пересекаются все

			// потому что указатели всегда разные будут
			// вынуждены хранить сами объекты и определить оператор сравненения
			// иначе пересечение будет только в том случае если 
			// один и тот же элемент будет в роли папы и мамы

			printf("setIntersec.size(): %d\n", setIntersec.size());
			if (setIntersec.size() < point) {
				std::set_difference(setMom.begin(), setMom.end(), setIntersec.begin(), setIntersec.end(), std::inserter(sMom, sMom.end()));
				for (int i = point; i < this->genotype.size(); i++) {
					if (sMom.erase(this->genotype[i]) > 0) {
						delete this->genotype[i];
						this->genotype[i] = (*sDad.begin())->clone();
						sDad.erase(sDad.begin());
					}
				}
				//printf("Attributes after crossing over:\n");
				//this->print();	// delete
			}
		}
		else getRecombinationOf(mom, dad, point);
	}
	if (this->genotype.size() > 0 && (rand() % (10000 + 1)) * 0.0001 <= mutationProb) this->mutate();
}

//void crossIndividuals(Individual* mom, Individual* dad, double mutationProb)
//{
//	if (mom->genotype.size() > 1) {
//		int point = (mom->genotype.size() == 2) ? 1 : rand() % (mom->genotype.size() - 1) + 1;
//		for (int i = 0; i < mom->genotype.size(); i++) {
//			if (i < point) swapAttributes(dad->genotype[i], mom->genotype[i]);
//			else swapAttributes(mom->genotype[i], dad->genotype[i]);
//		}
//	}
//	if (mom->genotype.size() > 0) {
//		if ((rand() % (10000 + 1)) * 0.0001 <= mutationProb) mom->mutate();
//		if ((rand() % (10000 + 1)) * 0.0001 <= mutationProb) dad->mutate();
//	}
//}