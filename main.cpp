#include <random>
#include <time.h>
#include <iostream>

#include "Rect.h"
#include "GA.h"

// ���� �������� ����� �� ������� �������� ���������� � �� �������� ������ ������� - ��������
// ��������� ������� ������ ��������
// ��� ������ ���� - ��� �����
double evaluateIndividual(const Individual* ind) {
	double sum = 0.0;
	for (Attribute* a : ind->genome) {
		sum += static_cast<Rect*>(a)->getSquare();
	}
	return fabs(10000.0 - sum);
}

// ������� ����� ��������� �������� ����� �����
// �������� � TSP (������ ����� ������ ���� ��� � ������, randomize() �� ����� ����� ����� �������, ��������������� ����� �������� � �� ��������!)


const unsigned POP_SIZE = 200;
const unsigned GEN_LENGTH = 10;
const unsigned NUM_GENERAIONS = 100;
const unsigned NUM_CROSS = 140;
const double MUT_PROB = 0.1;
const double ACCEPTABLE_ERROR = 10.0;

int main() {

	srand(time(0));

	class GA ga(POP_SIZE, GEN_LENGTH, new Rect(), ACCEPTABLE_ERROR, NUM_GENERAIONS, NUM_CROSS, MUT_PROB);
	Individual* bestInd = ga.findBest();
	std::cout << "best: " << evaluateIndividual(bestInd) << std::endl;
	bestInd->print();

	system("pause");

	return 0;
}