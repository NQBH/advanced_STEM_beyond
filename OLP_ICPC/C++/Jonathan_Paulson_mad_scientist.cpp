#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n, ans = 0;
	cin >> n;
	string A, B;
	cin >> A >> B;
	bool mismatched = false;
	for (ll i = 0; i < n; ++i)
		if (A[i] != B[i]) {
			if (!mismatched) {
				mismatched = true;
				++ans;
			}
		} else mismatched = false;
	cout << ans << '\n';
}