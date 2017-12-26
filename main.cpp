#include <random>
#include <time.h>
#include <iostream>

#include "Rect.h"
#include "GA.h"

// ���� �������� ����� �� ������� �������� ���������� � �� �������� ������ ������� - ��������
// ��������� ������� ������ ��������
// ��� ������ ���� - ��� �����

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
	for (Attribute* a : ind->genotype) {
		sum += static_cast<Rect*>(a)->getArea();
	}
	return fabs(10000.0 - sum);
}

// ������� ����� ��������� �������� ����� �����
// �������� � TSP (������ ����� ������ ���� ��� � ������, randomize() �� ����� ����� ����� �������, ��������������� ����� �������� � �� ��������!)
// ��������� ��� ������ ������������ ����� ��������� ��������
// ��� �������� �������, ��� ������ ������������ ��������, ����� ������������ ��������� ������� ������������ � �������������
// � � ����������� GA ���������� ��� �������� �� �����, �� ��������� ����� ��� ��������
// ��������� ����� �������, ������ �� ������ ������� �������� �����
// �������� ����� �������� ��� ������� � ���������� �������� ����� ������ � ��������� �������, ����� ������ �������� ���������
// �� �������� ������ ����� ����� �� ���������



const unsigned POP_SIZE = 100;
//const unsigned GEN_LENGTH = 10;
const unsigned NUM_GENERAIONS = 1;
const double ELITE_PERC = 0.1;
const double PARENTS_PERC = 0.5;
const double NEWCOM_PERC = 0.3;
const double MUT_PROB = 0.05;
const double ACCEPTABLE_ERROR = 2.0;

int main() {
	srand(time(0));

	//GA ga(POP_SIZE, GEN_LENGTH, new Rect(), ACCEPTABLE_ERROR, NUM_GENERAIONS, ELITE_PERC, NEWCOM_PERC, MUT_PROB);

	Genotype genotype;
	genotype.push_back(new Rect(4, 1));
	genotype.push_back(new Rect(4, 2));
	genotype.push_back(new Rect(4, 3));
	genotype.push_back(new Rect(4, 4));
	genotype.push_back(new Rect(4, 5));
	genotype.push_back(new Rect(4, 6));
	genotype.push_back(new Rect(4, 7));
	genotype.push_back(new Rect(4, 8));
	genotype.push_back(new Rect(4, 9));
	genotype.push_back(new Rect(4, 10));
	GA ga(POP_SIZE, new Individual(genotype, true), ACCEPTABLE_ERROR, NUM_GENERAIONS, ELITE_PERC, PARENTS_PERC, NEWCOM_PERC, MUT_PROB);

	Individual* bestInd = ga.findBest();
	std::cout << "best: " << fitnessFunction(bestInd) << std::endl;
	bestInd->print();

	system("pause");

	return 0;
}