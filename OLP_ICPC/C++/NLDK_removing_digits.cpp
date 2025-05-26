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

const int M = 1000000007;

SORAI {
    Sanic_speed
    int s, step = 0, temp;
    cin >> s;
    int ans = 0;
    int a[8];
    while (s) {
        a[step] = s % 10;
        ++step;
        s -= (s % 10);
        s /=10;
    }
    reverse(a, a+step);
    while (true) {
        temp = *max_element(a, a+step);
        if (temp == 0) {break;}
        if (temp == a[step-1]) {a[step-1] = 0;}
        else {
            a[step-1] += (10 - temp);
            for (int i = step-2; i >= 0; --i) {
                if (a[i] == 0) {
                    a[i] = 9;
                } else {--a[i]; break;}
            }
        }
        ++ans;
    }
    cout << ans;
}