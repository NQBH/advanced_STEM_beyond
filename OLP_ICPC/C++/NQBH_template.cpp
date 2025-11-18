#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

// binary search
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

// combinatorics

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

int last_true(int lo, int hi, function<bool(int)> f) {
	--lo;
	for (int dif = hi - lo; dif > 0; dif /= 2)
		while (lo + dif <= hi && f(lo + dif)) lo += dif;
	return lo;
}

// check prime
bool isPrime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0) return false;
	return true;
}

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


	}

	// BINARY SEARCH
	// all numbers satisfy the condition (outputs 10)
	cout << last_true(2, 10, [](int x) { return true; }) << endl;
	// outputs 5
	cout << last_true(2, 10, [](int x) { return x * x <= 30; }) << endl;
	// no numbers satisfy the condition (outputs 1)
	cout << last_true(2, 10, [](int x) { return false; }) << endl;

	// BITWISE OPERATION
	int a = 5;
	cout << bitset<32>(a) << '\n';     // Binary representation of a
	cout << bitset<32>(~a) << '\n';    // Binary of NOT a
	// bitset<32> means we represent the number using 32 bits.

	// turn bits on/off/flip
	int k = 1;
	a = a | (1 << k); // turn on bit k: make sure bit k = 1 (keep others unchanged)
	a = a & ~(1 << k); // turn off bit k: make sure bit k = 0.
	a = a ^ (1 << k); // flip bit k: 1 -> 0, 0 -> 1

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
	__builtin_popcount(x): count 1s in integer
	__builtin_popcountll(x): count 1s in long long
	__builtin_clz(x): count leading 0s = count how many 0s come before the 1st 1 from the left.
	__builtin_ctz(x): count trailing 0s = count how many 0s come after the last 1 from the right. These are useful to find the position of the 1st or last set bit quickly
	__lg(x): position of highest bit (approximately floor(log2(x)))
	*/
	x = 8;
	cout << __builtin_popcount(x) << endl; // 1
	cout << __lg(x) << endl;               // 3
	cout << (1 << __lg(x)) << endl;        // 8
	// all bitwise operations work in O(1). Mastering them can make your code shorter, faster, & smarter.
}