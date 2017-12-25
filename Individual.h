#pragma once

#include "Attribute.h"

class Individual {
	// �� ��������� ��� �������� �������� � ������ � ���� ������� �������������� �����. 
	// ������ �� ������������ ������ ��� ����� �� �������� ��������?
	// ! ��� �������, ������� - ��� ��������� (����������) ����� �� ���������� (����� ����� ��� �����, ���������� �� ���� �������� ���� Move/Rotate � ��� ���������� ���� x, y, angle)
	// ������ ��� ���������� ����� ����������� � ���� �������/������ ����������
	// � � ���� ������� ����� ������ ��������� �������� ���� �����������
	// ��������� � ������ ����������� �������� ���������� ������� ������� ��������� ����� ������ � �����, � ��� ������������ ������ ������ ���� ������������ �� Attribute 

	// ������� ���������� ������ ���� ������������, �� ���� ��� ����� � ��� �� �������� ������ ���� ��������� ������ � ���� �� ����
	Genome genome;
public:
	Individual();
	Individual(const Genome& genome);
	Individual(const Individual& ind);
	Individual& operator=(const Individual& ind);
	~Individual();

	void print();

	// ��� ��� ������� ����� �� ���������� ���� ������� �� ����������� � ������������ ��� ����
	// � �� ��������� ��������, ����� ���������� ������� ����� �� ������
	//virtual void initIndividual();		// �������������� ����� �� ������������ ������
	//virtual void setGenome();			// �������������� ���� ������������ ������ ���������� ���������� �� ������

	Individual* randomize();

	static Individual* generateRandomOf(const Individual* ind);
	void mutate();			// ������������� ��������� �������� ������

	friend void crossIndividuals(Individual* mom, Individual* dad, double mutationProb);
	friend double evaluateIndividual(const Individual* ind);
};

typedef double(*individEvaluator)(const Individual&);
typedef std::vector<Individual*> Generation;