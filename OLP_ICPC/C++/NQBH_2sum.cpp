#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i] + a[j] == x) {
				cout << i + 1 << " " << j + 1;
				return 0;
			}
	cout << "IMPOSSIBLE";
}