#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    vector<int> SUM;
    int num = 0;
    while (num <= 1e6) {
        num += 2020;
        SUM.push_back(num);
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool check = false;
        for (int i = 0; i < SUM.size(); i++) {
            if (SUM[i] > n) break;
            int left = n - SUM[i];
            if (left <= i + 1) {
                check = true;
                break;
            }
        }
        if (check) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}