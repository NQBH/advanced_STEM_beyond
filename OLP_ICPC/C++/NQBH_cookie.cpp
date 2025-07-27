#include <iostream>
using namespace std;
#define ll long long

int main() {
	ll n, a, ans = 0;
	cin >> n >> a;
	for (ll i = 2; i * i < n; ++i) {
		if (n % i == 0) {
			ans += i + a; // eat
			ans += n / i;
			break;
		}
	}
	cout << ans;
}