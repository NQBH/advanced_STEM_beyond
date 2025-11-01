#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

void tc() {
	vll ve(4);
	for (ll &i : ve) cin >> i;
	set<ll> st;
	st.insert(ve[3] - ve[2]);
	st.insert(ve[2] - ve[1]);
	st.insert(ve[0] + ve[1]);
	cout << 4 - st.size() << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--) tc();
}