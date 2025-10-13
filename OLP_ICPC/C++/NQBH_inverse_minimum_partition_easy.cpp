#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;


		cout << ans << '\n';
	}
}