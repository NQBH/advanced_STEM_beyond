#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int i = 1;
	while (5 * i * (i + 1) < 2 * (240 - k)) ++i;
	if (5 * i * (i + 1) == 2 * (240 - k)) cout << min(i, n);
	else cout << min(i - 1, n);
}