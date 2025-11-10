#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string a;
		cin >> a;
		if (a.size() < 3 || a[0] != '1' || a[1] != '0' || a[2] == '0') cout << "NO\n";
		else if (a.size() == 3 && a[2] == '1') cout << "NO\n";
		else cout << "YES\n";
	}
}