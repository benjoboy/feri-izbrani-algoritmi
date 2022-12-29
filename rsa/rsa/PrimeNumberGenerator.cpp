#include "PrimeNumberGenerator.h"
#include <tuple>
#include <iostream>

using namespace std;

cpp_int PrimeNumberGenerator::naive(int numOfBits) {
	while (true) {
		cpp_int p = getRandom(pow(cpp_int(2), numOfBits - 1), pow(cpp_int(2), numOfBits) - 1);

		if (p % 2 == 0) {
			p++;
		}
		if (naiveTest(p)) {
			return p;
		}
	}
}

bool PrimeNumberGenerator::naiveTest(cpp_int p) {
	while (true) {
		cpp_int j = 3;

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

cpp_int PrimeNumberGenerator::millerRabin(int numOfBits, int s) {
	while (true) {
		cpp_int p = getRandom(pow(cpp_int(2), numOfBits - 1), pow(cpp_int(2), numOfBits) - 1); //not sure
		if (p % 2 == 0) {
			p++;
		}
		if (millerRabinTest(p, s)) {

			return p;
		}
	}
}

bool PrimeNumberGenerator::millerRabinTest(cpp_int p, int s) {
	if (p <= 3)
		return true;
	if (p % 2 == 0)
		return false;

	auto tuple = getFactors(p);
	cpp_int d = get<0>(tuple);
	cpp_int k = get<1>(tuple);

	for (int j = 1; j <= s; j++) {
		cpp_int a = getRandom(2, p - 2);

		cpp_int x = modularExp(a, d, p);
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

tuple<cpp_int, cpp_int> PrimeNumberGenerator::getFactors(cpp_int p) {
	cpp_int d = p - 1;
	cpp_int k = 0;
	while (d % 2 == 0) {
		d /= 2;
		k++;
	}
	return make_tuple(d, k);
}


cpp_int PrimeNumberGenerator::modularExp(cpp_int num, cpp_int pow, cpp_int mod)
{
	cpp_int d = 1;
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


