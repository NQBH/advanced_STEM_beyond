#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> primes;

// sieve of primes
void sieve() {
	const int MAXP = 1000000;
    vector<bool> is_prime(MAXP + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= MAXP; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= MAXP; j += i)
                is_prime[j] = false;
        }
    }
}

// factorize
set<ll> factorize(ll g) {
    set<ll> factors;
    while (g % 2 == 0) {
        factors.insert(2);
        g /= 2;
    }
    for (ll d = 3; d * d <= g && d <= 1000000; d += 2) {
        while (g % d == 0) {
            factors.insert(d);
            g /= d;
        }
    }
    if (g > 1) factors.insert(g);
    return factors;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		bool has_odd = false;
		for (ll &x : a) {
			cin >> x;
			if (x & 1) has_odd = true;
		}
		if (has_odd) {
			cout << "2\n";
			continue;
		}
		// all numbers are even
		// compute gcd of all elements in a
		ll g = a[0]; // g >= 2 since all numbers are even
		for (int i = 1; i < n; ++i) g = gcd(g, a[i]);
		set<ll> common_primes = factorize(g); // all common divisors of all a[i]
		ll ans = -1;
		for (ll p : primes)
			if (!common_primes.count(p)) {
				ans = p;
				break;
			}
		if (ans == -1) {
			ans = *common_primes.rbegin();
		}
		cout << ans << '\n';
	}
}