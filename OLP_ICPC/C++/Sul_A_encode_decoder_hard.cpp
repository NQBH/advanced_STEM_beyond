#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define popcount __builtin_popcount
#define all(a) (a).begin(), (a).end()
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T,null_type,less_equal<>,rb_tree_tag,tree_order_statistics_node_update>;

string encode(int x) {
	string s(7, 'a');
	for (int i = 0; i < 7; ++i) {
		s[i] = x % 26 + 'a';
		x /= 26;
	}
	return s;
}

int decode(string s) {
	int x = 0;
	for (int i = 6; i >= 0; --i) x = x * 26 + s[i] - 'a';
	return x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;
    cin >> t;
    if (t == "first") {
    	int n;
    	cin >> n;
    	for (int i = 0; i < n; ++i) {
    		int a;
    		cin >> a;
    		cout << encode(a);
    	}
    } else {
    	string s;
    	cin >> s;
    	cout << s.size() / 7 << " ";
    	for (int i = 0; i < s.size(); i += 7) {
    		string u = s.substr(i, 7);
    		cout << decode(u) << " ";
    	}
    }
}