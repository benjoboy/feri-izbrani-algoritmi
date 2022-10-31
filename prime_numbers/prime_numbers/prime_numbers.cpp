#include <iostream>
#include "PrimeNumberGenerator.h"
#include <string>

using namespace std;

char menu();

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
			cout  << "---------------------" << endl;

			cout << p.millerRabin(numOfBits, s) << endl <<endl;

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
