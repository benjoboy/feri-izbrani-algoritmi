#include "RandomGenerator.h"
#include <iostream>

RandomGenerator::RandomGenerator() {
	m = 4294967295;
	a = 69069;
	b = 0;
	rn = 1;
}

unsigned int RandomGenerator::lcg() {
	rn = (a * rn + b) % m;
	//std::cout << rn << std::endl;
	return rn;
}

unsigned int RandomGenerator::getRandom(unsigned int min, unsigned int max) {
	return  (min + lcg()) % (max - min + 1);
}