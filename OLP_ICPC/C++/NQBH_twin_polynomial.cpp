#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int m = 1000000007;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, num_free = 0;
		cin >> n;
		vector<int> a(n + 1), b; // b consists of undetermined element of a
		for (int& x : a) {
			cin >> x;
			if (x == -1) ++num_free;
		}
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		if (n == 2) {
			if (a[1] == -1) cout << 3 << '\n';
			else if (a[1] <= 2) cout << 1 << '\n';
			else cout << 0 << '\n';
			continue;
		}
		if (num_free == n + 1) { // all a_i = -1
			vector<ll> dp(n + 1); // dp[i] = number of cool polynomials with a_i possibly = 0 additionally
			dp[0] = 1; // a[0] computed is 1 cool polynomial or a[0] := 0 if not yet determined
			dp[1] = 2;
			for (int i = 2; i <= n; ++i)
				dp[i] = (2 * dp[i - 1] + (i - 1) * dp[i - 2]) % m;
			ll ans = (dp[n] - dp[n - 1]) % m;
			cout << ans << '\n';
			continue;
		}
		bool ok = true;
		for (int i = 1; i < n; ++i) {
			if (a[i] > n) { // a[i] <= n for all i in [n] since deg f = deg g = n
				ok = false;
				break;
			} else if (a[i] == 0) {
				if (a[0] == -1) a[0] = i;
				else a[0] += i;
			} else if (a[i] == i); // i * x^i: done
			else if (a[i] != -1) { // a[i] = j
				if (a[a[i]] == -1) a[a[i]] = i; // a[j] = i
				else if (a[a[i]] != i) { // a_i != a_j uncool polynomial
					ok = false;
					break;
				}
			}
		}
		if (!ok) {
			cout << 0 << '\n';
			continue;
		}
		b.push_back(a[0] != -1 ? a[0] : 0);
		for (int i = 1; i <= n; ++i)
			if (a[i] == -1) b.push_back(i);
		if (b.size() == 1) { // no undetermined coefficients
			cout << 1 << '\n';
			continue;
		} else {
			int b_sz = b.size();
			/*
			cout << "debug\n";
			for (int i = 0; i < b_sz; ++i) cout << b[i] << " ";
			cout << "debug\n";
			*/
			if (b_sz == 1) {
				if (b[0] == 0) cout << 1 << '\n'; // a[0] = 0
				else cout << 0 << '\n';
			} else {
				vector<ll> dp(b_sz); // dp[i] = number of cool polynomials considered upto b[i]
				dp[0] = 1;
				dp[1] = 2;
				if (b[b_sz - 1] < n) {
					for (int i = 2; i < b_sz; ++i)
						dp[i] = (2 * dp[i - 1] + (i - 1) * dp[i - 2]) % m;
					cout << dp[b_sz - 1] << '\n';
				} else { // b[b_sz - 1] == n
					for (int i = 2; i < b_sz - 1; ++i)
						dp[i] = (2 * dp[i - 1] + (i - 1) * dp[i - 2]) % m;
					dp[b_sz - 1] = (dp[b_sz - 2] + (b_sz - 2) * dp[b_sz - 3]) % m;
					cout << dp[b_sz - 1] << '\n';
				}
				/*
				cout << "debug\n";
				for (int i = 0; i < b_sz; ++i) cout << dp[i] << " ";
				cout << "debug\n";
				*/
			}
		}
	}
}