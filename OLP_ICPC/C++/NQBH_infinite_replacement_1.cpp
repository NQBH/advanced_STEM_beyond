#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string s, t;
		cin >> s >> t;
		if (t == "a") cout << "1\n";
		else if (count(t.begin(), t.end(), 'a')) cout << "-1\n";
		else cout << (1ll << s.size()) << '\n';
	}
}