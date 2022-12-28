#pragma once

#include <fstream>
#include <string>

class BinReader
{
public:
	std::ifstream ifd;
	char var=0;
	int x=-1;

	
	BinReader(std::string in);
	~BinReader();

	bool readBit(bool &end);
	char readByte();
	int readInt();
	float readFloat();
	bool isOpen();
	unsigned long long readNumOfBits(int numOfBits, bool &end);
};

