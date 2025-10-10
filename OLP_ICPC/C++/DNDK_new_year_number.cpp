#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		bool check = false;
		while (n >= 0) {
			if (n % 2020 == 0) {
				check = true;
				break;
			}
			n -= 2021;
		}
		cout << (check ? "yes" : "no") << '\n';
	}
}
