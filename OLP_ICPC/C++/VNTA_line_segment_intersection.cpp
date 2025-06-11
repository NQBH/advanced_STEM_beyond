#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct P {
    ll x;
    ll y;
};

int ori(P a, P b, P c) {
    ll v = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (v == 0) return 0;
    return (v > 0) ? 1 : 2;
}

bool onSeg(P a, P b, P c) {
    return (b.x <= max(a.x, c.x) &&
            b.x >= min(a.x, c.x) &&
            b.y <= max(a.y, c.y) &&
            b.y >= min(a.y, c.y));
}

bool check(P a, P b, P c, P d) {
    int o1 = ori(a, b, c);
    int o2 = ori(a, b, d);
    int o3 = ori(c, d, a);
    int o4 = ori(c, d, b);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSeg(a, c, b)) return true;
    if (o2 == 0 && onSeg(a, d, b)) return true;
    if (o3 == 0 && onSeg(c, a, d)) return true;
    if (o4 == 0 && onSeg(c, b, d)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        P p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        if (check(p1, p2, p3, p4)) cout << "YES\n";
        else cout << "NO\n";
    }
}