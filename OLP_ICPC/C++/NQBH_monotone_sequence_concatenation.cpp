#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	int a[m], b[n], c[m + n];
	for (int i = 0; i < m; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	int idx_a = 0, idx_b = 0; // 2 pointers
	for (int i = 0; i < m + n; ++i)
		if (a[idx_a] <= b[idx_b]) c[i] = a[idx_a++];
		else c[i] = b[idx_b++];
	for (int i = 0; i < m + n; ++i) cout << c[i] << ' ';
}