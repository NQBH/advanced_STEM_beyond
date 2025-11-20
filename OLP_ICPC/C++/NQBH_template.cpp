#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cd = complex<double>;

const int MOD = 1e9 + 7;
const int base = 1000*1000*1000;
const double PI = acos(-1);

// #define macros
#define F first;
#define S second;
#define pb push_back;
#define mp make_pair;

// typedef
typedef long long ll;
typedef pair pp;
typedef vector vec;
typdef vector<int> lnum;

//-----------------------------------------------------------------------------//
// binary exponentiation: calculate a^n using O(log n) multiplications
//-----------------------------------------------------------------------------//

// recursive approach
ll binpow(ll a, ll b) {
	if (!b) return 1;
	ll res = binpow(a, b / 2);
	if (b & 1) return res * res * a;
	else return res * res;
}

// faster approach
ll binpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

// effective computation of large exponents modulo a number
ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

// apply a permutation k times: Given a sequence of length n. Apply to it a given permutation k times.
vector<int> applyPermutation(vector<int> sequence, vector<int> permutation) {
	vector<int> newSequence(sequence.size());
	for (int i = 0; i < sequence.size(); ++i) newSequence[i] = sequence[permutation[i]];
	return newSequence;
}

vector<int> permute(vector<int> sequence, vector<int> permutation, ll k) {
	while (k) {
		if (k & 1) sequence = applyPermutation(sequence, permutation);
		permutation = applyPermutation(permutation, permutation);
		k >>= 1;
	}
	return sequence;
}

//-----------------------------------------------------------------------------//
// binary search
//-----------------------------------------------------------------------------//

int binary_search(int A[], int sizeA, int target) {
	int lo = 1, hi = sizeA;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (A[mid] == target) return mid;
		else if (A[mid] < target) lo = mid + 1;
		else hi = mid - 1;
	}
	return -1;
}

int last_true(int lo, int hi, function<bool(int)> f) {
	// if none of the values in the range work, return lo -1
	--lo;
	while (lo < hi) {
		// find the middle of the current range (rounding up)
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) lo = mid; // if mid works, then all numbers smaller than mid also work
		else hi = mid - 1; // if mid does not work, greater values would not work either
	}
	return lo;
}

int last_true(int lo, int hi, function<bool(int)> f) {
	--lo;
	for (int dif = hi - lo; dif > 0; dif /= 2)
		while (lo + dif <= hi && f(lo + dif)) lo += dif;
	return lo;
}

//-----------------------------------------------------------------------------//
// bitwise operation
//-----------------------------------------------------------------------------//

// check if a bit is set
bool is_set(unsigned int n, int x) {
	return (n >> x) & 1;
}

// check if a number is divisible by a power of 2: n is divisible by 2^k exactly when n & (2^k - 1) = 0
bool is_divisible_by_power_of_2(int n, int k) {
	int pow_of_2 = 1 << k;
	return (n & (pow_of_2 - 1)) == 0;
}

// check if an integer is a power of 2

bool is_power_of_2(unsigned int n) {
	return n && !(n & (n - 1));
}

// Brian Kernighan's algorithm: count the number of bits set
int count_set_bit(int n) {
	int cnt = 0;
	while (n) {
		n &= (n - 1);
		++cnt;
	}
	return cnt;
}

// count set bits upto n: For numbers upto 2^x, i.e., [1, 2^x - 1], there are x * 2^{x - 1} set bits.
int count_set_bit(int n) {
	int cnt = 0;
	while (n) {
		int x = bit_width(n) - 1;
		cnt += x << (x - 1);
		n -= 1 << x;
		cnt += n + 1;
	}
	return cnt;
}

//-----------------------------------------------------------------------------//
// Chinese remainder theorem
//-----------------------------------------------------------------------------//

struct Congruence {
	ll a, m;
};

ll chinese_remainder_theorem(vector<Congruence> const& congruences) {
	ll M = 1;
	for (auto const& congruence : congruences) M *= congruence.m;
	ll sol = 0;
	for (auto const& congruence : congruences) {
		ll a_i = congruence.a, M_i = M / congruence.m, N_i = mod_inv(M_i, congruence.m);
		sol = (sol + a_i * M_i % M * N_i) % M;
	}
	return sol;
}

//-----------------------------------------------------------------------------//
// combinatorics
//-----------------------------------------------------------------------------//

int C2(int n) {
	return n * (n - 1) / 2;
}

ll C2(int n) {
	return 1LL * n * (n - 1) / 2;
}

ll C(int n, int k) {
	double res = 1;
	for (int i = 1; i <= k; ++i)
		res = res * (n - k + i) / i;
	return (ll)(res + 0.01);
}

int C(int n, int k) {
	double res = 1;
	for (int i = 1; i <= k; ++i)
		res = res * (n - k + i) / i;
	return (int)(res + 0.01);
}

//-----------------------------------------------------------------------------//
// divisor
//-----------------------------------------------------------------------------//

// number of divisors
ll num_divisor(ll n) {
	ll total = 1;
	for (int i = 2; (ll)i * i <= n; ++i)
		if (n % i == 0) {
			int e = 0;
			do {
				++e;
				n /= i;
			} while (n % i == 0);
			total *= e + 1;
		}
	if (n > 1) total *= 2;
	return total;
}

