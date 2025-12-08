#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e18;
const int MOD = 1e9 + 7;

struct robot {
    int x;
    int r;
    int q;
};

int n, k;

vector<robot> a;

bool compare(const robot& cur, const robot& other) {
    return cur.q < other.q;
}
bool checkSubtask1() {
    return n <= 1e3;
}
void doSubtask1() {
    sort(a.begin() + 1, a.end(), compare);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n && (a[j].q - a[i].q <= k); j++) {
            if (abs(a[i].x-a[j].x) <=  min(a[i].r,a[j].r)) ans++;
        } 
    }
    cout << ans;
}

void doSubtask2() {

}

signed main() {
    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].r >> a[i].q;
    }   
    if (checkSubtask1()) return doSubtask1(), 0;
    //if (checkSubtask2()) return doSubtask2(), 0;
    doSubtask1();
}