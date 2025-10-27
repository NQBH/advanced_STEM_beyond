#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		if (n <= 2) {
			cout << "YES\n";
			continue;
		}
		/*
		bool ok = true;
		vector<int> rabbit_direction(n, 0); // 1: right, -1: left, 0: not yet decided, 2: flower
		// rabit 0
		if (s[0] == '0') { // rabit at pot 0
			if (s[1] == '0') rabbit_direction[0] = 1;
			else { // 0 1
				if (s[2] == '1') rabbit_direction[0] = -1;
				else rabbit_direction[0] = 1;
			}
		} else rabbit_direction[0] = 2;
		// last rabit
		if (s[n - 1] == '0') {
			if (s[n - 2] == '0') rabbit_direction[n - 1] = -1;
			else { // 1 0
				if (s[n - 3] == '1') rabbit_direction[n - 1] = 1;
				else rabbit_direction[n - 1] = -1;
			}
		} else rabbit_direction[n - 1] = 2;		
		int num1_left = 0, num1_right = 0;
		bool done = false;	
		for (int i = 1; i < n - 1; ++i) {
			if (s[i] == '0') { // rabbit at pot i
				if (s[i - 1] == '0') s[i] = -1;
				else if (s[i + 1] == '0') s[i] = 1;
				else { // 1 0 1
					if (num1_left >= 2) rabbit_direction[i] = 1;
					else { // 0 1 0
						if (i >= 2) {
							if (rabbit_direction[i - 2] == -1) {
								cout << "NO\n";
								done = true;
								break;
							} else rabbit_direction[i] = -1;
						} else rabbit_direction[i] = 1;
					}
				}
				num1_left = 0;
			} else { // flower at pot i
				++num1_left;
				rabbit_direction[i] = 2;
			}
		}
		for (int i = 0; i < n; ++i) cout << rabbit_direction[i] << ' ';
		if (done) continue;
		else cout << "YES\n";
		*/
		if (n == 3) {
			if (s == "101") cout << "NO\n";
			else cout << "YES\n";
			continue;
		}
		if (s[0] == '1' && s[1] == '0' && s[2] == '1' && s[3] == '1') {
			cout << "NO\n";
			continue;
		} else if (s[n - 1] == '1' && s[n - 2] == '0' && s[n - 3] == '1' && s[n - 4] == '1') {
			cout << "NO\n";
			continue;
		} else {
			bool done = false;
			for (int i = 2; i < n - 1; ++i) {
				if (s[i] == '0' && s[i - 1] == '1' && s[i - 2] == '1' && s[i + 1] == '1' && s[i + 2] == '1') {
					cout << "NO\n";
					done = true;
					break;
				}
			}
			if (done) continue;
			else cout << "YES\n";
		}		
	}
}