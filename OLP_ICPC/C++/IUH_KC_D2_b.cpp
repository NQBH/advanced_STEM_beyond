#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e18;
const int MOD = 1e9 + 7;
int n;
vector<int>a;

bool checkSubtask1() {
    return n <= 1e3;
}

bool checkSubtask2() {
    return true;
}
void doSubtask1() {
    sort(a.begin() + 1, a.end());
    int MAX = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = i - 1; j >= 1; j--) {
            MAX = max(MAX, a[i] % a[j]);
        }
    }
    cout << MAX;
}

void doSubtask2() {
    set<int> ms;
    vector<int>b;
    for (int i = 1; i <= n; i++) ms.insert(a[i]);
    for (auto it : ms) {
        b.push_back(it);
    }
    int ans = 0;
    n = b.size();
    for (int i = 0; i < n; i++) {
        int val = b[i], j = i + 1;
        while (j < n) {
            while (val <= b[j]) {
                val += b[i];
            }
            int l = j, r = n - 1;
            int idx = n;
            while (l <= r) {
                int mid = l + r >> 1;
                if (b[mid] >= val) {
                    idx = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            j = idx;
            ans = max(ans, b[j - 1] - val  + b[i]);
        }
    }
    cout << ans;
}

signed main() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

//    if (checkSubtask1()) return doSubtask1(), 0;
    if (checkSubtask2()) return doSubtask2(), 0;
    doSubtask1();
}