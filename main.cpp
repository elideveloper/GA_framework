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

	class GA ga(10, 8, new Rect());
	Individual* bestInd = ga.findBest();
	std::cout << "best: " << evaluateIndividual(bestInd) << std::endl;
	bestInd->print();

	system("pause");

	return 0;
}