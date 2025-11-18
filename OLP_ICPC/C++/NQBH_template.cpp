#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

// #define macros
#define F first;
#define S second;
#define pb push_back;
#define mp make_pair;

// typedef
typedef long long ll;
typedef pair pp;
typedef vector vec;

// binary exponentiation: calculate a^n using O(log n) multiplications

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

// DFS Depth First Search O(n + m)
	// simplest implementation of DFS
vector<vector<int>> adj; // raph represented as an adjacency list
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

	// bitwise operations
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

	// range based for loop
	set<int> s = {1, 2, 3, 5};
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) cout << *it << ' ';
	for (auto it : s) cout << it << ' ';



}
/*
CP TRICKS

# bitwise operations
	- __builtin_popcount(x), __builtin_popcountl(x) & __builtin_popcountll(x) for long and long long data types: count number of 1s (set bits) in integer variable x



*/