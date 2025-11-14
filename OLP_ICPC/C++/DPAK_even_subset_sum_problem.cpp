#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1); for (int i = 1; i <= n; cin >> a[i++]);
        int curIdx = -1;
        int firstOddIdx = -1, secondOddIdx= -1;
        for (int i = 1; i <= n && curIdx == -1 && secondOddIdx == -1; (a[i] % 2 == 0 ? curIdx = i : (firstOddIdx == -1 ? firstOddIdx = i : secondOddIdx = i)), i++);
        if (curIdx != -1) {cout << 1 << endl << a[curIdx] << endl; continue; }
        if (secondOddIdx != -1) { cout << 2 << endl << a[firstOddIdx] << " " << a[secondOddIdx] << endl; continue;}
        cout << -1 << endl;
    }
    return 0;
}