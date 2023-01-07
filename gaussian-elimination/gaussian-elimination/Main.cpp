#include "LinearSystemSolver.h"
#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char** argv) {
	LinearSystemSolver solver = LinearSystemSolver();
	//cout << sizeof(float) * 8 << "   " << sizeof(double)*8 << endl;
	//solver.printMatrix();
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10; i++)
	{
		solver.readMatix("test2.txt");
		solver.gaussElimination();
	}
	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;


	solver.printA();

	return 0;
}


//  1 1				test3 01
//
