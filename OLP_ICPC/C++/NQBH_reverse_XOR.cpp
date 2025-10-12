#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

string dec2bin(ll n) {
	string bin_string = "";
	while (n) {
		bin_string += (n % 2 == 0 ? '0' : '1');
		n /= 2;
	}
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
			/*
			// get binary representation of n
			vector<bool> a;
			while (n) {
				a.push_back(n % 2);
				n /= 2;
			}
			// for (int i = 0; i < a.size(); ++i) cout << a[i];
			// check symmetry of vector a
			if (a.size() % 2 && a.back() == 0)
			*/
			string bin_n = dec2bin(n);
			if (bin_n.size() % 2) { // odd length binary representation
				if (n % 2) cout << "NO\n";
				else {
					bin_n = "0" + bin_n;
					if (isPalindrome(bin_n)) cout << "YES\n";
					else cout << "NO\n";
				}
			} else { // even length binary representation
				string new_bin_n = "0" + bin_n;
				if (isPalindrome(bin_n) || isPalindrome(new_bin_n)) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}