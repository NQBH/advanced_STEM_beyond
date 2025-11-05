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
#define frs(i, a, b) for(ll i = a; i < b; ++i)
#define fre(i, a, b) for(ll i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
using namespace std;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    int a[n], need = n-2;
    frs(i, 0, n) {cin >> a[i];}
    sort(a, a + n);
    frs(i, 0, n-1) {
        if (i > 0) {
            if (a[i] == a[i-1]) {continue;}
        }
        frs (j, i+1, n) {
            if (a[i] * a[j] == need) {
                cout << a[i] << " " << a[j] << el
                ret
            } elif (a[i] * a[j] > need) {break;}
        }   
    }
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