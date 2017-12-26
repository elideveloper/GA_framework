#include <random>
#include <time.h>
#include <iostream>

#include "Rect.h"
#include "City.h"
#include "GA.h"

// сюда возможно какой то целевой параметр передавать а не зашивать внутри функции - подумать
// простешая функция оценки индивида
// чем меньше балл - тем лучше

//// for unordered genotype (sum areas of rectangles)
//double fitnessFunction(const Individual* ind) {
//	double sum = 0.0;
//	for (Attribute* a : ind->genotype) {
//		sum += static_cast<Rect*>(a)->getArea();
//	}
//	return fabs(10000.0 - sum);
//}

// for Ordered genotype (TSP)
double fitnessFunction(const Individual* ind) {
	double sum = 0.0;
	for (int i = 0; i < ind->getGenotypeLength() - 1; i++) {
		sum += static_cast<City*>(ind->genotype[i])->getDist(*(static_cast<City*>(ind->genotype[i + 1])));
	}
	sum += static_cast<City*>(ind->genotype[ind->getGenotypeLength() - 1])->getDist(*(static_cast<City*>(ind->genotype[0])));
	return fabs(0.0 - sum);
}

const unsigned POP_SIZE = 200;
const unsigned GEN_LENGTH = 10;
const unsigned NUM_GENERAIONS = 300;
const double ELITE_PERC = 0.1;
const double PARENTS_PERC = 0.5;
const double NEWCOM_PERC = 0.3;
const double MUT_PROB = 0.05;
const double ACCEPTABLE_ERROR = 5.0;

int main() {
	srand(time(0));

	//GA ga(POP_SIZE, GEN_LENGTH, new Rect(), ACCEPTABLE_ERROR, NUM_GENERAIONS, ELITE_PERC, PARENTS_PERC, NEWCOM_PERC, MUT_PROB);

	Genotype genotype;
	genotype.push_back(new City(1, 1));
	genotype.push_back(new City(5, 5));
	genotype.push_back(new City(3, 5));
	genotype.push_back(new City(2, 4));
	genotype.push_back(new City(6, 4));
	genotype.push_back(new City(1, 3));
	genotype.push_back(new City(7, 3));
	genotype.push_back(new City(4, 1));
	genotype.push_back(new City(7, 1));
	GA ga(POP_SIZE, new Individual(genotype, true), ACCEPTABLE_ERROR, NUM_GENERAIONS, ELITE_PERC, PARENTS_PERC, NEWCOM_PERC, MUT_PROB);

	Individual* bestInd = ga.findBest();
	std::cout << "best: " << fitnessFunction(bestInd) << std::endl;
	bestInd->print();

	system("pause");

	return 0;
}