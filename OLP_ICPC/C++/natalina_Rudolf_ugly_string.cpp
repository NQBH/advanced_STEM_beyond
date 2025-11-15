#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ll t;
	cin >> t;
	for (ll c = 0; c < t; ++c) {
		ll n;
		cin >> n;
		string s;
		cin >> s;
		vector<ll> va;
		for (string sul : {"mapie", "pie", "map"}) {
			for (size_t pos = 0; (pos = s.find(sul, pos)) != string::npos;) {
				s[pos + sul.length() / 2] = '?';
				va.push_back(pos + sul.length() / 2);
			}
		}
		cout << va.size() << '\n';
	}
}