// sum of divisors
ll sum_divisor(ll n) {
	ll total = 1;
	for (int i = 2; (ll)i * i <= n; ++i)
		if (n % i == 0) {
			int e = 0;
			do {
				++e;
				n /= i;
			} while (n % i == 0);
			ll sum = 0, pow = 1;
			do {
				sum += pow;
				pow *= i;
			} while (e-- > 0);
			total *= sum;
		}
	if (n > 1) total *= 1 + n;
	return total;
}

//-----------------------------------------------------------------------------//
// DFS Depth First Search O(n + m)
//-----------------------------------------------------------------------------//

// simplest implementation of DFS
vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices
vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	for (int u : adj[v])
		if (!visited[u]) dfs(u);
}

// compute the entry & exit times & vertex color. Color all vertices with the color 0, if we have not visited them, with the color 1 if we visited them, & with the color 2, if we already exited the vertex
vector<vector<int>> adj; // raph represented as an adjacency list
int n, dfs_timer = 0; // number of vertices
vector<int> color, time_in, time_out;

void dfs(int v) {
	time_in[v] = dfs_timer++;
	color[v] = 1;
	for (int u : adj[v])
		if (!color[u]) dfs(u);
	color[v] = 2;
	time_out[v] = dfs_timer++;
}

//-----------------------------------------------------------------------------//
// discrete logarithm: int x satisfies equation a^x = b (mod m)
//-----------------------------------------------------------------------------//

// simplest implementation
int powmod(int a, int b, int m) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * 1ll * a) % m;
		a = (a * 1ll * a) % m;
		b >>= 1;
	}
	return res;
}

int solve(int a, int b, int m) {
	// if (a == 0) return b == 0 ? 1 : -1;
	a %= m, b %= m;
	int n = sqrt(m) + 1;
	map<int, int> vals;
	for (int p = 1; p <= n; ++p) vals[powmod(a, p * n, m)] = p;
	for (int q = 0; q <= n; ++q) {
		int cur = (powmod(a, q, m) * 1ll * b) % m;
		if (vals.count(cur)) {
			int ans = vals[cur] * n - q;
			return ans;
		}
	}
	return -1;
}

// improved implementation: return minimum x for which a ^ x % m = b % m, gcd(a, m) = 1: O(sqrt(m)) using unordered_map
int solve(int a, int b, int m) {
	a %= m, b %= m;
	int n = sqrt(m) + 1, an = 1;
	for (int i = 0; i < n; ++i) an = (an * 1ll * a) % m;
	unordered_map<int, int> vals;
	for (int q = 0; cur = b; q <= n; ++q) {
		vals[cur] = q;
		cur = (cur * 1ll * a) % m;
	}
	for (int p = 1, cur = 1; p <= n; ++p) {
		cur = (cur * 1ll * an) % m;
		if (vals.count(cur)) {
			int ans = n * p - vals[cur];
			return ans;
		}
	}
	return -1;
}

// return minimum x for which a ^ x % m = b % m: when a & m are not coprime: O(sqrt(m))
int solve(int a, int b, int m) {
	a %= m, b %= m;
    int k = 1, add = 0, g;
    while ((g = gcd(a, m)) > 1) {
    	if (b == k) return add;
    	if (b % g) return -1;
    	b /= g, m /= g, ++add;
    	k = (k * 1ll * a / g) % m;
    }
    int n = sqrt(m) + 1, an = 1;
    for (int i = 0; i < n; ++i) an = (an * 1ll * a) % m;
    unordered_map<int, int> vals;
	for (int q = 0, cur = b; q <= n; ++q) {
		vals[cur] = q;
		cur = (cur * 1ll * a) % m;
	}
	for (int p = 1, cur = k; p <= n; ++p) {
		cur = (cur * 1ll * an) % m;
		if (vals.count(cur)) {
			int ans = n * p - vals[cur] + add;
			return ans;
		}
	}
	return -1;
}

//-----------------------------------------------------------------------------//
// discrete root: given a prime n & 2 integers a, k, find all x for which x^k = a (mod n)
//-----------------------------------------------------------------------------//

/*
int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}
*/
int powmod(int a, int b, int p) {
	int res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

// find the primitive root modulo p
int generator(int p) {
	vector<int> fact;
	int phi = p - 1, n = phi;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			fact.push_back(i);
			while (n % i == 0) n /= i;
		}
	if (n > 1) fact.push_back(n);
	for (int res = 2; res <= p; ++res) {
		bool ok = true;
		for (int factor : fact)
			if (powmod(res, phi / factor, p) == 1) {
				ok = false;
				break;
			}
		if (ok) return res;
	}
	return -1;
}

//-----------------------------------------------------------------------------//
// extended Euclidean algorithm: find a way to represent gcd in terms of a & b, i.e., coefficients x, y for which ax + by = gcd(a, b)
//-----------------------------------------------------------------------------//

int egcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1, d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

// extended Euclidean algorithm iterative version: a little bit faster
int gcd(int a, int b, int &x, int &y) {
	x = 1, y = 0;
	int x1 = 0, y1 = 1, a1 = a, b1 = b;
	while (b1) {
		int q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
	return a1;
}

//-----------------------------------------------------------------------------//
// Euler's totient function phi(n) counts the number of integers between 1 & n inclusive, which are coprime to n
//-----------------------------------------------------------------------------//

// Euler's theorem: a^{phi(m)} = 1 (mod m) if gcd(a, m) = 1

// use factorization in O(sqrt(n))
int phi(int n) {
	int ans = n;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			ans -= ans / i;
		}
	if (n > 1) ans -= ans / n;
	return ans;
}

