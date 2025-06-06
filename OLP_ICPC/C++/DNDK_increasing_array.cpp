#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long tang = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			tang += a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}
	cout << tang;
}