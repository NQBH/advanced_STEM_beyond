#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string n, rn;
	cin >> n;
	rn = n;
	reverse(rn.begin(), rn.end());
	if (stoi(rn) % stoi(n)) cout << "NO";
	else cout << "YES";
}