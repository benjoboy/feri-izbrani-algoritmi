#pragma once
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

class RandomGenerator
{
public:
	RandomGenerator();
	cpp_int getRandom(cpp_int min, cpp_int max);
	cpp_int lcg();
	cpp_int m = 4294967295;
	cpp_int a = 69069;
	cpp_int b = 0;
	cpp_int rn = 1;
};


