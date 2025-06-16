/*
Source: ACM 2000, Northeastern European Regional Programming Contest (test tour).
IDs for online judges: Ural 1068.
Status: Accepted
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n <= 0) {
		n = -n;
		cout << -n * (n + 1) / 2 + 1;
	}
	else
		cout << n * (n + 1) / 2;
}