#include "RandomGenerator.h"
#include <iostream>

RandomGenerator::RandomGenerator() {
	m = 4294967295;
	a = 69069;
	b = 0;
	rn = 1;
}

cpp_int RandomGenerator::lcg() {
	rn = (a * rn + b) % m;
	//std::cout << rn << std::endl;
	return rn;
}

cpp_int RandomGenerator::getRandom(cpp_int min, cpp_int max) {
	return  min + lcg() % (max - min + 1);
}