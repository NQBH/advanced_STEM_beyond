#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n + 1), b(n);
		for (auto& x : b) cin >> x;
		if (b[n - 1] == n) {
			for (int i = 1; i <= n; ++i) cout << 1 << " ";
			cout << '\n';
		}
		else if (b[n - 1] == n * (n + 1) / 2) { // used all numbers in [n]
			for (int i = 1; i <= n; ++i) cout << i << " ";
			cout << '\n';
		} else {
			/*
			for (int i = n; i >= 2; --i) {
				if (b[i] == i) // 1 1 ... 1 i times
					for (int j = 1; j <= i) a[j] = 1;
				else if (b[i] = i * (i + 1) / 2)
					for (int j = 1; j <= i) a[j] = j;
			}
			*/
			int next_val = 1;
			ll b_prev = 0;
			for (int i = 1; i <= n; ++i) {
				ll d = b[i - 1] - b_prev;
				int last_pos = i - (int)d;
				if (last_pos <= 0) a[i] = next_val++;
				else a[i] = a[last_pos];
				b_prev = b[i - 1];
			}
			for (int i = 1; i <= n; ++i) cout << a[i] << " ";
			cout << '\n';
		}
	}
}