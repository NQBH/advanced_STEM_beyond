#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	cin >> S;
	if (S == "first") { // encoding
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
			while (x) {
				cout << char('a' + x % 25);
				x /= 25;
			}
			cout << 'z'; // cant use 0 here
		}
	} else { // decoding
		string s;
		cin >> s;
		cout << count(s.begin(), s.end(), 'z') << '\n';
		int a = 0, p = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'z') {
				cout << a << ' ';
				a = 0;
				p = 0;
			} else {
				a += (s[i] - 'a') * pow(25, p);
				++p;
			}
		}
	}
}
// unfinished