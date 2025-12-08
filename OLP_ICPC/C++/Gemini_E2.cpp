#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

// Function to calculate (base^exp) % mod
ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n;
    ll m, p_mod;
    cin >> n >> m >> p_mod;

    // Special case m=1: probability is 1, all subsegments are palindromes.
    if (m == 1) {
        ll total = (ll)n * (n + 1) / 2;
        total %= p_mod;
        cout << (total * total) % p_mod << "\n";
        return;
    }

    // Calculate probability p = m^(-1) mod P
    ll p = power(m, p_mod - 2, p_mod);

    // Precompute powers of p: p^0, p^1, ..., p^n
    vector<ll> pp(n + 1);
    pp[0] = 1;
    for (int i = 1; i <= n; ++i) pp[i] = (pp[i - 1] * p) % p_mod;

    // Precompute prefix sums for S_c and Q_c calculations
    // pref_p[k] = sum_{r=0}^k p^r
    // pref_linear[k] = sum_{r=0}^k (2r+1)p^r (for integer centers)
    // pref_linear_odd[k] = sum_{r=1}^k (2r-1)p^r (for half-integer centers)
    vector<ll> pref_p(n + 1);
    vector<ll> pref_linear(n + 1);
    vector<ll> pref_linear_odd(n + 1);

    pref_p[0] = 1; 
    pref_linear[0] = 1; 
    pref_linear_odd[0] = 0; 

    for (int r = 1; r <= n; ++r) {
        pref_p[r] = (pref_p[r - 1] + pp[r]) % p_mod;
        
        ll term = (2LL * r + 1) % p_mod * pp[r] % p_mod;
        pref_linear[r] = (pref_linear[r - 1] + term) % p_mod;

        ll term_odd = (2LL * r - 1) % p_mod * pp[r] % p_mod;
        pref_linear_odd[r] = (pref_linear_odd[r - 1] + term_odd) % p_mod;
    }

    ll sum_E = 0; // Sum of E[X_c]
    ll sum_Correction = 0; // Sum of Var(X_c) = Sum(E[X_c^2] - E[X_c]^2)

    // Iterate over Integer Centers (indices 1 to n)
    for (int i = 1; i <= n; ++i) {
        // Max radius is limited by distance to boundaries
        int K = min(i - 1, n - i);
        
        ll S = pref_p[K]; // E[X_c]
        ll Q = pref_linear[K]; // E[X_c^2]
        
        // C = Var(X_c) = Q - S^2
        ll C = (Q - (S * S) % p_mod + p_mod) % p_mod;
        
        sum_E = (sum_E + S) % p_mod;
        sum_Correction = (sum_Correction + C) % p_mod;
    }

    // Iterate over Half-integer Centers (gaps between indices)
    // There are n-1 gaps: between 1-2, 2-3, ..., (n-1)-n
    for (int j = 1; j < n; ++j) {
        int K = min(j, n - j);
        
        // Sum starts from radius r=1.
        // pref_p[K] includes r=0 (val 1), so subtract 1.
        ll S = (pref_p[K] - 1 + p_mod) % p_mod;
        ll Q = pref_linear_odd[K];
        
        ll C = (Q - (S * S) % p_mod + p_mod) % p_mod;
        
        sum_E = (sum_E + S) % p_mod;
        sum_Correction = (sum_Correction + C) % p_mod;
    }

    // Final result: (Sum E)^2 + Sum Var
    ll ans = (sum_E * sum_E) % p_mod;
    ans = (ans + sum_Correction) % p_mod;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}