#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }
    return true; // Is a palindrome
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		string s;
		cin >> s;
		if (isPalindrome(s)) cout << "0\n\n";
		else {
			vector<int> pos0;
			for (int i = 0; i < n; ++i)
				if (s[i] == '0') {
					++ans;
					pos0.push_back(i);
				}
			if (pos0.empty()) cout << "0\n\n";
			else {
				cout << ans << '\n';
				for (int x : pos0) cout << x + 1 << ' ';
				cout << '\n';
			} 
		}
	}
}