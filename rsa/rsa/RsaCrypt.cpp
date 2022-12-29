#include "RsaCrypt.h"
#include "RandomGenerator.h"
#include "BinReader.h"
#include "BinWriter.h"
#include <iostream>
#include <vector>

#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

template <typename T>
T modpow(T base, T exp, T modulus) {
	base %= modulus;
	T result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}

RsaCrypt::RsaCrypt()
{
	e = 0;
	d = 0;
	n = 0;
}

void RsaCrypt::writeKeysToFile() {
	std::ofstream myfile;
	myfile.open("privkey.txt");
	myfile << d << " " << n;
	myfile.close();
	myfile.open("pubkey.txt");
	myfile << e << " " << n;
	myfile.close();

}

void RsaCrypt::getKeysFromFile() {
	std::ifstream myfile;
	myfile.open("privkey.txt");
	myfile >> d >> n;
	myfile.close();
	myfile.open("pubkey.txt");
	myfile >> e;
	myfile.close();


}

void RsaCrypt::generateKeys(int keyLength) {
	{
		cpp_int p = primeGenerator.millerRabin(keyLength, 10);
		cpp_int q = primeGenerator.millerRabin(keyLength, 10);
		cpp_int n = p * q;
		cpp_int phi = (p - 1) * (q - 1);
		cpp_int e = primeGenerator.getRandom(1, phi - 1);
		while (true) {
			e = primeGenerator.getRandom(1, phi - 1);
			std::cout << e << std::endl;
			if (gcd(e, phi) == 1)
				break;
		}
		cpp_int d = modularLinearEquationSolver(e, 1, phi);

		if (e <= 1 || d == NULL || n < 1)
		{
			std::cout << "something is wrong with keys generation" << std::endl;
			std::cout << "e: " << e << std::endl;
			std::cout << "d: " << d << std::endl;
			std::cout << "n: " << n << std::endl;

		}

		this->e = e;
		this->n = n;
		this->d = d;
		writeKeysToFile();
	}
}

cpp_int RsaCrypt::gcd(cpp_int a, cpp_int b) {
	{
		if (b == 0) {
			return a;
		}
		else {
			return gcd(b, a % b);
		}
	}
}

cpp_int RsaCrypt::modularLinearEquationSolver(cpp_int a, cpp_int b, cpp_int n) {
	cpp_int x, y;
	cpp_int d = extendedEuclid(a, n, x, y);
	if (d % b == 0) {
		x = (x * (b / d)) % n;
		for (int i = 0; i < d; i++) {
			cpp_int xe = (x + i * (n / d)) % n;
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

cpp_int RsaCrypt::extendedEuclid(cpp_int a, cpp_int b, cpp_int& x, cpp_int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		cpp_int x1, y1;
		cpp_int d = extendedEuclid(b, a % b, x1, y1);
		x = y1;
		y = x1 - y1 * (a / b);
		return d;
	}

}

void RsaCrypt::encryptFile(std::string filename) {
	cpp_bin_float_100 numOfBitsReal = boost::multiprecision::log2(cpp_bin_float_100(n));
	cpp_bin_float_100 numOfBitsLow = floor(numOfBitsReal);
	cpp_bin_float_100 numOfBitsHigh = ceil(numOfBitsReal);
	cpp_int numOfBitsIn;
	cpp_int numOfBitsOut;

	numOfBitsIn = cpp_int(numOfBitsLow);
	numOfBitsOut = cpp_int(numOfBitsHigh);

	BinReader in(filename);
	BinWriter out("encrypted.bin");

	while (in.isOpen()) {
		bool end;
		cpp_int x = in.readNumOfBits(numOfBitsIn, end);
		if (end)
			break;
		x = modpow(x, this->e, this->n);
		out.writeNumOfBits(x, numOfBitsOut);

	}
}

void RsaCrypt::decryptFile(std::string filename) {
	cpp_bin_float_100 numOfBitsReal = boost::multiprecision::log2(cpp_bin_float_100(n));
	cpp_bin_float_100 numOfBitsLow = floor(numOfBitsReal);
	cpp_bin_float_100 numOfBitsHigh = ceil(numOfBitsReal);
	cpp_int numOfBitsIn;
	cpp_int numOfBitsOut;

	numOfBitsIn = cpp_int(numOfBitsLow);
	numOfBitsOut = cpp_int(numOfBitsHigh);

	BinReader in("encrypted.bin");
	BinWriter out(filename);

	while (in.isOpen()) {
		bool end;
		cpp_int x = in.readNumOfBits(numOfBitsOut, end);
		if (end)
			break;
		x = modpow(x, this->d, this->n);
		out.writeNumOfBits(x, numOfBitsIn);
	}

}
