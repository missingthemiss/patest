// pat1008.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main() {
	int currentFloor = 0;
	int nextFloor, n, time = 0;
	cin >> n;
	for (int i = 0; i<n; ++i) {
		cin >> nextFloor;
		time += currentFloor>nextFloor ? (currentFloor - nextFloor) * 4 + 5 : (nextFloor - currentFloor) * 6 + 5;
		currentFloor = nextFloor;
	}
	cout << time;
	return 0;
}
