#pragma once
#include "PrimeNumberGenerator.h"


class RsaCrypt {
private:
	PrimeNumberGenerator primeGenerator;
	unsigned long long e;
	unsigned long long n;
	unsigned long long d;
public:
	RsaCrypt();
	void generateKeys(int keyLength);
	unsigned long long extendedEuclid(unsigned long long a, unsigned long long b, unsigned long long& x, unsigned long long& y);
	unsigned long long gcd(unsigned long long a, unsigned long long b);
	unsigned long long modularLinearEquationSolver(unsigned long long a, unsigned long long b, unsigned long long n);
	void writeKeysToFile();
	void getKeysFromFile();
	void encryptFile();
	void decryptFile();
};