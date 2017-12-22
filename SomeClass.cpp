#include "SomeClass.h"

#include <random>

SomeClass::SomeClass()
{
	for (int i = 0; i < 10; i++) {
		this->digits.push_back(i);
	}
}

void SomeClass::randomize()
{
	for (int i = 0; i < 10; i++) {
		this->digits.push_back(rand() % 10);
	}
}
