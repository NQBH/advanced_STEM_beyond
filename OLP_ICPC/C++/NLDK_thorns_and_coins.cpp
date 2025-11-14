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
#define mp make_pair
#define pf push_front
#define pb push_back
#define popf pop_front
#define popb pop_back
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
    int n, ranger = -1; cin >> n;
    string s; cin >> s;
    int a[n + 1];
    a[0] = 0;
    if (s[1] == '@') {a[1] = 1;} elif (s[1] == '*') {a[1] = -1;} else {a[1] = 0;}
    fre(i, 2, n) {
        a[i] = max(a[i - 2], a[i - 1]);
        if (a[i] == -1) {ranger = i; break;}
        if (s[i] == '*') {a[i] = -1; continue;}
        if (s[i] == '@') {++a[i];}
    }
    if (ranger == -1) {ranger = n;}
    cout << *max_element(a, a+ranger+1) << el
}
 
SORAI {
    Sanic_speed
    int t = 1; cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