// Euler totient function from 1 to n in O(n log log n)
void phi_1_to_n(int n) {
	vector<int> phi(n + 1);
	for (int i = 0; i <= n; ++i) phi[i] = i;
	for (int i = 2; i <= n; ++i)
		if (phi[i] == i)
			for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
}

// find totient from 1 to n using divisor sum property
void phi_1_to_n(int n) {
	vector<int> phi(n + 1);
	phi[0] = 0, phi[1] = 1;
	for (int i = 2; i <= n; ++i) phi[i] = i - 1;
	for (int i = 2; i <= n; ++i)
		for (int j = 2 * i; j <= n; j += i) phi[j] -= phi[i];
}

//-----------------------------------------------------------------------------//
// factorial modulo p
//-----------------------------------------------------------------------------//

// compute n! mod p
int factmod(int n, int p) {
	vector<int> f(p);
	f[0] = 1;
	for (int i = 1; i < p; ++i) f[i] = f[i - 1] * i % p;
	int res = 1;
	while (n > 1) {
		if ((n / p) % 2) res = p - res;
		res = res * f[n % p] % p;
		n /= p;
	}
	return res;
}

// multiplicity of p: nu_p(n!)
int multiplicity_factorial(int n, int p) {
	int cnt = 0;
	do {
		n /= p;
		cnt += n;
	} while (n);
	return cnt;
}

//-----------------------------------------------------------------------------//
// Fast Fourier transform FFT: multiply 2 polynomials of length n in O(n log n) time, better than trivial multiplication O(n^2) time
//-----------------------------------------------------------------------------//

// a simple recursive implementation of FFT & inverse FFT
void fft(vector<cd> &a, bool invert) {
	int n = a.size();
	if (n == 1) return;
	vector<cd> a0(n / 2), a1(n / 2);
	for (int i = 0; 2 * i < n; ++i) {
		a0[i] = a[2 * i];
		a1[i] = a[2 * i + 1];
	}
	fft(a0, invert);
	fft(a1, invert);
	double ang = 2 * PI / n * (invert ? -1 : 1);
	cd w(1), wn(cos(ang), sin(ang));
	for (int i = 0; 2 * i < n; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if (invert) {
			a[i] /= 2;
			a[i + n / 2] /= 2;
		}
		w *= wn;
	}
}

// multiply 2 polynomials
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < a.size() + b.size()) n <<= 1;
	fa.resize(n);
	fb.resize(n);
	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; ++i) fa[i] *= fb[i];
	fft(fa, true);
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) ans[i] = round(fa[i].real());
	return ans;
}

// multiply 2 long numbers
int carry = 0;
for (int i = 0; i < n; ++i) {
	ans[i] += carry;
	carry = ans[i] / 10;
	ans[i] %= 10;
}

// improved implementation: in-place computation
int reverse(int n, int lg_n) {
	int res = 0;
	for (int i = 0; i < lg_n; ++i)
		if (n & (1 << i)) res |= 1 << (lg_n - 1 - i);
	return res;
}

void fft(vector<cd> &a, bool invert) {
	int n = a.size(), lg_n = 0;
	while ((1 << lg_n) < n) ++lg_n;
	for (int i = 0; i < n; ++i)
		if (i < reverse(i, lg_n)) swap(a[i], a[reverse(i, lg_n)]);
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		cd wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			cd w(1);
			for (int j = 0; j < len / 2; ++j) {
				cd u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (cd &x : a) x /= n;
}

void fft(vector<>cd> &a, bool invert) {
	int n = a.size();
	for (int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
        	cd w(1);
        	for (int j = 0; j < len / 2; ++j) {
        		cd u = a[i + j], v = a[i + j + len / 2] * w;
        		a[i + j] = u + v;
        		a[i + j + len / 2] = u - v;
        		w *= wlen;
        	}
        }
	}
	if (invert)
		for (cd &x : a) x /= n;
}

// number theoretic transform
const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

void fft(vector<int> & a, bool invert) {
	int n = a.size();
	for (int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		int wlen = invert ? root_1 : root;
		for (int i = len; i < root_pw; i <<= 1)
			wlen = (int)(1ll * wlen * wlen % mod);
		for (int i = 0; i < n; i += len) {
			int w = 1;
			for (int j = 0; j < len / 2; ++j) {
				int u = a[i + j], v = (int)(1ll * a[i + j + len / 2] * w % mod);
				a[i + j] = u + v < mod ? u + v : u + v - mod;
				a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
				w = (int)(1ll * w * wlen % mod);
			}
		}
	}
	if (invert) {
		int n_1 = inverse(n, mod); // function inverse computes the modular inverse
		for (int &x : a) x = (int)(1ll * x * n_1 % mod);
	}
}

//-----------------------------------------------------------------------------//
// Fibonacci numbers
//-----------------------------------------------------------------------------//

// O(n)
int fib(int n) {
	int a = 0, b = 1;
	for (int i = 0; i < n; ++i) {
		int tmp = a + b;
		a = b;
		b = tmp;
	}
	return a;
}

