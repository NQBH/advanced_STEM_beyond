#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int ans = 1;
		string s;
		cin >> s;
		if (s[0] == '0') {
			cout << "0\n";
			continue;
		}
		if (s[0] == '?') ans = 9;
		for (int i = 1; i < (int)s.size(); ++i)
			if (s[i] == '?') ans *= 10;
		cout << ans << '\n';
	}
}