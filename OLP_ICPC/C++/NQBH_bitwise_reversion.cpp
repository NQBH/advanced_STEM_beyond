#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, x, y, z;
	cin >> t;
	while (t--) {
		cin >> x >> y >> z;
		int A = x & y, B = y & z, C = x & z;
		if (A == B && (A == C)) cout << "YES\n";
		else cout << "NO\n";
	}
}