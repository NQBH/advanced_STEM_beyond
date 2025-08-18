#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int i = 0, j = n - 1; // 2 pointers
	while (i < j) {
		if (a[i] + a[j] == x) {
			cout << i << " " << j;
			return 0;
		}
		if (a[i] + a[j] < x) ++i;
		else --j;
	}
	cout << "No solution";
}