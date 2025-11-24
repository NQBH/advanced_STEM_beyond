#include <iostream>
using namespace std;

int main() {
	string S;
	int n;
	double ans = -1;
	cin >> n;
	while (n--) {
		int a = 0;
		string s;
		cin >> s;
		for (char c : s)
			if (c >= '0' && c <= '9') ++a;
		double w = 1.0 * a / ((double)s.size());
		if (w > ans) {
			ans = w;
			S = s;
		}		
	}
	cout << S;
}