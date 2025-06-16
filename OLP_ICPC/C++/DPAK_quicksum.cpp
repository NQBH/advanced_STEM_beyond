/*
Source: ACM Mid-Central United States 2006.
IDs for online judges: POJ 3094, ZOJ 2812, UVA 3594.
Status: Accepted
*/
#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	while (getline(cin, s) && s != "#") {
		int ans = 0;
		for (int i = 0; i < static_cast<int>(s.size()); i++) {
			if (s[i] == ' ') continue;
			ans += (i + 1) * (s[i] - 'A' + 1);
		}
		cout << ans << endl;
	}
}