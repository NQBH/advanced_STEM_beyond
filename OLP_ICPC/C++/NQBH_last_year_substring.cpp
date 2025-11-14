#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		if (s.substr(0, 4) == "2020" || s.substr(n - 4, 4) == "2020") cout << "YES\n";
		else if (s.substr(0, 1) + s.substr(n - 3, 3) == "2020" || s.substr(0, 2) + s.substr(n - 2, 2) == "2020" || s.substr(0, 3) + s[n - 1] == "2020") cout << "YES\n";
		else cout << "NO\n";		
	}
}