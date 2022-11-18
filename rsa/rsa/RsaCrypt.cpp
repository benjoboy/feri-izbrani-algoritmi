#include "RsaCrypt.h"
#include "RandomGenerator.h"
#include <iostream>

RsaCrypt::RsaCrypt()
{
	generateKeys();
}

void RsaCrypt::generateKeys() {
	{
		unsigned long long p = primeGenerator.millerRabin(keyLength, 10);
		unsigned long long q = primeGenerator.millerRabin(keyLength, 10);
		unsigned long long n = p * q;
		unsigned long long phi = (p - 1) * (q - 1);
		unsigned long long e = primeGenerator.getRandom(1, phi - 1);
		while (true) {
			e = primeGenerator.getRandom(1, phi - 1);
			if (gcd(e, phi) == 1)
				break;	
		}
		unsigned long long d = modularLinearEquationSolver(e, 1, phi);
		
		if( e<=1 || d == NULL || n< 1)
		{
			std::cout << "something is wrong with keys generation" << std::endl;
			std::cout << "e: " << e << std::endl;
			std::cout << "d: " << d << std::endl;
			std::cout << "n: " << n << std::endl;
		
		}
		this->e = e;
		this->n = n;
		this->d = d;
	}
}

unsigned long long RsaCrypt::gcd(unsigned long long a, unsigned long long b) {
	{
		if (b == 0) {
			return a;
		}
		else {
			return gcd(b, a % b);
		}
	}
}

unsigned long long RsaCrypt::modularLinearEquationSolver(unsigned long long a, unsigned long long b, unsigned long long n) {
	unsigned long long x, y;
	unsigned long long d = extendedEuclid(a, n, x, y);
	if (d % b == 0) {
		x = (x * (b / d)) % n;
		for (int i = 0; i < d; i++) {
			unsigned long long xe = (x + i * (n / d)) % n;
			if (xe < 0)
				return xe + n;
			else
				return xe;
		}
	}
	else {
		return NULL;
	}
}

unsigned long long RsaCrypt::extendedEuclid(unsigned long long a, unsigned long long b, unsigned long long& x, unsigned long long& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		unsigned long long x1, y1;
		unsigned long long d = extendedEuclid(b, a % b, x1, y1);
		x = y1;
		y = x1 - y1 * (a / b);
		return d;
	}
	
}
