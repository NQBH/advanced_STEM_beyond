#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << n * (n - 1) << '\n';
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			cout << i << " " << i << " " << j << '\n';
		}
}