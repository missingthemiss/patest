// pat1001.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a, b,c;
	char str_ans[20];
	cin >> a >> b;
	c = a + b;
	if (c < 0) {
		cout << '-';
		c = -c;
	}
	int i = 0;
	char tmp;
	while (c > 0) {
		if (i%4==3) {
			str_ans[i]=',';
			i++;
			continue;
		}

		tmp = c % 10 + '0';
		str_ans[i] = tmp;
		c = c / 10;
		++i;
	}
	i--;
	for (; i >= 0; --i)cout << str_ans[i];
	cin >> a;
    return 0;
}

