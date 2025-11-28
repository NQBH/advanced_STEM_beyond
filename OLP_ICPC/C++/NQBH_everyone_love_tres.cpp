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
		if (n == 1 || n == 3) cout << "-1\n";
		else if (n & 1) {
			string s = "36366";
			for (int i = 0; i < n - 5; ++i) s = '3' + s;
			cout << s << '\n';
		} else {
			string s = "66";
			for (int i = 0; i < n - 2; ++i) s = '3' + s;
			cout << s << '\n';
		}		
	}
}