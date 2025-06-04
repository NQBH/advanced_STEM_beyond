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

const int M = 1e9 + 7;
const int N = 1000001;
int Facting[1000009];
int invFacting[1000009];

int Powering(int a, int b) {
    if (b == 0) {return 1;}
    if (b == 1) {return a;}
    int temp = Powering(a, b / 2);
    temp = ((1LL * temp * temp) % M);
    if (b % 2) {temp = ((1LL * temp * a) % M);}
    return temp;
}

void GenFact() {
    Facting[0] = 1;
    Facting[1] = 1;
    Facting[2] = 2;
    fre(i, 3, N) {
        Facting[i] = (1LL * Facting[i - 1] * i % M);
    }

    invFacting[N] = Powering(Facting[N], M - 2);
    for (int i = N - 1; i >= 0; --i) {
        invFacting[i] = 1LL * invFacting[i + 1] * (i + 1) % M;
    }
}

int C(int a, int b) {
    if (b > a) {return 0;}
    return (1LL * Facting[a] * invFacting[b] % M) * invFacting[a - b] % M;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << C(a, b) << el
}

SORAI {
    Sanic_speed
    GenFact();
    int t; cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
