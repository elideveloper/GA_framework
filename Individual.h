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
	bool hasOrderedGenotype;
	Genotype genotype;
	void getRecombinationOf(const Individual* mom, const Individual* dad, unsigned int point);
public:
	Individual();
	Individual(const Genotype& genotype, bool hasOrderedGenotype);
	Individual(const Individual& ind);
	Individual& operator=(const Individual& ind);
	~Individual();

	void print();

	// ��� ��� ������� ����� �� ���������� ���� ������� �� ����������� � ������������ ��� ����
	// � �� ��������� ��������, ����� ���������� ������� ����� �� ������
	//virtual void initIndividual();		// �������������� ����� �� ������������ ������
	//virtual void setGenotype();			// �������������� ���� ������������ ������ ���������� ���������� �� ������

	unsigned int getGenotypeLength() const;

	Individual* randomize();

	static Individual* generateRandomOf(const Individual* ind);
	void mutate();																// ������������� ��������� �������� ������
	void turnToChildOf(const Individual* mom, const Individual* dad, double mutationProb);

	friend double fitnessFunction(const Individual* ind);
};

typedef double(*individEvaluator)(const Individual&);
typedef std::vector<Individual*> Generation;