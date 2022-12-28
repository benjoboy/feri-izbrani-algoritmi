#include "RsaCrypt.h"
#include <iostream>
#include <string>

using namespace std;

char menu();

int main()
{
	RsaCrypt rsaCrypt = RsaCrypt();

	bool running = true;
	char izbira;
	int numOfBits = 8;
	int s = 3;
	string filename;


	while (running) {
		cout << "Number of bits: " << numOfBits << endl;
		izbira = menu();

		switch (izbira) {
		case '1':
			cout << "Enter number of bits: \n";
			cin >> numOfBits;
			rsaCrypt.generateKeys(numOfBits);
			break;
		case '2':
			rsaCrypt.getKeysFromFile();
			break;
		case '3':
			cout << "Enter filename: \n";
			cin >> filename;
			rsaCrypt.encryptFile(filename);
			break;
		case '4':
			cout << "Enter out filename: \n";
			cin >> filename;
			rsaCrypt.decryptFile(filename);
			break;
		case '5':
		break; case '6':
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
	cout << "RSA\n";
	cout << "1) Generate keys\n";
	cout << "2) Read keys from file\n";
	cout << "3) Encode file\n";
	cout << "4) Decode file\n";
	cout << "5) \n";
	cout << "6) \n";
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