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
#define frs(i, a, b) for(int i = a; i < b; ++i)
#define fre(i, a, b) for(int i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
using namespace std;
typedef unsigned long long ull;

void solve() {
    
}

SORAI {
    Sanic_speed
    int n; cin >> n;
    int st = 2, m; cin >> m;
    int a[m], b[m];
    frs(i, 0, m) {a[i] = 1; b[i] = 0;}
    while (st <= n) {
        if (st % 2 == 0) {
            b[0] = 0;
            frs(i, 1, m)  {b[0] += a[i];}
            frs(i, 1, m) {
                b[i] = 0;
                frs(j, 0, m) {
                    if (j == (i-1)) {
                        j = i;
                        continue;
                    }
                    b[i] += a[j];
                }
            }
        } else {
            a[m-1] = 0;
            frs(i, 0, (m-1)) {
                a[m-1] += b[i];
            }
            frs(i, 0, (m-1)) {
                a[i] = 0;
                frs(j, 0, m) {
                    if (j == i) {
                        ++j;
                        continue;
                    }
                    a[i] += b[j];
                }
            }
        }
        ++st;
    }
    ll ans = 0;
    if (st % 2 == 0) {
        frs(i, 0, m) {
            ans += a[i];
        }
    } else {
        frs(i, 0, m) {
            ans += b[i];
        }
    }
    cout << ans;
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
