#include "Individual.h"

void cross(Individual * mom, Individual * dad)
{
	int mid = mom->genome.size() * 0.5;
	for (int i = 0; i < mom->genome.size(); i++) {
		if (i < mid) {
			mom->genome[i] = dad->genome[i];
		}
		else {
			dad->genome[i] = mom->genome[i];
		}
	}
}
