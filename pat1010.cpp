// pat1010.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

long long convertToDecimal(int  num[][2], int tag, long long radix) {
	long long ans=0;
	for (int j = 1; j <= num[0][tag-1]; ++j) {
		ans = ans*radix;
		ans+=num[j][tag - 1];
		if (ans < 0)return -1;
	}
	return ans;
}
int main()
{
	int num[12][2];
	char c;
	int tag,untag,radixTag_int,minRadix;
	long long inDec;

	for (int j = 0; j < 2; ++j) {
		int i = 1;
		c = cin.get();
		while (c != ' ') {
			if (c >= 'a' &&c <= 'z') {
				num[i][j] = c - 'a'+10;
			}
			else {
				num[i][j] = c - '0';
			}
			c = cin.get();
			i++;
		}
		num[0][j] = i - 1;
	}
	cin >> tag >> radixTag_int;
	untag = 1;
	if (tag == 1)untag = 2;
	inDec = convertToDecimal(num,tag, radixTag_int);

	minRadix = 0;
	for (int i = 1; i <= num[0][untag - 1]; ++i) {
		minRadix = minRadix < num[i][untag - 1]+1 ? num[i][untag - 1] + 1 : minRadix;
	}
	
	bool possible=false;
	long long min, mid, max,sumMid;
	min = minRadix;
	max = inDec>minRadix?inDec:minRadix;

	while (min <= max) {
		mid = (min + max)/2;
		sumMid = convertToDecimal(num, untag, mid);
		if(sumMid==-1|| sumMid>inDec){
			max = mid-1;
			continue;
		}
		if (sumMid < inDec) {
			min = mid+1;
			continue;
		}
		possible = true;
		break;
	}
	if (num[0][untag-1] == 1)mid = minRadix;
	if (possible)cout << mid;
	else cout << "Impossible";
    return 0;
}