// O(log n)
struct matrix {
	ll mat[2][2];
	matrix friend operator *(const matrix &a, const matrix &b) {
		matrix c;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				c.mat[i][j] = 0;
				for (int k = 0; k < 2; ++k) c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
			}
		return c;
	}
};

matrix matpow(matrix base, ll n) {
	matrix ans{ {
			{1, 0},
			{0, 1}
		} };
	while (n) {
		if (n & 1) ans = ans * base;
		base = base * base;
		n >>= 1;
	}
	return ans;
}

ll fib(int n) {
	matrix base{ {
			{1, 1},
			{1, 0}
		} };
	return matpow(base, n).mat[0][1];
}

// fast doubling method: return pair (F_n, F_{n+1})
pair<int, int> fib(int n) {
	if (!n) return {0, 1};
	auto p = fib(n >> 1);
	int c = p.first * (2 * p.second - p.first);
	int d = p.first * p.first + p.second * p.second;
	if (n & 1) return {d, c + d};
	else return {c, d};
}

//-----------------------------------------------------------------------------//
// integer factorization
//-----------------------------------------------------------------------------//

// trial division
vector<ll> trial_division1(ll n) {
	vector<ll> factorization;
	for (ll d = 2; d * d <= n; ++d)
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	if (n > 1) factorization.push_back(n);
	return factorization;
}

// wheel factorization: an optimization of trial division
vector<ll> trial_division2(ll n) {
	vector<ll> factorization;
	while (n % 2 == 0) {
		factorization.push_back(2);
		n /= 2;
	}
	for (ll d = 3; d * d <= n; d += 2)
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	if (n > 1) factorization.push_back(n);
	return factorization;
}

vector<ll> trial_division3(ll n) {
	vector<ll> factorization;
	for (int d : {2, 3, 5})
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
	int i = 0;
	for (ll d = 7; d * d <= n; d += increments[i++]) {
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
		if (i == 8) i = 0;
	}
	if (n > 1) factorization.push_back(n);
	return factorization;
}

// precomputed primes
vector<ll> primes;
vector<ll> trial_division3(ll n) {
	vector<ll> factorization;
	for (ll d : primes) {
		if (d * d > n) break;
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}
	if (n > 1) factorization.push_back(n);
	return factorization;
}

// Fermat's factorization method
int fertmat(int n) {
	int a = ceil(sqrt(n)), b2 = a * a - n, b = round(sqrt(b2));
	while (b * b != b2) {
		++a;
		b2 = a * a - n;
		b = round(sqrt(b2));
	}
	return a - b;
}

// Pollard's p - 1 method: a probabilistic algorithm O(B log B log^2 n) per iteration: A consequence of this is that there is a possibility of the algorithm being unable to find a factor at all.
ll pollards_p_minus_1(ll n) {
	int B = 10;
	ll g = 1;
	while (B <= 1000000 && g < n) {
		ll a = 2 + rand() % (n - 3);
		g = gcd(a, n);
		if (g > 1) return g;
		// compute a^M
		for (int p : primes) {
			if (p >= B) continue;
			ll p_power = 1;
			while (p_power * p <= B) p_power *= p;
			a = power(a, p_power, n);
			g = gcd(a - 1, n);
			if (g > 1 && g < n) return g;
		}
		B *= 2;
	}
	return 1;
}

// Pollard's rho algorithm with Floyd's cycle-finding algorithm: O(sqrt[4](n) log n)
ll mult(ll a, ll b, ll mod) {
	return (__int128)a * b % mod;
} // similar to:

ll mult(ll a, ll b, ll mod) {
	ll ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}

ll f(ll x, ll c, ll mod) {
	return (mult(x, x, mod) + c) % mod;
}

ll rho(ll n, ll x0 = 2, ll c = 1) {
	ll x = x0, y = x0, g = 1;
	while (g == 1) {
		x = f(x, c, n);
		y = f(y, c, n);
		y = f(y, c, n);
		g = gcd(abs(x - y), n);
	}
	return g;
}

// Brent's algorithm: a similar method to Floyd, using 2 pointers
ll brent(ll n, ll x0 = 2, ll c = 1) {
	ll x = x0, g = 1, q = 1, xs, y;
	int m = 128, l = 1;
	while (g == 1) {
		y = x;
		for (int i = 1; i < l; ++i) x = f(x, c, n);
		int k = 0;
		while (k < l && g == 1) {
			xs = x;
			for (int i = 0; i < m && i < l - k; ++i) {
				x = f(x, c, n);
				q = mult(q, abs(y - x), n);
			}
			g = gcd(q, n);
			k += m;
		}
		l *= 2;
	}
	if (g == n)
		do {
			xs = f(xs, c, n);
			g = gcd(abs(xs - y), n);
		} while (g == 1);
	return g;
}


//-----------------------------------------------------------------------------//
// LCM Least Common Multiple
//-----------------------------------------------------------------------------//

int lcm (int a, int b) {
	return a / gcd(a, b) * b;
}

//-----------------------------------------------------------------------------//
// linear Diophantine equation
//-----------------------------------------------------------------------------//

int egcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1, d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

// find 1 solution
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g) return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}

