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


int main() {

	srand(time(0));

	class GA ga(10, 8, new Rect(), 10.0, 10000, 4, 0.1);
	Individual* bestInd = ga.findBest();
	std::cout << "best: " << evaluateIndividual(bestInd) << std::endl;
	bestInd->print();

	system("pause");

	return 0;
}