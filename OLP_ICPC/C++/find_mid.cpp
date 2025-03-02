#include <iostream>
using namespace std;

long long diff = 1e18;
long long get_sum(int a, int b) {
	return (a*1LL + b*1LL) * (b*1LL - a*1LL + 1)/2;
}

int main() {
	int l, r, ans;
	cin >> l >> r;
	int L = l, R = r;
	while (L <= R) {
		int mid = (L + R)/2;
		long long left_sum = get_sum(l, mid);
		long long right_sum = get_sum(mid + 1, r);
		if (diff > abs(left_sum - right_sum)) {
			diff = abs(left_sum - right_sum);
			ans = mid;
		}
		if (left_sum < right_sum) L = mid + 1;
		else R = mid - 1;
	}
	cout << ans;
}