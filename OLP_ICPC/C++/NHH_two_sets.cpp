#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        sum += a[i]; // 28
    }

    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    } else {
        cout << "YES" << endl;
    }

    ll half = sum / (ll) 2; //  28/2 = 14
    vector<ll> l, r;
    for (int i = n; i >= 1; i--) {
        if (half >= i) {
            l.push_back(i);
            half -= i;
        } else {
            r.push_back(i);
        }
    }

    cout << l.size() << "\n";
    for (int i = 0; i < l.size(); i++) {
        cout << l[i] << " ";
    }
    cout << r.size() << "\n";
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << " ";
    }

    return 0;
}