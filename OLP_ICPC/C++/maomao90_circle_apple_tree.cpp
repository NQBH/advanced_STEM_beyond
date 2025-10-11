#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		set<int> st;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			st.insert(x);
		}
		cout << st.size() << '\n';
	}
}