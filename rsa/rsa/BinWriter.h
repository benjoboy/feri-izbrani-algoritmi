#pragma once

#include <fstream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

class BinWriter
{
public:
	std::ofstream ofd;
	char var = 0; // temporarna spr., kjer hranimo 1 byte 
	int x = 0; // stevec bitov (od 0 do vkljucno 7)

	BinWriter(std::string out);
	~BinWriter();

	void writeBit(bool b);
	void writeByte(char b);
	void writeInt(int i);
	void writeFloat(float f);
	void setX(int i);
	void writeNumOfBits(cpp_int out, cpp_int numOfBits);

};

