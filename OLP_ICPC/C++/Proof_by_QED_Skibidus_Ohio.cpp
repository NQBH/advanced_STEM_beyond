#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

void tc() {
	string str;
	cin >> str;
	for (ll i = 1; i < str.size(); i++)
		if (str[i - 1] == str[i]) {
			cout << "1\n";
			return;
		}
	cout << str.size() << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) tc();
}