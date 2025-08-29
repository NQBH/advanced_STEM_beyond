#include <array>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	vector<array<int, 3>> updates(m);
	for (array<int, 3> &update : updates) cin >> update[0] >> update[1] >> update[2];
	vector<long long> s(m + 2);
	vector<long long> add(n + 2, 0);
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		++s[x];
		--s[y + 1];
	}
	for (int i = 1; i <= m; ++i) {
		s[i] += s[i - 1];
		// at the same time compute the 2nd difference array
		add[updates[i - 1][0]] += s[i] * updates[i - 1][2];
		add[updates[i - 1][1] + 1] -= s[i] * updates[i - 1][2];
	}
	for (int i = 1; i <= n; ++i) {
		add[i] += add[i - 1]; // apply prefix sums
		cout << a[i] + add[i] << ' ';
	}
	cout << '\n';
}