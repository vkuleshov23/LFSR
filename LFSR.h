#ifndef _LFSR_
#define _LFSR_
#include <iostream>
#include <cmath>

class LFSR {

private:

	unsigned int NUMBER = 0b000000001;
	unsigned int POLYNOM = 0b100001000;

public:
	
	LFSR(unsigned int polynom) {
		this->POLYNOM = polynom;
	}

	LFSR(){}

	void setPolynom(unsigned int polynom) {
		this->POLYNOM = polynom;
		this->NUMBER = 0b000000001;
	}

	void printBin() {
		for(int i = 0; i < 9; i++) {
			std::cout << (this->NUMBER & (int(pow(2, 8))>>i)?'1':'0');
		}
		// std::cout << '\n';
	}
	void print() {
		std::cout << this->NUMBER << '\n';
	}
	unsigned int shift() {
		if(this->NUMBER & 0b000000001) {
			this->NUMBER = (((this->NUMBER >> 1) ^ this->POLYNOM));
		} else {
			this->NUMBER >>= 1;
		}
		return this->NUMBER;
	}
	~LFSR(){}
};

#endif