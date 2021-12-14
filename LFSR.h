#ifndef _LFSR_
#define _LFSR_
#include <iostream>

class LFSR {

private:

	unsigned int NUMBER = 0b000000001;
	unsigned int POLINOM = 0b100001000;
	unsigned int supply = 0b100000000;

public:
	
	LFSR(unsigned int polinom) {
		this->POLINOM = polinom;
	}

	LFSR(){}

	void printBin() {
		for(int i = 0; i < 9; i++) {
			std::cout << (this->NUMBER & (256>>i)?'1':'0');
		}
		// std::cout << '\n';
		
		// for(int i = 0; i < 9; i++) {
		// 	std::cout << (this->POLINOM & (256>>i)?'1':'0');
		// } std::cout << '\n';
		// std::cout << " : " << this->POLINOM << '\n';
	}
	void print() {
		std::cout << this->NUMBER << '\n';
	}
	unsigned int shift() {
		if(this->NUMBER & 0b000000001) {
			this->NUMBER = (((this->NUMBER >> 1) ^ this->POLINOM));
		} else {
			this->NUMBER >>= 1;
		}
		return this->NUMBER;
	}
};

#endif