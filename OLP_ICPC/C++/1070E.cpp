#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

struct segment_tree {
	int n;
	vector<ll> tree;
	segment_tree(int n) : n(n), tree(4 * n, inf) {}

	void push(int node) {
		if (tree[node] != inf) {
			tree[2 * node] = min(tree[2 * node], tree[node]);
			tree[2 * node + 1] = min(tree[2 * node + 1], tree[node]);
			tree[node] = inf; // reset
		}
	}

	void update(int node, int start, int end, int l, int r, ll val) {
		if (l > end || r < start) return;
		if (l <= start && end <= r) {
			tree[node] = min(tree[node], val);
			return;
		}
		push(node);
		int mid = (start + end) / 2;
		update(2 * node, start, mid, l, r, val);
		update(2 * node + 1, mid + 1, end, l, r, val);
	}
	void flatten(int node, int start, int end, vector<ll>& res) {
		if (start == end) {
			res[start] = tree[node];
			return;
		}
		push(node);
		int mid = (start + end) / 2;
		flatten(2 * node, start, mid, res);
		flatten(2 * node + 1, mid + 1, end, res);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, amax = 0;
		cin >> n;
		vector<int> a(n + 1, 0), p(n + 1, 0), l(n + 1, 0), r(n + 1, 0); // nearest greater element to left & right
		vector<ll> c(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] > amax) amax = a[i];
		}
		for (int i = 1; i <= n; ++i) cin >> c[i];
		for (int i = 1; i <= n; ++i) cin >> p[i];
		vector<int> s_max; // store indices of maximum elements
		ll c_opt = inf;
		for (int i = 1; i <= n; ++i)
			if (a[i] == amax) {
				s_max.push_back(i);
				c_opt = min(c_opt, c[i]);
			}
		stack<int> st;
		for (int i = 1; i <= n; ++i) {
			while (!st.empty() && a[st.top()] <= a[i]) st.pop();
			l[i] = st.empty() ? 0 : st.top();
			st.push(i);
		}
		while (!st.empty()) st.pop();
		for (int i = n; i >= 1; --i) {
			while (!st.empty() && a[st.top()] <= a[i]) st.pop();
			r[i] = st.empty() ? n + 1 : st.top();
			st.push(i);
		}
		// compute V[i] = min {c[y]; l[y] < i < r[y]}
		segment_tree segtree(n);
		for (int i = 1; i <= n; ++i) {
			int L = l[i] + 1, R = r[i] - 1;
			if (L <= R) segtree.update(1, 1, n, L, R, c[i]);
		}
		vector<ll> V(n + 1, 0);
		segtree.flatten(1, 1, n, V);
		ll curr_ans = 0;
		set<int> active_idx; // a set of active indices that have not been 0ed out
		for (int i = 1; i <= n; ++i) {
			active_idx.insert(i);
			curr_ans += min(c_opt, V[i]);
		}
		cout << curr_ans - c_opt << ' ';
		vector<bool> is_max(n + 1, false);
		for (int i : s_max) is_max[i] = true;
		bool max_zeroed = false;
		for (int i = 1; i <= n; ++i) {
			int target = p[i];
			if (is_max[target]) max_zeroed = true;
			if (max_zeroed) cout << "0 ";
			else { // update sets c[target] = 0 => V[j] = 0 for all j in [l[target], r[target]]
				int L = l[target] + 1, R = r[target] - 1;
				auto it = active_idx.lower_bound(L);
				while (it != active_idx.end() && *it <= R) {
					int idx = *it;
					curr_ans -= min(c_opt, V[idx]);
					it = active_idx.erase(it);
				}
				cout << curr_ans - c_opt << ' ';
			}
		}
		cout << '\n';
	}
}