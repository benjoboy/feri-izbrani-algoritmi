#pragma once
class RandomGenerator
{
public:
	RandomGenerator();
	unsigned long long getRandom(unsigned long long min, unsigned long long max);
	unsigned long long lcg();
	unsigned long long m = 4294967295;
	unsigned long long a = 69069;
	unsigned long long b = 0;
	unsigned long long rn = 1;
};


