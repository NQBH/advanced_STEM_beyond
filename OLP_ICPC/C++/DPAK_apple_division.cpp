#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;
int n;

signed main() {
    cin >> n;
    a.resize(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i - 1];
    }
    int mask = 1 << n;
    vector<int> groupA, groupB;
    int minWeight = INT_MAX;
    int gA = 0, gB = 0;
    for (int i = 0; i < mask; i++) {
        int sumA = 0, sumB = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sumA += a[j];
            }
            else {
                sumB += a[j];
            }
        }
        if (abs(sumA - sumB) < minWeight) {
            groupA.clear(); groupB.clear();
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    groupA.push_back(a[j]);
                }
                else {
                    groupB.push_back(a[j]);
                }
            }
            minWeight = abs(sumA - sumB);
            gA = sumA, gB = sumB;
        }
    }
    int ans = abs(gA - gB);
    cout << ans << endl;
    /*
    for (int a : groupA) {
        cout << a << " ";
    }
    cout << endl;
    for (int b : groupB) {
        cout << b << " ";
    }
    */
}