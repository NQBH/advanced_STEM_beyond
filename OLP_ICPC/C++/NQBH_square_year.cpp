#include <cmath>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a;
		cin >> a;
		int b = sqrt(a);
		if (b * b == a) cout << b << ' ' << 0 << '\n';
		else cout << "-1\n";
	}
}