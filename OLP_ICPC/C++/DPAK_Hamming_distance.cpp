#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int p2[32];

int BinaryToInt(string s) {
	reverse(s.begin(), s.end());
	int total = 0;
	for (int i = 0; i < static_cast<int>(s.size()); i++) {
		total += (s[i] - '0') * p2[i];
	}
	return total;
}

int countOneInBinary(int n) {
	int cnt = 0;
	while (n) {
		cnt += n % 2;
		n >>= 1;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string>s(n);
	vector<int> a;
	p2[0] = 1;
	for (int i = 1; i <= 31; i++) {
		p2[i] = p2[i - 1] * 2;
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		a.push_back(BinaryToInt(s[i]));
	}

	vector<int>b;

	int ans = INT_MAX;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			// countOneInBinary = TLE
			ans = min(ans, __builtin_popcount(a[i] ^ a[j]));
		}
	}

	cout << ans;
}