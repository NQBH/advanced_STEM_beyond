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
		string s = "";
		for (int &x : a) {
			cin >> x;
			s += 'a' + x - 1;
		}
		cout << s << flush;
	} else { // decoding
		string s;
		cin >> s;
		cout << s.size() << '\n';
		for (char c : s)
			cout << c - 'a' + 1 << ' ';
		cout << flush;
	}
}