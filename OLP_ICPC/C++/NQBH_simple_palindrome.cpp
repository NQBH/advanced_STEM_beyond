#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s = "aeiou";
		int f = n / 5, r = n % 5;
		for (int i = 0; i < f; ++i) cout << s;
		for (int i = 0; i < r; ++i) cout << s[i];
		cout << '\n';
	}
}