#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

int t;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		for (char &c : s) if (c == 'q') c = 'p'; else if (c == 'p') c = 'q';
		cout << s << '\n';
	}
}