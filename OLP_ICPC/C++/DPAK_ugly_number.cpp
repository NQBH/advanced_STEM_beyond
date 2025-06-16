/*
Source: New Zealand 1990, Division I.
IDs for online judges: POJ 1338, UVA 136.
Status: Time Limited Exceeded
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;

	vector<int> uglyNumber;
	int i;
	for (i = 1; uglyNumber.size() < 1500; i++) {
		int number = i;
		while (number % 2 == 0) {
			number /= 2;
		}
		while (number % 3 == 0) {
			number /= 3;
		}

		while (number % 5 == 0) {
			number /= 5;
		}
		if (number == 1) uglyNumber.push_back(i);
	}
	while (cin >> n && n != 0) {
		n--;
		cout << uglyNumber[n] << endl;
	}
}