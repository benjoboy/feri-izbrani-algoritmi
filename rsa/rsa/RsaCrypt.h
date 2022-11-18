#pragma once
#include "PrimeNumberGenerator.h"


class RsaCrypt {
private:
	PrimeNumberGenerator primeGenerator;
	unsigned long long e;
	unsigned long long n;
	unsigned long long d;
	unsigned int keyLength = 15;
public:
	RsaCrypt();
	void generateKeys();
	unsigned long long extendedEuclid(unsigned long long a, unsigned long long b, unsigned long long& x, unsigned long long& y);
	unsigned long long gcd(unsigned long long a, unsigned long long b);
	unsigned long long modularLinearEquationSolver(unsigned long long a, unsigned long long b, unsigned long long n);
		
};