// find all solution
void shift_solution(int & x, int & y, int a, int b, int cnt) {
	x += cnt * b;
	y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
	int x, y, g;
	if (!find_any_solution(a, b, c, x, y, g)) return 0;
	a /= g;
	b /= g;
	int sign_a = a > 0 ? +1 : -1;
	int sign_b = b > 0 ? +1 : -1;

	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx) shift_solution(x, y, a, b, sign_b);
	if (x > maxx) return 0;
	int lx1 = x;
	shift_solution(x, y, a, b, (maxx - x) / b);
	if (x > maxx) shift_solution(x, y, a, b, -sign_b);
	int rx1 = x;
	shift_solution(x, y, a, b, -(miny - y) / a);
	if (y < miny) shift_solution(x, y, a, b, -sign_a);
	if (y > maxy) return 0;
	int lx2 = x;
	shift_solution(x, y, a, b, -(maxy - y) / a);
	if (y > maxy) shift_solution(x, y, a, b, sign_a);
	int rx2 = x;
	if (lx2 > rx2) swap(lx2, rx2);
	int lx = max(lx1, lx2);
	int rx = min(rx1, rx2);
	if (lx > rx) return 0;
	return (rx - lx) / abs(b) + 1;
}

//-----------------------------------------------------------------------------//
// modular multiplicative inverse
//-----------------------------------------------------------------------------//

int inv(int a) {
	return a <= 1 ? a : m - (ll)(m / a) * inv(m % a) % m;
}

// find modular inverse for array of numbers modulo m
vector<int> invs(const vector<int> &a, int m) {
	int n = a.size();
	if (!n) return {};
	vector<int> b(n);
	inv v = 1;
	for (int i = 0; i != n; ++i) {
		b[i] = v;
		v = static_cast<ll>(v) * a[i] % m;
	}
	int x, y;
	egcd(v, m, x, y);
	x = (x % m + m) % m;
	for (int i = n - 1; i >= 0; --i) {
		b[i] = static_cast<ll>(x) * b[i] % m;
		x = static_cast<ll>(x) * a[i] % m;
	}
	return b;
}

//-----------------------------------------------------------------------------//
// primality test: check if a number is a prime or composite
//-----------------------------------------------------------------------------//

// trial division
bool isPrime(int x) {
	for (int d = 2; d * d <= x; ++d)
		if (x % d == 0) return false;
	return x >= 2;
}

// faster
bool isPrime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0) return false;
	return true;
}

// segmented sieve: counts number of primes <= n using block sieving
int count_prime(int n) {
	const int S = 10000;
	vector<int> primes;
	int nsqrt = sqrt(n);
	vector<char> is_prime(nsqrt + 2, true);
	for (int i = 2; i <= nsqrt; ++i)
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= nsqrt; j += i) is_prime[j] = false;
		}
	int ans = 0;
	vector<char> block(S);
	for (int k = 0; k * S <= n; ++k) {
		fill(block.begin(), block.end(), true);
		int start = k * S;
		for (int p : primes) {
			int start_idx = (start + p - 1) / p;
			int j = max(start_idx, p) * p - start;
			for (; j < S; j += p) block[j] = false;
		}
		if (!k) block[0] = block[1] = false;
		for (int i = 0; i < S && start + i <= n; ++i)
			if (block[i]) ++ans;
	}
	return ans;
}

// find primes in range [l, r] of small size, e.g., r - l + 1 approx 1e7 where r can be very large, e.g., r approx 1e12: O((r - l + 1)log log r + sqrt(r) log log sqrt(r))
vector<char> segmentedSieve(ll l, ll r) {
	// generate all primes up to sqrt(r)
	ll lim = sqrt(r);
	vector<char> mark(lim + 1, false);
	vector<ll> primes;
	for (ll i = 2; i <= lim; ++i)
		if (!mark[i]) {
			primes.emplace_back(i);
			for (ll j = i * i; j <= lim; j += i) mark[j] = true;
		}
	vector<char> isPrime(r - l + 1, true);
	for (ll i : primes)
		for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) isPrime[j - l] = false;
	if (l == 1) isPrime[0] = false;
	return isPrime;
}

// segmented sieve with no pregenerate all primes: O((r - l + 1)log r + sqrt(r)): worse complexity but still run very fast in practice
vector<char> segmentedSieveNoPreGen(ll l, ll r) {
	vector<char> isPrime(r - l + 1, true);
	ll lim = sqrt(r);
	for (ll i = 2; i <= lim; ++i)
		for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) isPrime[j - l] = false;
	if (l == 1) isPrime[0] = false;
	return isPrime;
}

// Fermat primality test: a probabilistic test
bool probablyPrimeFermat(int n, int iter = 5) {
	if (n < 4) return n == 2 || n == 3;
	for (int i = 0; i < iter; ++i) {
		int a = 2 + rand() % (n - 3);
		if (binpow(a, n - 1, n) != 1) return false;
	}
	return true;
}

// Miller-Rabin primality test
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
	u64 result = 1;
	base %= mod;
	while (e) {
		if (e & 1)
			result = (u128)result * base % mod;
		base = (u128)base * base % mod;
		e >>= 1;
	}
	return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
	u64 x = binpower(a, d, n);
	if (x == 1 || x == n - 1)
		return false;
	for (int r = 1; r < s; r++) {
		x = (u128)x * x % n;
		if (x == n - 1)
			return false;
	}
	return true;
};

