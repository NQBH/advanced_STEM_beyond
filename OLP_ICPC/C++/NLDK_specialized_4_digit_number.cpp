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

int customdecimal(int n, int k) {
    int res = 0;
    while (n) {
        res += n % k;
        n /= k;
    }
    return res;
}

void solve() {
    fre(i, 2992, 9999) {
        if (customdecimal(i, 10) == customdecimal(i, 12) && customdecimal(i, 10) == customdecimal(i, 16)) {
            cout << i << "\n";
        }
    }
}

SORAI {
    //Sanic_speed
    int t = 1;// cin >> t;
    wh(t) {solve();}
}

/*
     /\__/\
    ( • 3• )
    / >♥️<\
*/
