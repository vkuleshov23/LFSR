#ifndef _SERIES_
#define _SERIES_
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Series {
public:	
	static void test(vector<int> NUMS, int dimension) {
		double ei[6] = {0};
		double patternsONE[6] = {0};
		double patternsZERO[6] = {0};
		double counter = NUMS.size() * dimension;
		int size = 3;
		double res = 0.0;
		for(int i = 1; i <= size; i++) {
			ei[i] = e(i, counter);
			// cout << "ei" << i << ": " << ei[i] << '\n';
			patternsONE[i] = countingPatterns(i, NUMS, dimension, 1);	
			// cout << "patternsONE" << i << ": " << patternsONE[i] << '\n';
			patternsZERO[i] = countingPatterns(i, NUMS, dimension, 0);	
			// cout << "patternsZERO" << i << ": " << patternsZERO[i] << '\n';
			res = sum(patternsONE, ei, size) + sum(patternsZERO, ei, size);
		}
		std::cout << "------------------------------\n\tSERIES TEST: \n";
		std::cout << "RESULT: " << res << '\n';
	}
private:

	static double sum(double* patterns, double* e, int size){
		double sum = 0.0;
		for(int i = 1; i <= size; i++) {
			sum += ((patterns[i] - e[i]) * (patterns[i] - e[i])) / e[i];
			// cout << "sum: "<< sum << '\n';
		}
		return sum;
	} 

	static double e(int i, int n) {
		double a = double(n-i+3);
		double b = double(pow(2, (i+2)));
		double c = a/b;
		return c;
	}

	static int countingPatterns(int n, vector<int> NUMS, int dimension, bool number) {
		int patterns = 0, count = 0;
		bool flag = true;
		for(int i = 0; i < NUMS.size(); i++){
			for(int j = 0; j < dimension; j++) {
				
				flag = (NUMS[i] & (int(pow(2, dimension-1))>>j))?true:false;

				if(flag == number){
					// cout << "PUCK\n";
					count++;
				} else {
					// cout << "NE PUCK\n";
					if(count == n){
						// cout << "count: " << count << " i: " << i << '\n';
						patterns++;
					}
					count = 0;
				}
			}
		}
		if(count == n){
			patterns++;
		}
		return patterns;
	}
};

#endif