bool MillerRabin(u64 n, int iter = 5) { // returns true if n is probably prime, else returns false.
	if (n < 4) return n == 2 || n == 3;
	int s = 0;
	u64 d = n - 1;
	while ((d & 1) == 0) {
		d >>= 1;
		++s;
	}
	for (int i = 0; i < iter; i++) {
		int a = 2 + rand() % (n - 3);
		if (check_composite(n, a, d, s)) return false;
	}
	return true;
}

// Miller-Rabin primality test: deterministic implementation
bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
	if (n < 2)
		return false;

	int r = 0;
	u64 d = n - 1;
	while ((d & 1) == 0) {
		d >>= 1;
		r++;
	}

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a)
			return true;
		if (check_composite(n, a, d, r))
			return false;
	}
	return true;
}

//-----------------------------------------------------------------------------//
// primitive root
//-----------------------------------------------------------------------------//

// assume modulo p is a prime number
int powmod(int a, int b, int p) {
	int res = 1;
	while (b)
		if (b & 1) res = int (res * 1ll * a % p), --b;
		else a = int (a * 1ll * a % p), b >>= 1;
	return res;
}

int generator(int p) {
	vector<int> fact;
	int phi = p - 1, n = phi;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			fact.push_back(i);
			while (n % i == 0) n /= i;
		}
	if (n > 1) fact.push_back(n);
	for (int res = 2; res <= p; ++res) {
		bool ok = true;
		for (size_t i = 0; i < fact.size() && ok; ++i)
			ok &= powmod(res, phi / fact[i], p) != 1;
		if (ok) return res;
	}
	return -1;
}

