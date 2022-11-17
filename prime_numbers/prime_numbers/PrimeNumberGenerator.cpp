#include "PrimeNumberGenerator.h"
#include <cmath>
#include <tuple>
#include <iostream>

using namespace std;

unsigned long long PrimeNumberGenerator::naive(int numOfBits) {
	while (true) {
		unsigned long long p = getRandom(pow(2, numOfBits - 1), pow(2, numOfBits) - 1);

		if (p % 2 == 0) {
			p++;
		}
		if (naiveTest(p)) {
			return p;
		}
	}
}

bool PrimeNumberGenerator::naiveTest(unsigned long long p) {
	while (true) {
		unsigned long long j = 3;

		while (j < sqrt(p))
		{
			if (p % j == 0) {
				return false;
			}
			j += 2;
		}
		return true;
	}
}

unsigned long long PrimeNumberGenerator::millerRabin(int numOfBits, int s) {
	while (true) {
		unsigned long long p = getRandom(pow(2, numOfBits - 1), pow(2, numOfBits) - 1); //not sure
		if (p % 2 == 0) {
			p++;
		}
		if (millerRabinTest(p, s)) {

			return p;
		}
	}
}

bool PrimeNumberGenerator::millerRabinTest(unsigned long long p, int s) {
	if (p <= 3)
		return true;
	if (p % 2 == 0)
		return false;

	auto tuple = getFactors(p);
	unsigned long long d = get<0>(tuple);
	unsigned long long k = get<1>(tuple);

	for (int j = 1; j <= s; j++) {
		unsigned long long a = getRandom(2, p - 2);

		unsigned long long x = modularExp(a, d, p);
		if (x == 1) {
			continue;
		}
		for (int i = 0; i < k; i++) {
			if (x == p - 1) {
				break;
			}

			x = modularExp(x, 2, p);

		}
		if (x != p - 1) {
			return false;
		}
	}
	return true;
}

tuple<unsigned long long, unsigned long long> PrimeNumberGenerator::getFactors(unsigned long long p) {
	unsigned long long  d = p - 1;
	unsigned long long k = 0;
	while (d % 2 == 0) {
		d /= 2;
		k++;
	}
	return make_tuple(d, k);
}


unsigned long long PrimeNumberGenerator::modularExp(unsigned long long num, unsigned long long pow, unsigned long long mod)
{
	unsigned long long d = 1;
	num = num % mod;
	while (pow > 0)
	{
		if (pow & 1)
			d = (d * num) % mod;
		pow = pow >> 1;
		num = (num * num) % mod;
	}
	return d;
}


