// pat1005.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{
	char n;
	int sum = 0;
	int digit = 0;
	vector<string> numInEnglish;
	numInEnglish.resize(20);
	numInEnglish[0] = "zero";
	numInEnglish[1] = "one";
	numInEnglish[2] = "two";
	numInEnglish[3] = "three";
	numInEnglish[4] = "four";
	numInEnglish[5] = "five";
	numInEnglish[6] = "six";
	numInEnglish[7] = "seven";
	numInEnglish[8] = "eight";
	numInEnglish[9] = "nine";
	n = cin.get();
	while (n!='\n') {
		sum += n-'0';
		n = cin.get();
	}
	if (sum == 0) {
		cout << "zero";
		return 0;
	}
	int sum2 = sum;
	while (sum > 0) {
		sum /= 10;
		digit++;
	}
	for (int i = digit; i > 0; --i) {
		int numDigit = sum2 / pow(10, i-1);
		sum2 -= numDigit*pow(10, i-1);
		cout << numInEnglish[numDigit];
		if(i!=1) cout<< " ";
	}
    return 0;
}

