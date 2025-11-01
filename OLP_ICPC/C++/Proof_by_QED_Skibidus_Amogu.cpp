#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

void tc() {
	string str;
	cin >> str;
    str.pop_back();
    str.pop_back();
    cout << str + "i" << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--) tc();
}