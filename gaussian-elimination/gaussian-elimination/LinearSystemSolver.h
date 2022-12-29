#pragma once
#include <string>

using namespace std;

class LinearSystemSolver
{
public:
	LinearSystemSolver();
	float* matrix;
	int size;
	void gausElimination();
	void readMatix(string filename);
	void printMatrix();
};

