#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int n;
	cin >> n;
	if (n % 2 != 0) cout << 0 << endl;
	else {
		ll ans = 1;
		for (ll i = 1; i <= (n / 2); ++i) {
			ans *= 2;
		}
		cout << ans;
	}
}

