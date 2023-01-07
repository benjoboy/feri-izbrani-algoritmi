#include "LinearSystemSolver.h"
#include <fstream>
#include <iostream>

LinearSystemSolver::LinearSystemSolver() {
	size = 0;
	matrix = NULL;
	A = NULL;
}

void LinearSystemSolver::gaussElimination() {
	for (int k = 0; k < size - 2; k++) {
		// find the lowest element in column thats not 0
		int m = -1;
		for (int i = k+1; i < size - 1; i++) {
			if (matrix[i * size + k] != 0 && m == -1)
			{
				m = i;
			}
			if ((matrix[i * size + k] < matrix[m * size + k]) && matrix[i * size + k] != 0) {
				m = i;
			}
		}
		if (m == -1 && (k + 1 < size -1)) {
			//throw
			cout << "Error: Matrix is singular" << m << endl;
			return;
		}
		float mkVal = matrix[m * size + k];
		cout << "m: " << m << "val: " << mkVal << endl;
		for (int i = 0; i < size; i++) {
			float temp = matrix[k * size + i];
			matrix[k * size + i] = matrix[m * size + i] / mkVal;
			matrix[m * size + i] = temp;
		}

		for (int l = k + 1; l < size - 1; l++) {
			float ikVal = matrix[l * size + k];

			for (int j = 0; j < size; j++) {
				matrix[l * size + j] = matrix[l * size + j] - ikVal * matrix[k * size + j];
			}
		}
		printMatrix();
	}
	/*if (matrix[size * size + size] == 0) {
		cout << "Ann is zero\n";
		return;
	}*/
	if (matrix[(size - 1) * size - 1] == 0) {
		cout << "Ann is zero\n";
		return;
	}
	A[size - 2] = matrix[(size-2)*size + size - 1] / matrix[(size - 2) * size + size - 2];
	for (int i = size-3; i >= 0; i--) {
		float sum = 0;
		for (int j = i + 1; j < size-1; j++) {
			sum += matrix[i * size + j] * A[j];
		}
		A[i] = (matrix[i * size + size-1] - sum) / matrix[i * size + i];
	}

}

void LinearSystemSolver::readMatix(string filename)
{
	ifstream file(filename);
	file >> size;
	size++;
	matrix = new float[(size - 1) * size];
	A = new float[size-1];

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size; j++)
		{
			file >> matrix[i * size + j];
		}
	}

}

void LinearSystemSolver::printMatrix() {
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrix[i * size + j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}

}

void LinearSystemSolver::printA() {
	{
		for (int i = 0; i < size-1; i++)
		{
			cout << "x" << i + 1 << " = " << A[i] << " " << endl;
		}
		cout << endl;
	}
	{
	}
}