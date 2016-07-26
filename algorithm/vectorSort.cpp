#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
short main() {
	vector<short> v;
	for (short i = 0; i < 20; i++)
		v.push_back(i);

	random_shuffle(v.begin(), v.end());

	for (short i = 0; i < 20; i++) cout << v[i] << " ";
	cout << endl;

	sort(v.begin(), v.end());

	for (short i = 0; i < 20; i++) cout << v[i] << " ";
	cout << endl;
	return 0;
}