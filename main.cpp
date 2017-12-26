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

// пролема когда аттрибуты зависимы между собой
// например в TSP (каждый город только один раз в геноме, randomize() не может любой город вернуть, рандомизировать нужно индивида а не аттрибут!)
// разобрать как делать кроссинговер когда аттрибуты зависимы
// для подобных проблем, где только перестановка возможна, можно использовать отдельные функции рандомизации и кроссинговера
// и в конструктор GA передавать это значение из енума, по умолчанию будет все рандомно
// кроссовер можно сделать, только он больше времени занимать будет
// возможно стоит сравнить это решение с вычитанием большого числа баллов в оценочной функции, чтобы только валидные проходили
// но валидных нужное число может не набраться

// подумать насчет скрещивания с лучшим геном и насчет скрещивания не только последовательно парном но и в других комбинациях

const unsigned POP_SIZE = 200;
const unsigned GEN_LENGTH = 10;
const unsigned NUM_GENERAIONS = 100;
const double ELITE_PERC = 0.1;
const double NEWCOM_PERC = 0.3;
const double MUT_PROB = 0.1;
const double ACCEPTABLE_ERROR = 10.0;

int main() {

	srand(time(0));

	class GA ga(POP_SIZE, GEN_LENGTH, new Rect(), ACCEPTABLE_ERROR, NUM_GENERAIONS, ELITE_PERC, NEWCOM_PERC, MUT_PROB);
	Individual* bestInd = ga.findBest();
	std::cout << "best: " << evaluateIndividual(bestInd) << std::endl;
	bestInd->print();

	system("pause");

	return 0;
}