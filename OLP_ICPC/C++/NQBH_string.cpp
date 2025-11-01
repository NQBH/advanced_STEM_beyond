#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int ans = 0;
		string s;
		cin >> s;
		for (char c : s)
			if (c == '1') ++ans;
		cout << ans << '\n';
	}
}