#pragma once
#include <string>

using namespace std;

class LinearSystemSolver
{
public:
	LinearSystemSolver();
	double* matrix;
	double* A;
	int size;
	void gaussElimination();
	void readMatix(string filename);
	void printMatrix();
	void printA();
};

