#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll S = 0;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
			S += x;
		}
		// ll S = accumulate(a.begin(), a.end(), 0); // somehow WA test 3 CF
		ll sq = sqrt(S);
		cout << (sq * sq == S ? "YES\n" : "NO\n");
	}
}