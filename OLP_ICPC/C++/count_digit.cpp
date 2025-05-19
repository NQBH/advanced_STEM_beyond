#include <iostream>
using namespace std;

int count_digit(int x, int k) {
	if (x == 0 && k == 0)
		return 1;
	int ans = 0;
	while (x) {
		if (x % 10 == k)
			++ans;		
		x /= 10;
	}
	return ans;
}

int main() {
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
	}
	cout << count_digit(14, 1);
}