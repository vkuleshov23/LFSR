#ifndef _FREQUENCY_
#define _FREQUENCY_
#include <vector>
#include <iostream>

class Frequency {
public:
	static void test(std::vector<int> NUMS, int dimension) {
		int ONE = 0, ZERO = 0;
		for(int i = 0; i < NUMS.size(); i++){
			for(int j = 0; j < dimension; j++) {
				if(NUMS[i] & (256>>j)){
					ONE++;
				} else {
					ZERO++;
				}
			} 
		}
		double counter = NUMS.size() * dimension;
		std::cout << "------------------------------\n\tFREQUENCY TEST:\n";
		std::cout << "0: " << ZERO << " | 1: " << ONE << " | all: " << counter << '\n';
		std::cout << "P(0): " << (double)ZERO/counter << " | P(1): " << (double)ONE/counter << '\n';
		std::cout << "RESULT: " << (double(ZERO-ONE)* double(ZERO-ONE))/ double(NUMS.size()*dimension) << '\n';
	}
};

#endif