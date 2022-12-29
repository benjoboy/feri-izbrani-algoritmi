#pragma once
#include "PrimeNumberGenerator.h"
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

class RsaCrypt {
private:
	PrimeNumberGenerator primeGenerator;
	cpp_int e;
	cpp_int n;
	cpp_int d;
public:
	RsaCrypt();
	void generateKeys(int keyLength);
	cpp_int extendedEuclid(cpp_int a, cpp_int b, cpp_int& x, cpp_int& y);
	cpp_int gcd(cpp_int a, cpp_int b);
	cpp_int modularLinearEquationSolver(cpp_int a, cpp_int b, cpp_int n);
	void writeKeysToFile();
	void getKeysFromFile();
	void encryptFile(std::string filename);
	void decryptFile(std::string filename);
};