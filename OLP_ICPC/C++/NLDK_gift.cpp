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
#define pf push_front
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

void solve() {
    int n, k, step = 0;
    cin >> n >> k;
    int a[n];
    int stacker[1000000];
    int cnt[1000000];
    frs(i, 0, n) {cin >> a[i];}
    frs(i, 0, n) {
        int temp = step; 
        frs(j, 0, temp) {
            if (stacker[j] <= (a[i] - k)) {
                stacker[step] = a[i];
                cnt[step] = cnt[j] + 1;
                ++step;
            }
        }
        stacker[step] = a[i];
        cnt[step++] = 1;
    }
    int ans = *max_element(cnt, cnt+step);
    cout << ans << el
}

SORAI {
    Sanic_speed
    int t; cin >> t;
    wh(t) {solve();}
}