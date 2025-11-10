#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define popcount __builtin_popcount
#define all(a) (a).begin(), (a).end()
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 f(high_resolution_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string t; cin >> t;
	if (t == "first") {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			cout << char(a + 'a' - 1);
		}
	} else {
		string s; cin >> s;
		cout << s.size() << " ";
		for (char& c : s) cout << c - 'a' + 1 << " ";
	}
}