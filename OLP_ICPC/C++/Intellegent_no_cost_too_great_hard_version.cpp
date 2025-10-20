#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int uid(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}

ll uld(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(rng);
}

const int N = 2e5 + 10;
vector<vector<int>> pfac(N + 1); // pre-calculated prime divisors with Sieve of Eratosthenes

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int x, int y) -> bool{
		return b[x] < b[y];
	});
	int ans = b[ord[0]] + b[ord[1]];
	map<int, int> cnt;
	for (int i = 0; i < n; ++i)
		for (int x : pfac[a[i]]) {
			if (cnt[x] > 0) ans = 0;
			++cnt[x];
		}
	for (int i = 0; i < n; ++i) {
		for (int x : pfac[a[i]]) --cnt[x];
		for (int x : pfac[a[i] + 1])
			if (cnt[x] > 0) ans = min(ans, b[i]);
		for (int x : pfac[a[i]]) ++cnt[x];
	}
	int idx = ord[0];
	vector<int> check;
	for (int i = 0; i < n; ++i) {
		if (i == idx) continue;
		for (int x : pfac[a[i]]) check.push_back(x);
	}
	for (int x : check) {
		int times = x - (a[idx] % x);
		if (times == x) times = 0;
		ans = min(1LL * ans, 1LL * times * b[idx]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i <= N; ++i) {
    	if (!pfac[i].empty()) continue;
    	for (int j = i; j <= N; j += i) pfac[j].push_back(i);
    }
	int t;
	cin >> t;
	while (t--) solve();
}