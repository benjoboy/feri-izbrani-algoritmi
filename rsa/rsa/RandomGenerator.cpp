#include "RandomGenerator.h"
#include <iostream>

RandomGenerator::RandomGenerator() {
	m = 4294967295;
	a = 69069;
	b = 0;
	rn = 1;
}

unsigned long long RandomGenerator::lcg() {
	rn = (a * rn + b) % m;
	//std::cout << rn << std::endl;
	return rn;
}

unsigned long long RandomGenerator::getRandom(unsigned long long min, unsigned long long max) {
	return  (min + lcg()) % (max - min + 1);
}