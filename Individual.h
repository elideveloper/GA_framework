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
	// ����������� ������ � �����������

	Individual(const Individual& ind);
	Individual& operator=(const Individual& ind);

	// ��� ��� ������� ����� �� ���������� ���� ������� �� ����������� � ������������ ��� ����
	// � �� ��������� ��������, ����� ���������� ������� ����� �� ������
	//virtual void initIndividual();		// �������������� ����� �� ������������ ������
	//virtual void setGenome();			// �������������� ���� ������������ ������ ���������� ���������� �� ������

	void randomize();

	static Individual* generateRandomOf(const Individual& ind);
	void mutate();			// ������������� ��������� �������� ������

	friend void cross(Individual* mom, Individual* dad);
	friend double evaluateIndividual(const Individual* ind);
};

typedef double(*individEvaluator)(const Individual&);
typedef std::vector<Individual*> Generation;