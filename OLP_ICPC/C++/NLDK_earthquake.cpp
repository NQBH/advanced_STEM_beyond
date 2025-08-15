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
#define popb pop_back
#define mp make_pair
#define popf pop_front
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
    int n, k, c, ans;
    cin >> n >> k >> c;
    vector<vector<int>> linked(n + 1);
    vector<bool> cow(30009, 0);
    wh(k) {
        int a, b;
        cin >> a >> b;
        linked[a].pb(b);
        linked[b].pb(a);
    }
    wh(c) {
        int s;
        cin >> s;
        cow[s] = 1;
    }
    int temp = 0;
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    deque<int> d;
    d.pb(1);
    while (!d.empty()) {
        int cur = d.front(), alter = 0;
        bool check = 0;
        d.popf();
        for (auto i : linked[cur]) {
            if (!visited[i]) {
                if (cow[i] == 1) {
                    check = 1;
                    break;
                }
                visited[i] = true;
                ++alter;
                d.pb(i);
            }
        }
        if (check) {wh(alter) {visited[d.back()] = 0; d.popb();}}
        else {
            ++temp;
        }
    }
    ans = n - temp;
    cout << ans;
}

SORAI {
    Sanic_speed
    int t = 1;// cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
