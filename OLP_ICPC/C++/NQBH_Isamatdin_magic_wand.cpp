#include <algorithm>
#include <iostream>
#include <vector>
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
		int num_odd = 0, num_even = 0;
		for (int &x : a) {
			cin >> x;
			if (x & 1) ++num_odd;
			else ++num_even;
		}
		if (num_odd == 0 || num_even == 0) {
			for (int &x : a) cout << x << ' ';
			cout << '\n';
		} else {
			sort(a.begin(), a.end());
			for (int &x : a) cout << x << ' ';
			cout << '\n';
		}
	}
}