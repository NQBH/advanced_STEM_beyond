#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	string s;
	cin >> n >> s;
	vector<int> room(10, 0);
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'L') {
			int j = 0;
			while (room[j]) ++j;
			room[j] = 1;
		} else if (s[i] == 'R') {
			int j = 9;
			while (room[j]) --j;
			room[j] = 1;
		} else room[s[i] - '0'] = 0;
	}
	for (int i = 0; i < 10; ++i) cout << room[i];
}