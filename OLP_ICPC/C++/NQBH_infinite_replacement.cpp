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
		if (t.size() > 1) {
			if (count(t.begin(), t.end(), 'a')) cout << "-1\n";
			else cout << s.size() * t.size() << '\n';
		} else if (t == "a") cout << "1\n";
		else cout << s.size() + 1 << '\n';
	}
}
// wrong answer 3334th numbers differ - expected: '64', found: '18'
// WTF 3334?