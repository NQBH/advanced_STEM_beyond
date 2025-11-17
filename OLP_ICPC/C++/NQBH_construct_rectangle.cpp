#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b + c || b == c + a || c == a + b || (a == b && !(c & 1)) || (b == c && !(a & 1)) || (c == a && !(b & 1))) cout << "YES\n";
		else cout << "NO\n";		
	}
}