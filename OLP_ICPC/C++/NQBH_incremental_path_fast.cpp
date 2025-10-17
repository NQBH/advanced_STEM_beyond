#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> oper(n, 0);
		for (int i = 0; i < n; ++i)
			if (s[i] == 'B') oper[i] = 1;
		vector<int> a(m);
		vector<bool> is_black(1e9 + 1, false);
		set<int> black;
		for (int& x : a) {
			cin >> x;
			black.insert(x);
			is_black[x] = true;
		}
		int pos = 1, next_start_pos = 1;
		// person 1
		if (!oper[0]) {
			++pos;
			if (!is_black[pos]) {
				is_black[pos] = true;
				black.insert(pos);
			}
		} else { // find 1st current white cell > 1
			++pos;
			while (is_black[pos]) ++pos;
			is_black[pos] = true;
			black.insert(pos);
		}
		// person 2
		if (n >= 2) {
			pos = 1;
			if (!oper[0]) ++pos;
			else { // find 1st white cell > 1
				++pos;
				while (is_black[pos]) ++pos;
				// cout << "pos = " << pos << '\n';
			}
			next_start_pos = pos;
			if (!oper[1]) {
				++pos;
				// cout << "pos = " << pos << '\n';
				if (!is_black[pos]) {
					is_black[pos] = true;
					black.insert(pos);
				}
			} else { // find 1st white cell > 1
				++pos;
				while (is_black[pos]) ++pos;
				is_black[pos] = true;
				black.insert(pos);
			}
		}
		for (int i = 3; i <= n; ++i) { // person i
			pos = next_start_pos; // start from (i - 2)th cell visited by (i - 1)th person, need 2 more steps
			// step i - 1
			if (!oper[i - 2]) {
				++pos;
			} else { // move to next white cell
				++pos;
				while (is_black[pos]) ++pos;
			}
			next_start_pos = pos;
			// step i (last step)
			if (!oper[i - 1]) {
				++pos;
				if (!is_black[pos]) {
					is_black[pos] = true;
					black.insert(pos);
				}
			} else { // move to next white cell
				++pos;
				while (is_black[pos]) ++pos;
				is_black[pos] = true;
				black.insert(pos);
			}
		}
		cout << black.size() << '\n';
		int max_black = *max_element(black.begin(), black.end());
		for (int i = 1; i <= max_black; ++i) {
			if (is_black[i]) cout << i << ' ';
		}
		cout << '\n';
	}
}
// TLE Codeforce test 1