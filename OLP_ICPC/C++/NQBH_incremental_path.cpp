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
		for (int i = 1; i <= n; ++i) { // person i
			int pos = 1; // start from cell 1
			for (int j = 0; j < i; ++j) { // execute i commands
				if (!oper[j]) ++pos;
				else { // s[i] = 'B'
					++pos;
					while (is_black[pos]) ++pos;
				}
			}
			if (!is_black[pos]) {
				is_black[pos] = true; // color the last visited cell black
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