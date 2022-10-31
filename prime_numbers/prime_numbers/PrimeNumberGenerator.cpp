#include "PrimeNumberGenerator.h"
#include <cmath>
#include <tuple>
#include <iostream>

using namespace std;

unsigned int PrimeNumberGenerator::naive(int numOfBits) {
	while (true) {
		unsigned int p = getRandom(2, pow(2, numOfBits)); //not sure

		if (p % 2 == 0) {
			p++;
		}
		if (naiveTest(p)) {
			return p;
		}
	}
}

bool PrimeNumberGenerator::naiveTest(unsigned int p) {
	while (true) {
		unsigned int j = 3;

		while (j < sqrt(p))
		{
			if (p % j == 0) {
				break;
			}
			j += 2;
		}

		if (j > sqrt(p)) {
			return true;
		}
		else return false;
	}
}

unsigned int PrimeNumberGenerator::millerRabin(int numOfBits, int s) {
	while (true) {
		unsigned int p = getRandom(2, pow(2, numOfBits)); //not sure
		if (p % 2 == 0) {
			p++;
		}
		if (millerRabinTest(p, s)) {

			return p;
		}
	}
}

bool PrimeNumberGenerator::millerRabinTest(unsigned int p, int s) {
	if (p <= 3)
		return true;
	if (p % 2 == 0)
		return false;

	auto tuple = getFactors(p);
	unsigned int d = get<0>(tuple);
	unsigned int k = get<1>(tuple);

	for (int j = 1; j < s; j++) {
		unsigned int a = getRandom(2, p - 2);

		unsigned int x = modularExp(a, d, p);
		if (x == 1) {
			return true;
		}
		for (int r = 1; r < s; r++) {
			x = modularExp(x, 2, p);
			if (x == 1) {
				return false;
			}
			if (x == p - 1) {
				break;
			}
		}
		if (x != p - 1) {
			return false;
		}
	}
	return true;
}

tuple<unsigned int, unsigned int> PrimeNumberGenerator::getFactors(unsigned int p) {
	unsigned int  d = p - 1;
	unsigned int k = 0;
	while (d % 2 != 0) {
		d /= 2;
		k++;
	}
	return make_tuple(d, k);
}


unsigned int PrimeNumberGenerator::modularExp(unsigned int num, unsigned int pow, unsigned int mod)
{

	int d = 1;
	while (pow > 0) {


		if ((pow & 1) == 1) {
			d = ((d % mod) * (num % mod)) % mod;
		}
		num = ((num % mod) * (num % mod)) % mod;

		pow = pow >> 1;
	}
	return d;
}


