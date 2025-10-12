#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, left_half_sum = 0, right_half_sum = 0;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> a;
	for (int i = 0; i < n / 2; ++i) {
		left_half_sum += a[i];
	}
	for (int i = n / 2; i < n; ++i) right_half_sum += a[i];
	cout << abs(left_half_sum - right_half_sum);
}