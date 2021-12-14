#ifndef _POKER_
#define _POKER_
#include <vector>
#include <iostream>
#include <cmath>

class Poker {
public:
	static void test(std::vector<int> NUMS, int dimension, int m) {
		double counter = NUMS.size() * dimension;
		int k = int(counter / m);
		int number = 0, count = 0;
		std::vector<int> Ni = vec(m);

		int ONE = 0, ZERO = 0;
		for(int i = 0; i < NUMS.size(); i++){
			for(int j = 0; j < dimension; j++) {
				if(count == m){
					count = 0;
					Ni[number] += 1;
					number = 0;
				}
				if(NUMS[i] & (int(pow(2, dimension-1))>>j)){
					number ^= 1<<count;
				}
				count++;
			} 
		}
		Ni[number] += 1;
		std::cout << "------------------------------\n\tPOKER TEST: \n";
		printNi(Ni, m);
		double result = ((pow(2, m) / k) * sum(Ni)) - k;
		std::cout << "RESULT: " << result << '\n';
	}
private:
	static double sum(std::vector<int> Ni) {
		double sum = 0.0;
		for(int i = 0; i < Ni.size(); i++) {
			sum += pow(Ni[i],2);
		}
		return sum;
	}
	static void printNi(std::vector<int> Ni, int m) {
		for(int i = 0; i < Ni.size(); i++) {
			std::cout << "N" << i << "(";
			for(int j = m-1; j >= 0; j--) {
				std::cout << (i & (1<<j)?'1':'0');
			}
			std::cout << ") : " << Ni[i] << '\n';
		}
	}
	static std::vector<int> vec(int m) {
		std::vector<int> res;
		for(int i = 0; i < pow(2, m); i++) {
			res.push_back(0);
		}
		return res;
	}
};

#endif