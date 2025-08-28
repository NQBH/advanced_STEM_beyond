#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAX_POS = 100;

int main() {
	int a, b, c, d, total = 0;
	cin >> a >> b >> c >> d;
	vector<bool> painted(MAX_POS + 1);
	for (int i = a; i < b; ++i) painted[i] = true; // add Farmer John's painted interval
	for (int i = c; i < d; ++i) painted[i] = true; // add Bessie's painted interval
	for (bool i : painted) total += i; // count the total amount of intervals painted
	cout << total << '\n';
}