#include <bits/stdc++.h>
using namespace std;

void ask(int x, int y, vector<int>& p, vector<int>& pos) {
	cout << "? " << x << ' ' << y << endl;
	int u, v;
	cin >> u >> v;
	if (u == -1) exit(0);
	// update p & position
	swap(p[u], p[v]);
	pos[p[u]] = u;
	pos[p[v]] = v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n + 1, 0), pos(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
			pos[p[i]] = i;
		}
		// from out pair -> inside pair ( ( ... () ... ))
		for (int i = 1; i <= n / 2; ++i) {
			int l = i, r = n - i + 1;
			while (pos[l] != l || pos[r] != r) {
				int target, pivot;
				// fix l 1st then r
				if (pos[l] != l) {
					target = l;
					pivot = r;
				} else {
					target = r;
					pivot = l;
				}
				int curr = pos[target];
				if (curr == pivot) ask(l, r, p, pos); // if l is at r, make l is at l
				else ask(curr, target, p, pos);
			}
		}
		cout << "!" << endl;		
	}
}