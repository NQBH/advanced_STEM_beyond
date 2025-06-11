#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; cin >> n;
    int total = n * (n + 1) / 2;
    if (total % 2) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    vector<int> left, right;
    if (n % 4 == 0) {
        for (int i = 1; i <= n / 4; i++) {
            left.push_back(i);
            left.push_back(n - i + 1);
        }
        for (int i = n / 4 + 1; i <= n / 2; i++) {
            right.push_back(i);
            right.push_back(n - i + 1);
        }
    } else if (n % 4 == 3) {
        left.push_back(1);
        left.push_back(2);
        right.push_back(3);
        n -= 3;
        for (int i = 1; i <= n / 4; i++) {
            left.push_back(3 + i);
            left.push_back(3 + n - i + 1);
        }
        for (int i = n / 4 + 1; i <= n / 2; i++) {
            right.push_back(3 + i);
            right.push_back(3 + n - i + 1);
        }
    }
    cout << left.size() << endl;
    for (auto x : left) cout << x << " ";
    cout << endl << right.size() << endl;
    for (auto x : right) cout << x << " ";
}