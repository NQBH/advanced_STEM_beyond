#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> a(k);
		for (int i = 0; i < length(s); ++i) {
			a[i] = stoi(s[i]);
		}
	}
}