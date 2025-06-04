#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 20;
ll fact[MAXN + 1];

void prepare() {
	fact[0] = 1;
	for (int i = 1; i <= MAXN; i++)
		fact[i] = fact[i - 1] * i;
}

// Tìm p(n, k): hoán vị thứ k (1-based) của {1..n}
vector<int> kth_permutation(int n, ll k) {
	vector<int> result;
	vector<int> unused(n); // functionality: unused(n) = (1, 2, ..., n)
	for (int i = 0; i < n; i++)
		unused[i] = i + 1;

	ll rank = k - 1; // chuyển sang 0-based
	for (int i = n; i >= 1; i--) {
		ll f = fact[i - 1];  // (i-1)!
		ll index = rank / f; // tìm phần tử ở vị trí index
		rank = rank % f;     // giảm rank để xử lý tiếp
		result.push_back(unused[index]);
		unused.erase(unused.begin() + index);
	}
	return result;
}

// Tìm k (1-based) cho hoán vị pi của độ dài n
ll permutation_index(int n, const vector<int> &pi) {
	ll idx = 0; // 0-based index
	vector<int> unused(n);
	for (int i = 0; i < n; i++)
		unused[i] = i + 1;

	for (int i = 0; i < n; i++) {
		// Tìm vị trí của pi[i] trong unused
		int val = pi[i];
		int pos = int(lower_bound(unused.begin(), unused.end(), val) -
		              unused.begin());
		// Có pos phần tử nhỏ hơn val chưa dùng
		idx += pos * fact[n - 1 - i];
		// Xóa val khỏi unused
		unused.erase(unused.begin() + pos);
	}
	return idx + 1; // chuyển sang 1-based
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	prepare();

	int t;
	cin >> t;
	while (t--) {
		int type;
		cin >> type;
		if (type == 1) {
			int n;
			ll k;
			cin >> n >> k;
			vector<int> ans = kth_permutation(n, k);
			for (int x : ans) {
				cout << x << ' ';
			}
			cout << "\n";
		} else if (type == 2) {
			int n;
			cin >> n;
			vector<int> pi(n);
			for (int i = 0; i < n; i++) {
				cin >> pi[i];
			}
			ll k_idx = permutation_index(n, pi);
			cout << k_idx << "\n";
		}
	}
	return 0;
}