#pragma once

#include <fstream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

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
	cpp_int readNumOfBits(cpp_int numOfBits, bool &end);
};

