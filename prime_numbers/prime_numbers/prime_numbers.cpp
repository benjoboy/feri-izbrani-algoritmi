#include <iostream>
#include "PrimeNumberGenerator.h"
#include <string>
#include <chrono>

using namespace std;

char menu();
void testMillerRabin(PrimeNumberGenerator& g, int numOfBits, int s);
void testNaive(PrimeNumberGenerator& g, int numOfBits);

int main()
{
	PrimeNumberGenerator p;

	bool running = true;
	char izbira;
	int numOfBits = 8;
	int s = 3;


	while (running) {
		cout << "Number of bits: " << numOfBits << endl;
		cout << "S: " << s << endl;
		izbira = menu();

		switch (izbira) {
		case '1':
			cout << "Enter number of bits: ";
			cin >> numOfBits;
			break;
		case '2':
			cout << p.naive(numOfBits) << endl;
			break;
		case '3':
			cout << "Enter s: ";
			cin >> s;
			break;
		case '4':
			cout << "---------------------" << endl;
			cout << p.millerRabin(numOfBits, s) << endl << endl;
			break;
		case '5':
			testNaive(p, numOfBits);
		break; case '6':
			testMillerRabin(p, numOfBits, s);
			break;
		case '0':
			running = 0;
			break;
		default:
			cout << "Ta izbira ne obstaja!\n";
		}
	}
}

char menu() {

	cout << endl;
	cout << "Prastevila\n";
	cout << "1) Velikost stevila\n";
	cout << "2) Naivna metoda\n";
	cout << "3) Nastavi s za miller-rabinovo metodo\n";
	cout << "4) Miller-robinova metoda\n";
	cout << "5) Testiraj naivno metodo\n";
	cout << "6) Testiraj miller rabinovo metodo\n";
	cout << "0) Konec\n";
	cout << endl;
	cout << "Izbira: ";

	string selection;
	do
	{
		if (!getline(cin, selection))
		{
			return 0;
		}
	} while (selection.length() == 0);
	return selection[0];
}

void testMillerRabin(PrimeNumberGenerator& g, int numOfBits, int s) {
	int numOfTests = 1000;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < numOfTests; i++) {
		g.millerRabin(numOfBits, s);
		//cout << g.millerRabin(numOfBits, s) << endl;
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	cout << "MillerRabin average: " << duration.count() / 100 << endl;
}

void testNaive(PrimeNumberGenerator& g, int numOfBits) {
	{
		int numOfTests = 1000;
		auto start = chrono::high_resolution_clock::now();
		for (int i = 0; i < numOfTests; i++) {
			g.naive(numOfBits);
			//cout << g.naive(numOfBits) << endl;
		}
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

		cout << "Naive average: " << duration.count()/100 << endl;
	}
}
