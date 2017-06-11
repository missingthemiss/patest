// pat1006.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Time {
public:
	
	int hour;
	int minute;
	int second;
	Time() {
	}
	Time(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	int earlythan(Time t) {
		if (t.hour > hour)return 1;
		if (t.hour < hour)return -1;
		if (t.minute > hour)return 1;
		if (t.minute < hour)return -1;
		if (t.second > second)return 1;
		if (t.second < second)return -1;
		return 0;
	}/*
	int operator=(Time t2) {
		this->hour = t2.hour;
		this->minute = t2.minute;
		this->second = t2.second;
		return 0;
	}*/
};

int main()
{
	int n;
	char c;
	cin >> n;
	Time earliest(25,0,0), latest(-1,0,0),come,leave;
	string unlockStu, lockStu,curStu;
	for (int i = 0; i < n; ++i) {
		cin >> curStu >> come.hour >> c >> come.minute >> c >> come.second >> leave.hour >> c >> leave.minute >> c >> leave.second;
		if (come.earlythan(earliest) == 1) {
			earliest = come;
			unlockStu = curStu;
		}
		if (leave.earlythan(latest) == -1) {
			latest = leave;
			lockStu = curStu;
		}
	}
	cout << unlockStu << " " << lockStu;
    return 0;
}

