// pat1007.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using std::cin;
using std::cout;
int main()
{
	int k, curSum,maxSum, maxStart, maxEnd,start,end;
	bool allNegative = true;
	cin >> k;
	int *seq = new int[k];
	for (int i = 0; i < k; ++i)cin >> seq[i];
	curSum = 0;
	maxSum = -1;
	start = 0;
	end = 0;
	maxStart = 0;
	maxEnd = 0;
	for (int i = 0; i < k; ++i) {
		curSum += seq[i];
		if (curSum > maxSum) {
			allNegative = false;
			maxEnd = i;
			maxStart = start;
			maxSum = curSum;
			continue;
		}
		if (curSum > 0)continue;
		
		
		if (curSum == 0) {
			allNegative = false;
		}
		else {
			start = i + 1;
			curSum = 0;
		}
		
	}
	if (maxSum<0) {
		maxSum = 0;
		maxStart = 0;
		maxEnd = k - 1;
	}
	
	cout <<maxSum<<' '<< seq[maxStart] << ' ' << seq[maxEnd];
	
    return 0;
}

