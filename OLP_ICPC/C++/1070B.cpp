#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		bool h0 = false;
		for (char c : s)
			if (c == '0') {
				h0 = true;
				break;
			}
		if (!h0) {
			cout << "0\n";
			continue;
		}
		string a = s + s;
		int max0 = 0, curr0 = 0;
		for (char c : a)
			if (c == '0') ++curr0;
			else {
				max0 = max(max0, curr0);
				curr0 = 0;
			}
		max0 = max(max0, curr0);
		cout << max0 << '\n';
	}
}