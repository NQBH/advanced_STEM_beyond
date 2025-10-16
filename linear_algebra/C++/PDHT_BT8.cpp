#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    cout << "Ma tran 0";
    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = 0; j < n; j++)
            cout << 0 << " ";
    }
    cout << "\n";
    cout << "Ma tran don vi I";
    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = 0; j < n; j++) {
            if (i == j) cout << 1 << " ";
            else cout << 0 << " ";
        }
    }
}
