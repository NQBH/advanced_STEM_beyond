#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAXN = 200005;

// Global arrays for number theoretic functions
int omega[MAXN];
int mu[MAXN];
int min_prime[MAXN];
vector<int> primes;

// Linear Sieve to compute omega and mu
void sieve() {
    mu[1] = 1;
    omega[1] = 0;
    for (int i = 2; i < MAXN; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            primes.push_back(i);
            omega[i] = 1;
            mu[i] = -1;
        }
        for (int p : primes) {
            if (p > min_prime[i] || (long long)i * p >= MAXN) break;
            min_prime[i * p] = p;
            if (min_prime[i] == p) {
                omega[i * p] = omega[i];
                mu[i * p] = 0;
            } else {
                omega[i * p] = omega[i] + 1;
                mu[i * p] = -mu[i];
            }
        }
    }
}

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Data structures per test case
int cnt[8][MAXN];  // cnt[p][T]: count of nums divisible by T with omega = p
int V[MAXN][15];   // V[T][S]: precomputed convolution term
int pow_k[16];     // Precomputed powers S^k
int freq[MAXN];    // Frequency of each number in input

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    // Reset frequency array
    for (int i = 0; i <= n; ++i) freq[i] = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        freq[val]++;
    }

    // Precompute small powers
    for (int i = 0; i <= 14; ++i) {
        pow_k[i] = power(i, k);
    }

    // Clear and compute cnt[p][T]
    // Iterating multiples takes O(N log N)
    for (int p = 0; p <= 7; ++p) {
        for (int T = 1; T <= n; ++T) cnt[p][T] = 0;
    }

    for (int T = 1; T <= n; ++T) {
        for (int j = T; j <= n; j += T) {
            if (freq[j] > 0) {
                cnt[omega[j]][T] += freq[j];
            }
        }
    }

    // Clear V array
    for (int T = 1; T <= n; ++T) {
        for (int s = 0; s <= 14; ++s) V[T][s] = 0;
    }

    // Compute V[T][S] = sum_{d|T} mu(d) * (S - omega[T/d])^k
    // We iterate i acting as d, and T as multiples of i.
    // This is effectively calculating the Dirichlet convolution.
    for (int i = 1; i <= n; ++i) {
        if (mu[i] == 0) continue;
        for (int T = i; T <= n; T += i) {
            int w = omega[T/i]; // omega(G) where G = T/d
            int mu_val = mu[i];
            for (int s = 0; s <= 14; ++s) {
                if (s >= w) {
                    int term = pow_k[s - w];
                    if (mu_val == 1) {
                        V[T][s] = (V[T][s] + term);
                        if (V[T][s] >= MOD) V[T][s] -= MOD;
                    } else {
                        V[T][s] = (V[T][s] - term);
                        if (V[T][s] < 0) V[T][s] += MOD;
                    }
                }
            }
        }
    }

    long long total_sum = 0;
    
    // Combine results
    // Ans = sum_{T} sum_{p, q} cnt[p][T] * cnt[q][T] * V[T][p+q]
    for (int T = 1; T <= n; ++T) {
        for (int p = 0; p <= 7; ++p) {
            if (cnt[p][T] == 0) continue;
            for (int q = 0; q <= 7; ++q) {
                if (cnt[q][T] == 0) continue;
                
                long long pairs = (long long)cnt[p][T] * cnt[q][T] % MOD;
                int s = p + q;
                // s is at most 14
                long long term = pairs * V[T][s] % MOD;
                total_sum = (total_sum + term) % MOD;
            }
        }
    }

    // The total_sum includes pairs (i, j), (j, i) and (i, i).
    // We need to subtract diagonal (i, i) and divide by 2.
    long long diag_sum = 0;
    for (int x = 1; x <= n; ++x) {
        if (freq[x] > 0) {
            // omega(x*x) = omega(x)
            long long term = (long long)freq[x] * pow_k[omega[x]] % MOD;
            diag_sum = (diag_sum + term) % MOD;
        }
    }

    long long ans = (total_sum - diag_sum + MOD) % MOD;
    long long inv2 = power(2, MOD - 2);
    ans = ans * inv2 % MOD;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}