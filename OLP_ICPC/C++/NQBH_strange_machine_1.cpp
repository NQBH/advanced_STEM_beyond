#include <iostream>
#include <vector>
using namespace std;
const int MAX_TIME = 1000000;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		vector<int> a(q);
		for (int &x : a) cin >> x;

		bool allA = true ; // s is full of A
		for (char c : s)
			if (c == 'B') {
				allA = false;
				break;
			}
		if (allA) {
			for (int &x : a) cout << x << '\n';
			continue;
		}

		bool allB = true; // s is full of B
		for (char c : s)
			if (c == 'A') {
				allB = false;
				break;
			}
		if (allB) {
			for (int &x : a) cout << __lg(x) + 1 << '\n';
			continue;
		}

		for (int &x : a) { // process a[i]
			int ans = 0;
			bool done = false;
			for (int time = 1; time <= MAX_TIME; ++time) {
				for (int i = 0; i < n; ++i) {
					if (x == 0) {
						done = true;
						break;
					}
					if (s[i] == 'A') --x;
					else x /= 2;
					++ans;
				}
				if (done) break;
			}
			cout << ans << '\n';
		}
	}
}