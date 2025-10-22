#include <bits/stdc++.h>
using namespace std;
/*
(\_/)          (\___/)
( " ")		   ( ^ ^  )
 /  >> <3      he(#)(#)
/	??		   (") (")
bruth lmeo lmeo
*/
int n;
int calculate_cost(const vector<int>& chanle, int p) {
    int cost = 0;
    int t = p;
    for (int x : chanle) {
        cost += abs(x - t);
        t += 2;
    }
    return cost;
}
void solve()
{
    vector<int> chan;
    vector<int> le;

    cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x % 2) le.push_back(i); else chan.push_back(i);
    }
    int nl = le.size();
    int nc = chan.size();

    if (abs(nl - nc) > 1) {
        cout << -1 << endl;
        return;
    }
    int ans = INT_MAX;

    if (nl >= nc) ans = min(ans, calculate_cost(chan, 1));
    if (nl <= nc) ans = min(ans, calculate_cost(chan, 0));

    cout <<ans<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
