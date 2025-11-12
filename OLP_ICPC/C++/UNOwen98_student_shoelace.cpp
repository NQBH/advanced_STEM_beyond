#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define trace(x) cerr<<x<<END;
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i)
const int mod = 1e9 + 7;
const int mod1 = 998244353;
const int inf = 9223372036854775807ll;
const int mxn = 101;
int n, m;
vector<int> adj[mxn];
int degree[mxn];
void solve()
{
    cin >> n >> m;
    loop(i, 1, n + 1)
    degree[i] = 0;
    loop(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        degree[u]++;
        degree[v]++;
    }
    int ans = 0;
    queue<pii> q;
    loop(i, 1, n + 1)
    if (degree[i] == 1)
        q.push({i, 1});
    while (!q.empty())
    {
        int node = q.front().ff;
        int batch = q.front().ss;
        q.pop();
        if (degree[node] == 0)
            continue;
        ans = max(ans, batch);
        for (auto x : adj[node])
        {
            degree[x]--;
            if (degree[x] == 1)
                q.push({x, batch + 1});
        }
        degree[node]--;
    }
    cout << ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    /*int t;
    cin>>t;
    while(t--)*/
    solve();
    //cerr<<END<<1.0*clock();
    return 0;
}