// pat1002.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	int k, nk;
	double ak;
	static double ans[1001];
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> nk >> ak;
		ans[nk] += ak;
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> nk >> ak;
		ans[nk] += ak;
	}
	int total = 0;
	string re;
	for (int i = 0; i < 1001; ++i) {
		if (ans[i] != 0)total++;
	}
	cout << total;
	if (total > 0) {
		for (int i = 1001; i >= 0; --i) {
			if (ans[i] != 0)cout << ' ' << i <<' '<< fixed<<setprecision(1)<<ans[i];
		}

	}
	cin >> total;
    return 0;
}

