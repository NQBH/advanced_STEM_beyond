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

void moving(int n, int m, string s[], int i, int j) {
    s[i][j] = '#';
    if (i > 0 && s[i-1][j] == '.') {
        moving(n, m, s, i-1, j);
    }
    if (i < (n-1) && s[i+1][j] == '.') {
        moving(n, m, s, i+1, j);
    }
    if (j > 0 && s[i][j-1] == '.') {
        moving(n, m, s, i, j-1);
    }
    if (j < (m-1) && s[i][j+1] == '.') {
        moving(n, m, s, i, j+1);
    }
}

void solve(int n, int m, string s[]) {
    int ans = 0;
    frs(i, 0, n) {
        frs(j, 0, m) {
            if (s[i][j] == '.') {
                moving(n, m, s, i, j);
                ++ans;
            }
        }
    }
    cout << ans;
}

SORAI {
    Sanic_speed
    int n, m;
    cin >> n >> m;
    string s[n];
    frs(i, 0, n) {
        cin >> s[i];
    }
    solve(n, m, s);
}