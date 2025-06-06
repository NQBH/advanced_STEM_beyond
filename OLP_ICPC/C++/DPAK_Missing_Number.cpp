#include <bits/stdc++.h>
#define int long long
using namespace std;
bool done = false;
int i = 0;
signed main() {
    int n; cin >> n;
	int t = n;
    int x;
    vector<int> a;
    for (; n-- > 1; cin >> x, a.push_back(x), x = 0);

    for (sort(a.begin(), a.end()) ; i + 1 < a.size() && !done; (a[i + 1] - a[i] == 2 ? (cout << a[i] + 1, done = true) : i++));

    for (; !done; (a[0] != 1 ? cout << 1 : cout << t), done = true); 

    return 0;
}
