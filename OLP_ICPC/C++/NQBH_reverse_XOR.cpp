#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

string dec2bin_symmetrize(ll n) {
	string bin_string = "";
	int num_trailing_0 = 0;
	bool stop = false;
	while (n) {
		// bin_string += (n % 2 == 0 ? '0' : '1');
		if (n % 2 == 0) { // bit 0
			if (!stop) ++num_trailing_0;
			bin_string += '0';
		} else { // bit 1
			stop = true;
			bin_string += '1';
		}
		n /= 2;
	}
	for (int i = 0; i < num_trailing_0; ++i) bin_string += '0';
	reverse(bin_string.begin(), bin_string.end());
	return bin_string;
}

bool isPalindrome(const string& s) {
	int left = 0;
	int right = s.length() - 1;
	while (left < right) {
		if (s[left] != s[right]) {
			return false; // characters don't match, not a palindrome
		}
		left++;
		right--;
	}
	return true; // all characters matched, it's a palindrome
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n == 0) cout << "YES\n"; // x = 1
		else if (n == 1) cout << "NO\n";
		else {
			string bin_n = dec2bin_symmetrize(n);
			// cout << bin_n << '\n';
			if (bin_n.size() % 2) { // odd length binary representation
				if (bin_n[(bin_n.size() - 1) / 2] == '1') cout << "NO\n"; // middle bit must be 0 after XOR
				else {
					if (isPalindrome(bin_n)) cout << "YES\n";
					else cout << "NO\n";
				}
			} else {
				if (isPalindrome(bin_n)) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}