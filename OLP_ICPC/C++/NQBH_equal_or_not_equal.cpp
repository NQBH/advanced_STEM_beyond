#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int nN = 0;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == 'N') ++nN;
		if (nN == 1) cout << "NO\n";
		else cout << "YES\n";
	}
}