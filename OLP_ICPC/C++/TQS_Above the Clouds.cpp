#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t; cin >> t;
	while (t--) {
		ll n ; cin >> n;
		string s;
		cin >> s;
		map<char, ll> a;
		bool kq = false;
		for (ll i = 1; i < n - 1; ++i) a[s[i]]++;
		for (auto it = a.begin(); it != a.end(); ++it) {
			if ((*it).second > 1) {
				kq = true;
			}
		}
		if (a[s[0]] == 1 or a[s[n - 1]] == 1) {
			cout << "YES" << "\n";
			continue;
		}
		if (kq) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}
