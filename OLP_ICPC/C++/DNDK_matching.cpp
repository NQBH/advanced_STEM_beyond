#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ans = 1;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '?') cnt++;
		}

		if (s[0] == '0') {
			cout << "0" << endl;
			continue;
		}
		else if (s[0] == '?') {
			ans = 9 * pow(10, cnt - 1);
			cout << ans << endl;
			continue;
		}
		else {
			ans = pow(10, cnt);
			cout << ans << endl;
		}
	}
}
