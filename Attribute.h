#pragma once

#include <vector>

struct Attribute {
public:
	virtual ~Attribute();
	virtual Attribute* clone() = 0;
	virtual Attribute* randomize() = 0;

	virtual void print() = 0;
};

void swapAttributes(Attribute* attr1, Attribute* attr2);

typedef std::vector<Attribute*> Genotype;
