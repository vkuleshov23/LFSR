#ifndef _AUTOCOR_
#define _AUTOCOR_
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

class Autocor {
public:
	static void test(std::vector<int> NUMS, int dimension, int d) {
		std::vector<double> result;
		int counter = (NUMS.size() * dimension)-d;
		for(int d = 1; d < counter/2; d++) {
			autocor(NUMS, dimension, d, result);
		}
		std::ofstream fout;
		fout.open("autocor.txt");
		for(int i = 0; i < result.size(); i++){
			fout  << i+1 << " " << result[i] << '\n';
		} fout.close();
		std::cout << "------------------------------\n\tAUTOCOR TEST: \n";
		system("./plot.sh autocor.txt 2> /tmp/backet.txt");
		std::cout << "done!\n";
	}
private:
	static void autocor(std::vector<int> NUMS, int dimension, int d, std::vector<double>& result) {
		int sum = 0;
		double counter = (NUMS.size() * dimension)-d;
		for(int i = 0; i < counter; i++){
			sum += XOR(NUMS, dimension, i, d);
		}
		// std::cout << "A(d): " << sum << '\n';
		double res = (2*(sum - ((counter)/2)))/sqrt(counter);
		// std::cout << "RESULT: " << abs(res) << '\n';
		result.push_back(res);
	}
	
	static int XOR(std::vector<int> NUMS, int dimension, int i, int d){
		int blockPos1 = i/dimension;
		int blockPos2 = (i+d)/dimension;
		int bitPos1 = i%dimension;
		int bitPos2 = (i+d)%dimension;
		
		bool first = (NUMS[blockPos1] & (256>>bitPos1))?true:false;
		bool second = (NUMS[blockPos2] & (256>>bitPos2))?true:false;

		int res = (first != second)?1:0;
		// std::cout << "\t1: block:" << blockPos1 << "| bit:" << bitPos1 << '\n';
		// std::cout << "\t2: block:" << blockPos2 << "| bit:" << bitPos2 << '\n';
		// std::cout << i << ": " << (res) << '\n';
		return res;
	}
};

#endif