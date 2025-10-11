#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1);
        vector<int> alice, bob;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) alice.push_back(a[i]);
            else bob.push_back(a[i]);
        }
        sort(alice.begin(), alice.end(), greater<int>());
        sort(bob.begin(), bob.end(), greater<int>());
        int aPoint = 0, bPoint = 0;
        int i = 0, j = 0;
        bool turn = true;
        while (i < alice.size() || j < bob.size()) {
            if (turn) {
                if (i >= alice.size()) {
                    j++;
                }
                else if (j >= bob.size()) {
                    aPoint += alice[i++];
                }
                else if (alice[i] >= bob[j]) {
                    aPoint += alice[i++];
                }
                else {
                    j++;
                }
            }
            else {
                if (i >= alice.size()) {
                    bPoint += bob[j++];
                }
                else if (j >= bob.size()) {
                    i++;
                }
                else if (alice[i] <= bob[j]) {
                    bPoint += bob[j++];
                }
                else {
                    i++;
                }
            }
            turn = !turn;
        }
        //cout << i << " " << j << " " << aPoint << " " << bPoint << endl;
        if (bPoint == aPoint) cout << "Tie";
        else if (bPoint > aPoint)  cout << "Bob";
        else cout << "Alice";
        cout << endl;
    }
}