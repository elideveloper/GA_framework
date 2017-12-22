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
	void randomize();
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

	Individual* getRandomCopy() const;
	void mutate();			// ������������� ��������� �������� ������

	friend void cross(Individual* mom, Individual* dad);
	friend double evaluateIndividual(const Individual* ind);
};

typedef double(*individEvaluator)(const Individual*);
typedef std::vector<Individual*> Generation;