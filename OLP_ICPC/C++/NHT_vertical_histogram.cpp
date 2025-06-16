#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<char, int> m;

int main() {
	string s;
	for (int i = 0; i < 4; ++i) {
		getline(cin, s);
		for (int j = 0; j < s.size(); ++j)
			if (s[j] >= 'A' && s[j] <= 'Z')
				++m[s[j]];
	}
	int maxx = 0;
	for (auto it = m.begin(); it != m.end(); ++it)
		maxx = max(maxx, it->second);
	for (int i = 0; i < maxx; ++i) {
		for (int j = 0; j < 25; ++j) {
			if (m['A' + j] + i >= maxx)
				cout << "*" << ' ';
			else
				cout << " " << ' ';
		}
		if (m['Z'] + i >= maxx)
			cout << "*" << endl;
		else
			cout << ' ' << endl;
	}
	for (int i = 0; i < 26; i++)
		if (i == 25)
			cout << "Z" << endl;
		else
			cout << (char)('A' + i) << ' ';
	return 0;
}