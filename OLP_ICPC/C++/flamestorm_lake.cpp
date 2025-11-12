#include <bits/stdc++.h>
#define startt ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long  ll;
using namespace std;
#define vint vector<int>
#define all(v) v.begin(), v.end()
#define MOD 1000000007
#define MOD2 998244353
#define MX 1000000000
#define MXL 1000000000000000000
#define PI (ld)2*acos(0.0)
#define pb push_back
#define sc second
#define fr first
#define endl '\n'
#define ld long double
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl

int n, m;
bool vis[1005][1005];
int a[1005][1005];

int dfs(int i, int j) {
	vis[i][j] = true;
	int ans = a[i][j];
	if (i && a[i - 1][j] && !vis[i - 1][j]) ans += dfs(i - 1, j);
	if (i != n - 1 && a[i + 1][j] && !vis[i + 1][j]) ans += dfs(i + 1, j);
	if (j && a[i][j - 1] && !vis[i][j - 1]) ans += dfs(i, j - 1);
	if (j != m - 1 && a[i][j + 1] && !vis[i][j + 1]) ans += dfs(i, j + 1);
	return ans;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			vis[i][j] = false;
			cin >> a[i][j];
		}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!vis[i][j] && a[i][j]) ans = max(ans, dfs(i, j));
	cout << ans << endl;
}

int32_t main(){
    startt
    int t = 1;
    cin >> t;
    while (t--) solve();
}