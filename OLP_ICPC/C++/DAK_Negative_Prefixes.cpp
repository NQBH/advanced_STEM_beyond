#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];

    vector<int> l(n);
    vector<int> ul_v;

    for (int i = 0; i < n;i++) {
        cin >> l[i];
        if (l[i] == 0) ul_v.push_back(a[i]);
    }
    sort(ul_v.begin(), ul_v.end(), greater<int>());
    int index = 0;

    for (int i = 0; i < n; ++i)
        if (l[i] == 1) cout <<a[i]<< " ";
         else {
            cout << ul_v[index] << " ";
            index++;
        }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
