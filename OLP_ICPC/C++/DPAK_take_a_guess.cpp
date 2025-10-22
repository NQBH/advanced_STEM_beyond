#include <bits/stdc++.h>
#define APC signed
#define int long long
using namespace std;

const int oo = 1e9;

int AND(int a, int b) {
    cout << "and " << a << " " << b << endl;
    int x; cin >> x;
    return x;
}

int OR(int a, int b) {
    cout << "or " << a << " " << b << endl;
    int x; cin >> x;
    return x;
}
// (a & b) + (a | b) = a + b
// ex: 6&3=2, 6|3 =110 | 011 = 111 = 7 + 2 = 9
APC main() {
    int n, k; cin >> n >> k;
    vector<int>a(n + 1);

    // a1 + a2 = x
    int x = AND(1, 2) + OR(1, 2);
    // a1 + a3 = y
    int y = AND(1, 3) + OR(1, 3);
    //a2+a3 = z
    int z = AND(2, 3) + OR(2, 3);
    // x+y-z = 2*a1
    a[1] = x + y - z;
    a[1] /= 2;
    a[2] = x - a[1];
    a[3] = y - a[1];
    for (int i = 4; i <= n; i++) {
        // a1 + ai
        int x = AND(1, i);
        int y = OR(1, i);
        a[i] = x + y - a[1];
    }
    sort(a.begin() + 1, a.end());
    cout << "finish " << a[k];
}

