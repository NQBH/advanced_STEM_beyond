#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

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

// Function to calculate modular inverse
ll modInverse(ll n, ll mod) {
    return power(n, mod - 2, mod);
}

void solve() {
    int n;
    ll m, p_mod;
    cin >> n >> m >> p_mod;

    // Special case for m=1: beauty is always (number of subsegments)^2
    if (m == 1) {
        ll num = (ll)n * (n + 1) / 2;
        num %= p_mod;
        cout << (num * num) % p_mod << "\n";
        return;
    }

    // Calculate p = m^(-1) mod P
    ll p = modInverse(m, p_mod);
    
    // Precompute powers of p: p^0, p^1, ..., p^n
    vector<ll> pp(n + 1);
    pp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pp[i] = (pp[i - 1] * p) % p_mod;
    }

    ll tot_sum = 0;      // Sum over all c of S_c
    ll tot_sq_sum = 0;   // Sum over all c of (S_c)^2
    ll tot_diag = 0;     // Sum over all c of D_c (diagonal term)

    // Iterate over all possible centers.
    // Centers are at indices 1, 1.5, 2, ..., n.
    // We represent a center c by c_double = 2*c.
    // Integer centers: 2, 4, ..., 2n.
    // Half-integer centers: 3, 5, ..., 2n-1.
    for (int c_double = 2; c_double <= 2 * n; ++c_double) {
        ll current_S = 0;
        ll current_D = 0;
        
        if (c_double % 2 == 0) {
            // Integer center c
            int c = c_double / 2;
            // Max radius (number of edges) corresponds to distance to nearest boundary
            int K = min(c - 1, n - c);
            
            // For integer center, r ranges from 0 to K.
            // S_c = sum_{r=0}^K p^r
            for (int r = 0; r <= K; ++r) {
                current_S = (current_S + pp[r]) % p_mod;
            }
            // D_c = sum_{r=0}^K (2r+1) * p^r
            for (int r = 0; r <= K; ++r) {
                ll term = (ll)(2 * r + 1) * pp[r];
                current_D = (current_D + term) % p_mod;
            }
        } else {
            // Half-integer center c = i + 0.5
            int i = (c_double - 1) / 2;
            // Max radius K is such that i-K+1 >= 1 and i+K <= n
            // Intervals are [i-r+1, i+r]
            int K = min(i, n - i);
            
            // For half center, r ranges from 1 to K.
            // S_c = sum_{r=1}^K p^r
            for (int r = 1; r <= K; ++r) {
                current_S = (current_S + pp[r]) % p_mod;
            }
            // D_c = sum_{r=1}^K (2r-1) * p^r
            for (int r = 1; r <= K; ++r) {
                ll term = (ll)(2 * r - 1) * pp[r];
                current_D = (current_D + term) % p_mod;
            }
        }

        tot_sum = (tot_sum + current_S) % p_mod;
        
        ll sq = (current_S * current_S) % p_mod;
        tot_sq_sum = (tot_sq_sum + sq) % p_mod;
        
        tot_diag = (tot_diag + current_D) % p_mod;
    }

    // Result = (sum S)^2 - sum S^2 + sum D
    ll term1 = (tot_sum * tot_sum) % p_mod;
    ll ans = (term1 - tot_sq_sum + tot_diag) % p_mod;
    
    if (ans < 0) ans += p_mod;

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