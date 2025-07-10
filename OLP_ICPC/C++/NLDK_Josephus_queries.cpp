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

int Looping(int n, int k) {
    if (n == 1) {return 1;}
    if ((n + 1) / k >= 2) {
        if (k * 2 > n) {return 2 * k % n;}
        else {return 2 * k;}
    }
    int temp = Looping(n / 2, k - (n + 1) / 2);
    if (n & 1) {return 2 * temp + 1;}
    else {return 2 * temp - 1;}
}

void solve() {
    int n, k;
    cin >> n >> k;
    cout << Looping(n, k) << el
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 3 5 7 9 11 13 15 17 19
1 5 9 13 17
1 9 17
9
*/
SORAI {
    Sanic_speed
    int t; cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
