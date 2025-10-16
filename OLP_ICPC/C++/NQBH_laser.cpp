#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		vector<int> a(n), b(m);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
		cout << m + n << '\n';
	}
}