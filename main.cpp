#include <random>
#include <time.h>
#include <iostream>

#include "Rect.h"
#include "GA.h"

// простешая функция оценки индивида
double evaluateIndividual(const Individual* ind) {
	double sum = 0.0;
	for (Attribute* a : ind->genome) {
		std::cout << "h: " << static_cast<Rect*>(a)->getH() << std::endl;
		sum += static_cast<Rect*>(a)->getSquare();
	}
	return fabs(1000.0 - sum);
}

int main() {

	srand(time(0));

	class GA ga(4);
	Genome genome;
	genome.push_back(new Rect(2,5));
	genome.push_back(new Rect(100, 30));
	genome.push_back(new Rect(33, 22));
	genome.push_back(new Rect(25, 40));
	Individual ind(genome);
	Generation gen = ga.createRandomGeneration(ind, evaluateIndividual);


	system("pause");

	return 0;
}