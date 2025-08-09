#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == x) {
			cout << i << ' ' << i;
			return 0;
		}
	}
	int l = 0, r = 1; // left- & right pointers
	int sum = a[0] + a[1];
	while (sum != x) {
		if (sum < x && r == n - 1) {
			cout << "Impossible";
			return 0;
		}
		if (sum < x && r < n - 1) sum += a[++r];
		if (sum > x && l < n - 1) sum -= a[l++];
	}
	cout << l << ' ' << r;
}