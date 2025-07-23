#include <iostream>
#include <cstring>
using namespace std;

struct node {
	int k, step; // current prime number k, length of path (number of changed digits) step
};

node h[100000]; // queue
bool p[11000]; // sieve
int x, y, t, s[11000]; // initial prime x, goal prime y, number of remainder test cases t, current shortest path s[x] for prime x

void make(int n) { // get primes in [2..n] by sieve method
	memset(p, 0, sizeof(p));
	p[0] = 1, p[1] = 1;
	for (int i = 2; i <= n; ++i)
		if (!p[i])
			for (int j = i * i; j <= n; j += i) p[j] = 1;
}

int change(int x, int i, int j) { // change i-th digit of x into j
	if (i == 1) return x / 10 * 10 + j;
	else if (i == 2) return x / 100 * 100 + x % 10 + j * 10;
	else if (i == 3) return x / 1000 * 1000 + x % 100 + j * 100;
	else if (i == 4) return x % 1000 + j * 1000;
}

int main() {
	make(9999); // get primes in [2..9999]
	cin >> t; // number of test cases
	while (t--) {
		cin >> x >> y; // initial prime x & goal prime y
		h[1].k = x; // initial prime x is pushed into queue
		h[1].step = 0;
		int l = 1, r = 1; // initialize pointers of queue
		memset(s, 100, sizeof(s)); // initialize length of path
		int ans = -1; // initialize minimal cost
		while (1) {
			if (h[l].k == y) { // goal prime y is gotten
				ans = h[l].step;
				break;
			}
			int tk, ts;
			for (int i = 1; i <= 4; ++i) // every digit of front for queue is changed
				for (int j = 0; j <= 9; ++j)
					if (!((j == 0) && (i == 4))) { // enumerate
						tk = change(h[l].k, i, j);
						if (p[tk]) continue; // if tk is not a prime
						ts = h[l].step + 1; // length of path to tk
						if (ts >= s[tk]) continue;
						if (tk == y) { // if tk is goal prime
							ans = ts;
							break;
						}
						s[tk] = ts; // length of path to tk
						++r;
						h[r].k = tk; // prime tk & its length of path is pushed
						h[r].step = ts;
					}
			if (l == r || ans >= 0) break; // if queue is empty or goal prime is arrived
			++l;
		}
		if (ans >= 0) cout << ans << '\n';
		else cout << "Impossible" << '\n';
	}
}