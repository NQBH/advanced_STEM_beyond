#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<bool> present(1001, false);
		int n_pb = 0;
		for (int &x : a) {
			cin >> x;
			if (!present[x]) {
				present[x] = true;
				++n_pb;
			}
		}
		while (1) {
			if (n_pb <= 1000 && present[n_pb]) {
				cout << n_pb << '\n';
				break;
			} else ++n_pb;
		}
	}
}