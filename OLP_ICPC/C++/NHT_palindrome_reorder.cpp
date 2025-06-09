#include <bits/stdc++.h>
#define ll long long
using namespace std;

string str;
int freq[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> str;
	for (int i = 0; i < static_cast<int>(str.size()); ++i)
		freq[str[i] - 'A']++;
	int cnt(0);
	for (int i = 0; i < 26; ++i)
		if (freq[i] % 2 == 1)
			cnt++;
	if (cnt > 1)
		cout << "NO SOLUTION\n";
	else {
		string ans(str.size(), ' ');
		int left = 0, right = str.size() - 1;
		for (int i = 0; i < static_cast<int>(str.size()); ++i) {
			if (freq[str[i] - 'A'] % 2) {
				ans[str.size() / 2] = str[i];
				freq[str[i] - 'A']--;
			}
			while (freq[str[i] - 'A'] > 0) {
				ans[left++] = ans[right--] = str[i];
				freq[str[i] - 'A'] -= 2;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}