#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ret return 0;
#define ret return;
#define all(x) x.begin(), x.end()
#define el "\n";
#define elif else if
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define pops pop_back
#define cYES cout << "YES" << "\n";
#define cNO cout << "NO" << "\n";
#define cYes cout << "Yes" << "\n";
#define cNo cout << "No" << "\n";
#define frs(i, a, b) for(int i = a; i < b; ++i)
#define fre(i, a, b) for(int i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
#define fileinout(name) freopen(name".INP", "r", stdin);freopen(name".OUT", "w", stdout);
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;
    int a[n];
    frs(i, 0, n) {
        cin >> a[i];
    }
    if (n==1) {
        cYES
        cout << 1 << el
        ret
    }
    frs(i, 0, n) {
        bool mark = 1;
        frs(j, 0, n) {
            if (i == j) {continue;}
            if (abs(a[i] - a[j]) % k == 0) {
                mark = 0;
                break;
            }
        }
        if (mark) {
            cYES
            cout << (i+1) << el
            ret
        }
    }
    cNO
}

SORAI {
    Sanic_speed
    int t;
    cin >> t;
    wh(t) {solve();}
}

/**
     /\__/\
    ( • 3• )
     / >♥️<\
**/