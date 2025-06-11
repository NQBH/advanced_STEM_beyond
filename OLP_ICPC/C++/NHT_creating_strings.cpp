#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
vector<string> ans;

bool check(string s, int i, int l) {
	for (int j = l; j < i; ++j)
		if (s[j] == s[i])
			return false;
	return true;
}

void per(string s, int l, int r) {
	if (l == r)
		ans.push_back(s);
	for (int i = l; i <= r; ++i)
		if (check(s, i, l)) {
			swap(s[l], s[i]);
			per(s, l + 1, r);
			swap(s[l], s[i]);
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	per(s, 0, s.size() - 1);
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (const auto &s : ans)
		cout << s << endl;
	return 0;
}