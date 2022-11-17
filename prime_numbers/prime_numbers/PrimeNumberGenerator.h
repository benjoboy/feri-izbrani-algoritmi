#pragma once
#include "RandomGenerator.h"
#include <tuple>
class PrimeNumberGenerator: RandomGenerator
{
public:
	unsigned long long naive(int numOfBits);
	bool naiveTest(unsigned long long p);
	unsigned long long millerRabin(int numOfBits, int s);
	bool millerRabinTest(unsigned long long p, int s);
	std::tuple<unsigned long long, unsigned long long> getFactors(unsigned long long p);
	unsigned long long modularExp(unsigned long long a, unsigned long long b, unsigned long long n);
};

