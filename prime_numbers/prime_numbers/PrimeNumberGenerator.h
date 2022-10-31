#pragma once
#include "RandomGenerator.h"
#include <tuple>
class PrimeNumberGenerator: RandomGenerator
{
public:
	unsigned int naive(int numOfBits);
	bool naiveTest(unsigned int p);
	unsigned int millerRabin(int numOfBits, int s); 
	bool millerRabinTest(unsigned int p, int s);
	std::tuple<unsigned int, unsigned int> getFactors(unsigned int p);
	unsigned int modularExp(unsigned int a, unsigned int b, unsigned int n);
};

