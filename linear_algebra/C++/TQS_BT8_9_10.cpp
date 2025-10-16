#include <bits/stdc++.h>
using namespace std;
#define ll int

int main()
{
    cout << "Bai 8:" << "\n";
    cout << "Nhap phan tu n: ";
    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n, 0)), b(n, vector<ll>(n, 0));
    cout << "Ma tran 0(n): " << "\n";
    for (auto i : a) {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "Ma tran I(n): " << "\n";
    ll i = 0, j = 0;
    while (i < n) {
        b[i++][j++] = 1;
    }
    for (auto i : b) {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "Bai 9: \n";
    cout << "Nhap n: \n";
    cin >> n;
    cout << "Nhap phan tu cua ma tran: \n";
    vector<vector<ll>> a1(n, vector<ll>(n));
    for (auto &i : a1)
        for (auto &j : i)
            cin >> j;
    cout << "Ma tran duong cheo: ";
    bool ans = true;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (a1[i][j] == 0) continue;
            if (j == i) continue;
            ans = false;
            break;
        }
        if (!ans) break;
    }
    cout << ans << "\n";
    if (ans) {
        cout << "Ma tran tam giac tren: " << ans << "\n";
        cout << "Ma tran tam giac duoi: " << ans << "\n";
    }
    else {
        ans = true;
        for (ll i = 1; i < n; ++i) {
            for (ll j = 0; j < i; ++j) {
                if (a1[i][j] == 0) continue;
                ans = false;
                break;
            }
            if (!ans) break;
        }
        cout << "Ma tran tamm giac tren: " << ans << "\n";
        ans = true;
        for (ll i = 0; i < n - 1; ++i) {
            for (ll j = i + 1; j < n; ++j) {
                if (a1[i][j] == 0) continue;
                ans = false;
                break;
            }
            if (!ans) break;
        }
        cout << "Ma tran tam giac duoi: " << ans << "\n";
    }
    ans = true;
    vector<vector<ll>> a2(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            a2[i][j] = a1[j][i];
        }
    }
    if (a1 != a2) ans = false;
    cout << "Ma tran doi xung: " << ans << "\n";
    cout << "Bai 10: " << "\n";
    n = 2;
    vector<vector<ll>> a3(n, vector<ll>(n));
    cout << "Nhap cac phan tu cua ma tran: " << "\n";
    for (auto &i : a3)
        for (auto &j : i)
            cin >> j;
    cout << "A = " << a3[0][0] * a3[1][1] - (a3[0][1] * a3[1][0]);
}
