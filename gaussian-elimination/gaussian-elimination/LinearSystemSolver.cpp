#include "LinearSystemSolver.h"
#include <fstream>
#include <iostream>

LinearSystemSolver::LinearSystemSolver() {
	
}

void LinearSystemSolver::gausElimination() {
	
	
}

void LinearSystemSolver::readMatix(string filename)
{
	ifstream file(filename);
	file >> size;
	matrix = new float[size * size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			file >> matrix[i * size + j];
		}
	}
	
}

void LinearSystemSolver::printMatrix() {
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrix[i * size + j] << " ";
			}
			cout << endl;
		}
	}

}