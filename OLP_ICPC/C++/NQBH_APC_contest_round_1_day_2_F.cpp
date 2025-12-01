#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 2e6;

int n, q;
struct node {
	int max_len, plen, slen, len;
};

vector<int> a(MAX);
vector<node> t(4 * MAX); // segment tree

node merge(node l, node r, int mid) {
	
}



void build(int v, int l, int r) {
	if (l == r) t[v] = a[l];
	else {
		int m = (l + r) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

void update(int v, int l, int r, int pos, int new_val) {
	if (l == r) t[v] == new_val;
	else {
		int tm = (l + r) / 2;
		if (pos <= tm) update(v * 2, l, tm, pos, new_val);
		else update(v * 2 + 1, tm + 1, r, pos, new_val);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

// output: max length
int query(int v, int l, int r, int u, int v) {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	build(1, 1, n); // init segment tree
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int i, x;
			cin >> i >> x;
			update(1, 1, n, i, x); // a[i] == x
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
}