//-----------------------------------------------------------------------------//
// main
//-----------------------------------------------------------------------------//

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		// insert more . . .
	}

	//-----------------------------------------------------------------------------//
	// arbitrary-precision arithmetic/bignum/long arithmetic
	//-----------------------------------------------------------------------------//
	// output bignum
	printf ("%d", a.empty() ? 0 : a.back());
	for (int i = (int)a.size() - 2; i >= 0; --i) printf ("%09d", a[i]);

	// input bignum: to read a long integer, read its notation into a string & then convert it to "digits"
	for (int i = (int)s.length(); i > 0; i -= 9)
		if (i < 9) a.push_back(atoi(s.substr(0, i).c_str()));
		else a.push_back(atoi(s.substr(i - 9, 9).c_str()));
	// if we use an array of char instead of a string, shorter code:
	for (int i = (int)strlen(s); i > 0; i -= 9) {
		s[i] = 0;
		a.push_back(atoi(i >= 9 ? s + i - 9 : s));
	}
	// if the input can contain leading 0s, they can be removed as follows:
	while (a.size() > 1 && !a.back()) a.pop_back();

	// add bignums: increment long integer a by b & store result in a
	int carry = 0;
	for (size_t i = 0; i < max(a.size(), b.size()) || carry; ++i) {
		if (i == a.size()) a.push_back(0);
		a[i] += carry + (i < b.size() ? b[i] : 0);
		carry = a[i] >= base;
		if (carry) a[i] -= base;
	}

	// subtract bignums: decrement long integer a by b & store result in a
	int carry = 0;
	for (size_t i = 0; i < b.size() || carry; ++i) {
		a[i] -= carry + (i < b.size() ? b[i] : 0);
		carry = a[i] < 0;
		if (carry) a[i] += base;
	}
	while (a.size() > 1 && !a.back()) a.pop_back();

	// multiply by short integer: multiply long integer a by short integer b < base & store result in a
	int carry = 0;
	for (size_t i = 0; i < a.size() || carry; ++i) {
		if (i == a.size()) a.push_back(0);
		ll cur = carry + a[i] * 1ll * b;
		a[i] = int(cur % base);
		carry = int(cur / base);
	}
	while (a.size() > 1 && !a.back()) a.pop_back();

	// multiply by long integer: multiply long integers a & b & store result in c
	lnum c (a.size() + b.size());
	for (size_t i = 0; i < a.size(); ++i)
		for (int j = 0; carry = 0; j < (int)b.size() || carry; ++j) {
			ll cur = c[i + j] + a[i] * 1ll + (j < (int)b.size() ? b[j] : 0) + carry;
			c[i + j] = int(cur % base);
			carry = int(cur / base);
		}
	while (c.size() > 1 && !c.back()) c.pop_back();
	// division by short integer: divide long integer a by short integer b < base, store integer result in a & remainder in carry
	int carry = 0;
	for (int i = (int)a.size() - 1; i >= 0; --i) {
		ll cur = a[i] + carry * 1ll * base;
		a[i] = int(cur / b);
		carry = int(cur % b);
	}
	while (a.size() > 1 && !a.back()) a.pop_back();

	//-----------------------------------------------------------------------------//
	// discrete root: given a prime n & 2 integers a, k, find all x for which x^k = a (mod n)
	//-----------------------------------------------------------------------------//
	// find all numbers x s.t. x^k = a (mod n)
	int n, k, a;
	int n, k, a;
    scanf("%d %d %d", &n, &k, &a);
    if (!a) {
    	puts("1\n0");
        return 0;
    }
    int g = generator(n);
    // baby-step giant-step discrete logarithm algorithm
    int sq = (int) sqrt(n + .0) + 1;
    vector<pair<int, int>> dec(sq);
    for (int i = 1; i <= sq; ++i)
    	dec[i - 1] = {powmod(g, i * sq * k % (n - 1), n), i};
    sort(dec.begin(), dec.end());
    int any_ans = -1;
    for (int i = 0; i < sq; ++i) {
    	int my = powmod(g, i * k % (n - 1), n) * a % n;
    	auto it = lower_bound(dec.begin(), dec.end(), make_pair(my, 0));
    	if (it != dec.end() && it->first == my) {
    		any_ans = it->second * sq - i;
    		break;
    	}
    }
    if (any_ans == -1) {
    	puts("0");
    	return 0;
    }
    // print all possible answers
    int delta = (n - 1) / gcd(k, n - 1);
    vector<int> ans;
    for (int cur = any_ans % delta; cur < n - 1; cur += delta)
    	ans.push_back(powmod(g, cur, n));
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int answer : ans) printf("%d ", answer);

	//-----------------------------------------------------------------------------//
	// sieve of Eratosthenes: find all primes in [1, n] using O(n log log n) operations
	//-----------------------------------------------------------------------------//
	int n;
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; ++i) {
		if (is_prime[i] && (ll)i * i <= n)
			for (int j = i * i; j <= n; j += i) is_prime[j] = false;
	}

	// sieving till root: reduce number of operations
	int n;
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; ++i)
		if (is_prime[i])
			for (int j = i * i; j <= n; j += i) is_prime[j] = false;

	// linear sieve: find all primes in a segment [2, n]
	const int N = 10000000;
	vector<int> lp(N + 1), pr;
	for (int i = 2; i <= N; ++i) {
		if (!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) break;
		}
	}

	// assign value by a pair of {} to a container
	// initialize pair
	pair<int, int> p;
	p = make_pair(3, 4); // same as
	p = {3, 4};
	// initialize vector
	vector<int> v;
	v = {1, 2, 5, 2};
	// initialize set
	set<int> s;
	s = {4, 6, 2, 7, 4};

	/* ordered set: more powerful set container than set
	Ordered set keeps elements in sorted order, performs all operations as performed by set<T> data structure in STL, e.g., find(), lower_bound(), etc. in O(log n) complexity
	& 2 additional functions with same O(log n) complexity:
	- order_of_key (k): number of items which are strictly smaller than k
	- find_by_order(k): kth element in a set (0-based indexing)
	*/

	// compute number of digits
	int N = 1e9;
	int n_digit = floor(log10(N)) + 1;

	// binary search
	cout << last_true(2, 10, [](int x) { return true; }) << endl; // all numbers satisfy the condition (outputs 10)
	cout << last_true(2, 10, [](int x) { return x * x <= 30; }) << endl; // outputs 5
	cout << last_true(2, 10, [](int x) { return false; }) << endl; // no numbers satisfy the condition (outputs 1)

	// 2 built-in binary search functions automatically use binary search to find iterator to the specified value in O(n log n)
	/* iterator lower_bound(iterator first, iterator last, const val) returns an iterator pointing to 1st element in range [first, last) which has a value >= val
	Syntax: std::lower_bound(first, last, val, comp);
	Return an iterator to the smallest number >= val.

	*/
	vector<int> v = {10, 20, 30, 40, 50};
	cout << *lower_bound(v.begin(), v.end(), 35); // find lower bound for value 35 in vector v, output: 40
	// iterator upper_bound(iterator first, iterator last, const val) returns an iterator pointing to 1st element in range [first, last) which has a value > val

	// BFS Breadth First Search O(n + m)
	vector<vector<int>> adj; // adjacency list representation
	int n, s; // number of nodes & source vertex
	queue<int> q;
	vector<bool> used(n);
	vector<int> d(n), p(n); // distances & parents
	q.push(s);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v])
			if (!used[u]) {
				used[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
				p[u] = v;
			}
	}
	// restore & display the shortest path from the source to some vertex u
	if (!used[u]) cout << "No path!";
	else {
		vector<int> path;
		for (int v = u; v != -1; v = p[v]) path.push_back(v);
		reverse(path.begin(), path.end());
		cout << "Path: ";
		for (int v : path) cout << v << ' ';
	}

	/* bitwise operations:	
	https://cp-algorithms.com/algebra/bit-manipulation.html
	*/
	int a = 5;
	cout << bitset<32>(a) << '\n';     // Binary representation of a
	cout << bitset<32>(~a) << '\n';    // Binary of NOT a
	// bitset<32> means we represent the number using 32 bits.

	// turn bits on/off/flip
	int k = 1;
	a = a | (1 << k); // turn on bit k: make sure bit k = 1 (keep others unchanged)
	a = a & ~(1 << k); // turn off bit k: make sure bit k = 0.
	a = a ^ (1 << k); // flip bit k: 1 -> 0, 0 -> 1
	n &= (n - 1); // clear the right-most set bit
	n & (n + 1); // clear all trailing 1s: 00110111 -> 00110000
	n | (n + 1); // set the last cleared bit: 00110101 -> 00110111
	n & -n; // extracts the last set bit: 00110100 -> 00000100

	// check if bit x is on
	if (a & (1 << x)) cout << "ON";
	else cout << "OFF";

	if ((a >> x) & 1) cout << "ON";

	// even/odd check
	if (x & 1) cout << "Odd";
	else cout << "Even";

	// can a string form a palindrome?
	string s;
	cin >> s;
	int ans = 0;
	for (char c : s) ans ^= 1 << (c - 'a');
	// if at most 1 bit is ON -> palindrome possible
	if (ans == 0 || (ans & (ans - 1)) == 0) cout << "YES"; // trick (ans & (ans - 1)) == 0 checks whether ans has only 1 bit ON, i.e., ans is a power of 2
	else cout << "NO";

	/* build-in bit functions (gcc)
	__builtin_popcount(unsigned int): count 1s in integer = returns the number of set bits (__builtin_popcount(0b0001'0010'1100) == 4)
	__builtin_popcountll(x): count 1s in long long
	__builtin_clz(unsigned int): count leading 0s = count how many 0s come before the 1st 1 from the left. (__builtin_clz(0b0001'0010'1100) == 23)
	__builtin_ctz(x): count trailing 0s = count how many 0s come after the last 1 from the right. These are useful to find the position of the 1st or last set bit quickly. __builtin_ctz(unsigned int) the count of trailing zeros (__builtin_ctz(0b0001'0010'1100) == 2)
	__lg(x): position of highest bit (approximately floor(log2(x)))
	__builtin_ffs(int) finds the index of the first (most right) set bit (__builtin_ffs(0b0001'0010'1100) == 3)
	__builtin_parity(x) the parity (even or odd) of the number of 1s in the bit representation

	Note that some of the operations (both the C++20 functions and the Compiler Built-in ones) might be quite slow in GCC if you don't enable a specific compiler target with #pragma GCC target("popcnt").

	C++ supports some of those operations since C++20 via the bit standard library:
	
	has_single_bit checks if the number is a power of 2
	bit_ceil/bit_floor round up/down to the next power of 2
	rotl/rotr rotate the bits in the number
	countl_zero/countr_zero/countl_one/countr_one count the leading/trailing 0s/1s
	popcount count the number of set bits
	*/
	x = 8;
	cout << __builtin_popcount(x) << endl; // 1
	cout << __lg(x) << endl;               // 3
	cout << (1 << __lg(x)) << endl;        // 8
	// all bitwise operations work in O(1). Mastering them can make your code shorter, faster, & smarter.

	// range based for loop
	set<int> s = {1, 2, 3, 5};
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) cout << *it << ' ';
	for (auto it : s) cout << it << ' ';

	//-----------------------------------------------------------------------------//
	// minimum stack/minimum queue
	//-----------------------------------------------------------------------------//
	
	// -- stack modification
	stack<pair<int, int>> st;

	// add an element
	int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
	st.push({new_elem, new_min});

	// remove an element O(1)
	int removed_element = st.top().first;
	st.pop();

	// find minimum O(1)
	int minimum = st.top().second;

	// -- queue modification 1
	deque<int> q;

	// find the minimum O(1)
	int minimum = q.front();

	// add an element O(1)
	while (!q.empty() && q.back() > new_element) q.pop_back();
	q.push_back(new_element);

	// remove an element
	if (!q.empty() && q.front() == remove_element) q.pop_front();
	
	// -- queue modification 2
	deque<pair<int, int>> q;
	int cnt_added = 0, cnt_removed = 0;

	// find the minimum
	int minimum = q.front().first;

	// add an element
	while (!q.empty() && q.back().first > new_element) q.pop_back();
	q.push_back({new_element, cnt_added});
	++cnt_added;
	
	// remove an element
	if (!q.empty() && q.front().second == cnt_removed) q.pop_front();
	++cnt_removed;

	// -- queue modification 3
	stack<pair<int, int>> s1, s2;

	// find the minimum
	if (s1.empty() || s2.empty()) minimum = s1.empty() ? s2.top().second : s1.top().second;
	else minimum = min(s1.top().second, s2.top().second);

	// add element
	int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
	s1.push({new_element, minimum});

	// remove an element
	if (s2.empty())
		while (!s1.empty()) {
			int element = s1.top().first;
			s1.pop();
			int minimum = s2.empty() ? element : min(element, s2.top().second);
			s2.push({element, minimum});
		}
	int remove_element = s2.top().first;
	s2.pop();
	
	//-----------------------------------------------------------------------------//
	// modular multiplicative inverse
	//-----------------------------------------------------------------------------//
	int x, y, g = egcd(a, m, x, y);
	if (g != 1) cout << "No solution!";
	else {
		x = (x % m + m) % m; // since may be negative
		cout << x << '\n';
	}

	// precompute modular inverse for [1, m - 1] in O(m)
	inv[1] = 1;
	for (int a = 2; a < m; ++a) inv[a] = m - (ll)(m / a) * inv[m % a] % m;

	//-----------------------------------------------------------------------------//
	// submask enumeration
	//-----------------------------------------------------------------------------//
	
	// enumerating all submasks of a given mask
	int s = m;
	while (s) {
		// can use s ...
		s = (s - 1) & m;
	} // or, using a more compact for statement
	for (int s = m; s; s = (s - 1) & m) // can use s ...
	// or use a less elegant design
	for (int s = m; ; s = (s - 1) & m) {
		// can use s ...
		if (!s) break;
	}

	// iterate through all masks with their submasks O(3^n), especially problems using bitmask DP, we want to iterate through all bitmasks & for each mask, iterate through all of its submasks
	for (int m = 0; m < (1 << n); ++m)
		for (int s = m; s; s = (s - 1) & m) // s & m ...

}