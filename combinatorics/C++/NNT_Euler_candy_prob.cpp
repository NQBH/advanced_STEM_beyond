// a, b
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <limits>
#include <climits>
#include <utility>
using namespace std;

// Type Aliases
typedef long long ll;
typedef pair<int, int> pii; 
typedef vector<int> vi;
typedef vector<ll> vll;

// Fast IO
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Common Macros
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

// Compute C(n, k)
ll comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;

    ll res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

// Solve Function
void solve() {
    int m, n;
    cin >> m >> n;
    vi s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    // Promote all x_i to be positive (i.e., assume x_i >= 1)
    // Add 1 to m for every x_i that is allowed to be 0 (s_i == 0)
    int count_zero_allowed = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 0) count_zero_allowed++;
    }

    int new_m = m + count_zero_allowed;

    ll ans = comb(new_m - 1, n - 1);
    cout << ans << '\n';
}

// Main
int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}