#pragma once
#include <string>

using namespace std;

class LinearSystemSolver
{
public:
	LinearSystemSolver();
	float* matrix;
	float* A;
	int size;
	void gaussElimination();
	void readMatix(string filename);
	void printMatrix();
	void printA();
};

