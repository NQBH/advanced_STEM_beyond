#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ret return 0;
#define ret return;
#define all(x) x.begin(), x.end()
#define el "\n";
#define elif else if
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pops pop_back
#define cYES cout << "YES" << "\n";
#define cNO cout << "NO" << "\n";
#define cYes cout << "Yes" << "\n";
#define cNo cout << "No" << "\n";
#define cel cout << "\n";
#define frs(i, a, b) for(int i = a; i < b; ++i)
#define fre(i, a, b) for(int i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
using namespace std;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    vector<int> a1, a2;
    if (n % 4 == 0) {
        int p1 = 1, p2 = 2;
        a1.pb(1);
        a2.pb(2);
        while (p1 <= n) {
            if (p1 % 2 == 1) {p1 += 3;}
            else {++p1;}
            if (p1 <= n) {a1.pb(p1);}
        }
        while (p2 <= n) {
            if (p2 % 2 == 0) {++p2;}
            else {p2 += 3;}
            if (p2 <= n) {a2.pb(p2);}
        }
        cYES
        cout << n / 2 << el
        frs(i, 0, a1.size()) {
            cout << a1[i] << " ";
        }
        cel
        cout << n / 2 << el
        frs(i, 0, a2.size()) {
            cout << a2[i] << " ";
        }
        cel
    } elif (n % 2 == 0) {
        cNO
    } else {
        int check = (n - 1) / 2 + 1;
        if (check % 2 == 1) {
            cNO
        } else {
            vector<int> a1, a2;
            int p1 = 2, p2 = 3;
            a1.pb(1);
            a1.pb(2);
            if (n != 3) {a1.pb(n - 1);}
            a2.pb(n);
            if (n != 3) {a2.pb(3);}
            while (p1 <= (n - 2)) {
                if (p1 % 2 == 0) {p1 += 3;}
                else {++p1;}
                if (p1 < (n - 1)) {a1.pb(p1);}
            }
            while (p2 <= (n - 2)) {
                if (p2 % 2 == 1) {++p2;}
                else {p2 += 3;}
                if (p2 < (n - 1)) {a2.pb(p2);}
            }
            cYES
            cout << (n / 2 + 1) << el
            frs(i, 0, a1.size()) {
                cout << a1[i] << " ";
            }
            cel
            cout << n / 2 << el
            frs(i, 0, a2.size()) {
                cout << a2[i] << " ";
            }
            cel
        }
    }
}

SORAI {
    Sanic_speed
    int t = 1; //cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
