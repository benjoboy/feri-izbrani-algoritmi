#pragma once
class RandomGenerator
{
public:
	RandomGenerator();
	unsigned int getRandom(unsigned int min, unsigned int max);
	unsigned int lcg();
	unsigned int m = 4294967295;
	unsigned int a = 69069;
	unsigned int b = 0;
	unsigned int rn = 1;
};


