#pragma once

#include "Attribute.h"

class Individual {
	// мб считывать все числовые значения в строку и этой строкой манипулировать потом. 
	// всегда ли скрещиваемые данные это какие то числовые значения?
	// ! как правило, Индивид - это сочетание (комбинация) каких то аттрибутов (набор мувов или точек, комбинация из вида действия типа Move/Rotate и его параметров типа x, y, angle)
	// значит эту комбинацию можно представить в виде массива/списка параметров
	// и с этим списком будет удобно проводить операции типа скрещивания
	// останется в классе наследующем Индивида определить функцию которая считывает набор данных в геном, и все содержащиеся данные должны быть унаследованы от Attribute 

	// Порядок аттрибутов должен быть единственным, то есть под одним и тем же индексом должны быть параметры одного и того же типа
	Genome genome;
public:
	Individual();
	Individual(const Genome& genome);
	Individual(const Individual& ind);
	Individual& operator=(const Individual& ind);
	~Individual();

	void print();

	// эти две функции могут не пригодится если Индивид не наследуется а используется как есть
	// а по окончании эволюции, набор параметров берется прямо из генома
	//virtual void initIndividual();		// инициализирует геном из наследующего класса
	//virtual void setGenome();			// инициализирует поля наследующего класса значениями аттрибутов из генома

	Individual* randomize();

	static Individual* generateRandomOf(const Individual* ind);
	void mutate();			// рандомизирует случайный параметр генома

	friend void crossIndividuals(Individual* mom, Individual* dad, double mutationProb);
	friend double evaluateIndividual(const Individual* ind);
};

typedef double(*individEvaluator)(const Individual&);
typedef std::vector<Individual*> Generation;