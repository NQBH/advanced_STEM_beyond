#include <iostream>
#include <vector>
using namespace std;
#define sz(x) (int)size(x)
using ll = long long;

vector<ll> psum(const vector<ll> &a) {
	vector<ll> psum(sz(a) + 1);
	for (int i = 0; i < sz(a); ++i) psum[i + 1] = psum[i] + a[i];
	// or partial_sum(begin(a), end(a), begin(psum) + 1);
	return psum;
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	for (ll &x : a) cin >> x;
	vector<ll> p = psum(a);
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		cout << p[r] - p[l] << '\n';
	}
}