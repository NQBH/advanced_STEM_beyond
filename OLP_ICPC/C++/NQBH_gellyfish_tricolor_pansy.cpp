#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (min(a, c) >= min(b, d)) cout << "Gellyfish\n";
		else cout << "Flower\n";
	}
}