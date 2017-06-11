// pat1009.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct poly{
	int exp;
	double coe;
};
int main()
{
	vector<poly> p1,p2,p3;
	int k1, k2;
	
	cin >> k1;
	p1.resize(k1);
	for (int i = 0; i < k1;i++) {
		cin >> p1[i].exp >> p1[i].coe;
	}
	cin >> k2;
	p2.resize(k2);
	for (int i = 0; i < k2; i++) {
		cin >> p2[i].exp >> p2[i].coe;
	}
	p3.resize(p1[0].exp+p2[0].exp+1);
	for (int i = 0; i <p3.size();++i) {
		p3[i].exp = i;
		p3[i].coe = 0;
	}
	int k3 = 0;
	for (int i = 0; i < k1; ++i) {
		for (int j = 0; j < k2; ++j) {
			//if (p3[p1[i].exp + p2[j].exp].coe == 0)k3++;
			p3[p1[i].exp + p2[j].exp].coe += p1[i].coe*p2[j].coe;
		}
	}
	for (int i = p3.size() - 1; i >= 0; --i) {
		if (p3[i].coe != 0) {
			k3++;
		}
	}
	cout << k3 ;
	if (k3 > 0) {
		for (int i = p3.size()-1; i >= 0; --i) {
			if (p3[i].coe != 0) {
				cout << ' ' << p3[i].exp << ' ' <<setprecision(1)<<fixed<< p3[i].coe;
			}
		}
	}
    return 0;
}

