#include "LinearSystemSolver.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	LinearSystemSolver solver = LinearSystemSolver();
	solver.readMatix("test2.txt");
	solver.printMatrix();
	cout << "solve the system\n";
	solver.gaussElimination();
	solver.printA();

	return 0;
}
