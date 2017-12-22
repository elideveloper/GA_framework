#include <random>
#include <time.h>
#include <iostream>

#include "Rect.h"
#include "GA.h"

// сюда возможно какой то целевой параметр передавать а не зашивать внутри функции - подумать
// простешая функция оценки индивида
// чем меньше балл - тем лучше
double evaluateIndividual(const Individual* ind) {
	double sum = 0.0;
	for (Attribute* a : ind->genome) {
		sum += static_cast<Rect*>(a)->getSquare();
	}
	return fabs(10000.0 - sum);
}


/*
Не обязательно создавать геном с элементами, 
можно просто размер указать генома 
и с помощью метода типа гетРандом
образовать геном
*/

int main() {

	srand(time(0));

	class GA ga(8);
	Genome genome;
	genome.push_back(new Rect(21, 5));
	genome.push_back(new Rect(100, 30));
	genome.push_back(new Rect(33, 22));
	genome.push_back(new Rect(25, 40));
	genome.push_back(new Rect(20, 50));
	genome.push_back(new Rect(24, 30));
	genome.push_back(new Rect(88, 22));
	genome.push_back(new Rect(25, 12));
	Individual ind(genome);
	std::cout << "first: " << evaluateIndividual(&ind) << std::endl;
	Individual* bestInd = ga.findBest(ind);
	std::cout << "best: " << evaluateIndividual(bestInd) << std::endl;

	system("pause");

	return 0;
}