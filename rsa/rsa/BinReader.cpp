//#include "stdafx.h"
#include "BinReader.h"
#include <string>
#include <iostream>

BinReader::BinReader(std::string in){
	ifd.open(in, std::ios::binary);
	ifd.seekg(0, std::ios::end);
	size = ifd.tellg() * 8;
	pointer = 0;
	ifd.seekg(0, std::ios::beg);


	std::cout << "size: " << size;
}


BinReader::~BinReader(){
	if (ifd.is_open()) {
		ifd.close();
	}
}

bool BinReader::readBit(bool &end) {
	if (x < 0) {
		if (ifd.get(var) && (pointer < size-1) && !ifd.eof()) {
			x = 7;
			if (ifd.eof()) {
				std::cout << "HERE" << std::endl;
				ifd.close();
				end = true;
				return NULL;
			}

		}
		else {
			ifd.close();
			end = true;
			return NULL;
		}
	}
	bool bit = (var >> x) & 1;
	x--;
	pointer++;
	end = false;
	return bit;
}

char BinReader::readByte() {
	char byte;
	for (int i = 0; i < 8; i++) {
		bool end;
		bool b = readBit(end);
		if (b) {
			byte |= 1 << i;
		}
		else {
			byte &= ~(1 << i);
		}
		//byte ^= (-b ^ byte)&(128 >> i);
	}
	return byte;
}

int BinReader::readInt() {
	int integer;
	for (int i = 31; i >= 0; i--) {
		bool end;
		bool bit = readBit(end);
		if (bit) {
			integer |= 1 << i;
		}
		else
			integer &= ~(1 << i);
	}
	return integer;


}

float BinReader::readFloat() {
	float a = *(float*)readInt();
		return a;
}

bool BinReader::isOpen() {
	return ifd.is_open();
}

unsigned long long BinReader::readNumOfBits(int numOfBits, bool& end) {
	unsigned long long number = 0;
	end = false;
	
	for (int i = numOfBits - 1; i >= 0; i--) {
	
		bool endBit;
		bool bit = readBit(endBit);
		if (endBit) {
			std::cout << "bit is null\n";
			end = true;
			return number;
		}
		if (bit) {
			std::cout << "1 ";
			number |= 1ULL << i;
		}
		else
		{
			std::cout << "0 ";

			number &= ~(1ULL << i);
		}
	}
	std::cout << "\n";
	return number;
}

