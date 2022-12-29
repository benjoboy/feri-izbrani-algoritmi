#pragma once
#include "RandomGenerator.h"
#include <tuple>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

class PrimeNumberGenerator: public RandomGenerator
{
public:
	cpp_int naive(int numOfBits);
	bool naiveTest(cpp_int p);
	cpp_int millerRabin(int numOfBits, int s);
	bool millerRabinTest(cpp_int p, int s);
	std::tuple<cpp_int, cpp_int> getFactors(cpp_int p);
	cpp_int modularExp(cpp_int a, cpp_int b, cpp_int n);
	
};

