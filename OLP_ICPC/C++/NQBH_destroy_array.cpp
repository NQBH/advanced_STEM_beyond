#include <iostream>
#include <vector>
using namespace std;

vector<int> a, p, parent, sz;
vector<long long> res, sum;
vector<bool> activated_pos;

void make_set_size_sum(int i) {
	parent[i] = i;
	sz[i] = 1;
	sum[i] = a[i];
}

int find_set_size_sum(int v) {
	return v == parent[v] ? v : parent[v] = find_set_size_sum(parent[v]);
}

void union_set_size_sum(int a, int b) {
	a = find_set_size_sum(a);
	b = find_set_size_sum(b);
	if (a != b) {
		if (sz[a] < sz[b]) swap(a, b);
		parent[b] = a;
		sz[a] += sz[b];
		sum[a] += sum[b];
	}
}

int main() {
	int n;
	cin >> n;
	vector<bool> activated_pos(n + 1, false);
	a.resize(n + 1);
	p.resize(n + 1);
	parent.resize(n + 1);
	sz.resize(n + 1);
	res.resize(n + 1);
	sum.resize(n + 1);
	res[n] = 0; // last result is always 0
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> p[i];
	activated_pos[p[n]] = true;
	long long ans = a[p[n]]; // initialize current max sum
	res[n - 1] = ans; // last element being destroyed
	make_set_size_sum(p[n]);
	for (int i = n - 1; i >= 1; --i) {
		activated_pos[p[i]] = true;
		make_set_size_sum(p[i]);
		if (p[i] > 1 && activated_pos[p[i] - 1]) union_set_size_sum(p[i], p[i] - 1);
		if (p[i] < n && activated_pos[p[i] + 1]) union_set_size_sum(p[i], p[i] + 1);
		ans = max(ans, sum[find_set_size_sum(p[i])]);
		res[i - 1] = ans;
	}
	for (int i = 1; i <= n; ++i) cout << res[i] << '\n';
}