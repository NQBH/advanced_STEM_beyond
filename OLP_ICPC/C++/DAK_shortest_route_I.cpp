#include <bits/stdc++.h>
#define int long long
using namespace std;
void IOfile()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    freopen("b.inp","r",stdin);
    freopen("b.out","w",stdout);
}
long long oo=1e18;
typedef pair<int, int> ii;
vector<ii> a[200200];
int n, m;
int d[100100];
void dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = oo;
    d[1] = 0;
    pq.push(ii(0, 1));
    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}
main() {
    //IOfile();
    int u, v, m, w;
    cin >>n >>m;
    while (m--) {
        cin >> u >> v >> w;
        a[u].push_back(ii(w, v));
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
}