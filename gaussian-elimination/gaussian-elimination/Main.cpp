#include "LinearSystemSolver.h"

using namespace std;

int main(int argc, char** argv) {
	LinearSystemSolver solver = LinearSystemSolver();
	solver.readMatix("problem1Gaus.txt");
	solver.printMatrix();
	

	return 0;
}
