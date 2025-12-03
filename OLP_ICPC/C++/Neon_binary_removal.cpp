#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int i = s.find("11"), j = s.rfind("00");
		cout << (i != -1 && j != -1 && i < j ? "NO\n" : "YES\n");
	}
}