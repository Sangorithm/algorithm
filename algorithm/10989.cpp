#include<iostream>
using namespace std;
int main() {
	int total = 0,
		i = 0,
		j = 0;
	cin >> total;
	short * ary = new short[total];
	for (i = 0; i < total; i++) {
		cin >> ary[i];
		if (ary[i] <= 10000)
			continue;
		--i;
		--total;
	}
}