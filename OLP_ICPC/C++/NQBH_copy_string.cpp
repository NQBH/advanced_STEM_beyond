#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k_max, k = 0;
		cin >> n >> k_max;
		string s, t;
		cin >> s >> t;
		if (s == t) {
			cout << "0\n";
			continue;
		}
		map<char, int> pos; // current position of char c
		vector<int> max_dist(n, 0); // max num moves at t[i]
		pos[s[0]] = 0;
		bool no = 0;
		for (int i = 1; i < n; ++i) {
			pos[s[i]] = i;
			if (s[i] == t[i]) {
				max_dist[i] = 0;
				continue;
			}
			if (i - pos[t[i]] > k_max) {
				no = 1;
				break;
			} else {
				max_dist[i] = i - pos[t[i]];
				k = max(k, i - pos[t[i]]);				
			}
		}
		if (no) cout << "-1\n";
		else {
			cout << k << '\n';
			int block_cnt = 0;			
			for (int it = 0; it < k; ++it) {
				for (int i = n - 1; i >= 1; --i) {
					if (block_cnt) {
						s[i] = s[i - 1];
						--block_cnt;						
						if (max_dist[i]) --max_dist[i];
						else ++max_dist[i];
					}
					if (max_dist[i]) {
						s[i] = s[i - 1];
						--max_dist[i];
						block_cnt = max_dist[i];
					}
				}
				cout << s << '\n';
			}
			// cout << t << '\n';
		}
	}
}
// unfinished