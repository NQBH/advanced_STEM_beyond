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

const int N = 10005;
bool Primer[N] {false};

void Sorai_Era_sieve() {
    Primer[0] = Primer[1] = 1;
    for (int i = 4; i < N; i += 2) {
        Primer[i] = 1;
    }
    for (int i = 3; i < N; i += 2) {
        if (!Primer[i]) {
            for (int j = i*i; j < N; j += i) {
                Primer[j] = 1;
            }
        }
    }
}

void solve() {
    while (true) {
        int n; cin >> n;
        if (n == 0) {break;}
        if (n == 1 || n == 4) {cout << 0 << el}
        elif (n == 2 || n == 3) {cout << 1 << el}
        else {
            int ans = 0;
            if (!Primer[n]) {++ans;}
            int temp = 2;
            for (int i = 3; i < N; i += 2) {
                if (!Primer[i]) {
                    temp += i;
                    if (temp == n) {++ans; break;}
                    elif (temp > n) {break;}
                }
            }
            temp = 3;
            while (temp < n) {
                if (temp >= n) {break;}
                if (Primer[temp]) {temp += 2; continue;}
                int alt = temp;
                for (int i = temp + 2; i < n; i += 2) {
                    if (!Primer[i]) {
                        temp += i;
                        if (temp == n) {++ans; break;}
                        elif (temp > n) {break;}
                    }
                }
                temp = alt;
                temp += 2;
            }
            cout << ans << el
        }
    }
}

SORAI {
    //Sanic_speed
    Sorai_Era_sieve();
    int t = 1;// cin >> t;
    wh(t) {solve();}
}

/*
     /\__/\
    ( • 3• )
    / >♥️<\
*/
