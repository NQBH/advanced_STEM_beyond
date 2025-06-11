#include <iostream>
#define ll long long
using namespace std;
ll mod = 10000000007;
int main() {
	ll n;
	cin >> n;
	ll x = 1;
	for (ll i = 0; i < n; i++) {
		x = x * 2;
		x = x % mod;
	}
	cout << x;
}