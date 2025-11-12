#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    vector<ll> d;
    cin >> n;
    bool visited[n + 1] = {false};
    vector<vector<ll>> a(n + 1);
    ll de[n + 1] = {0};
    ll t;
    for (ll i = 1; i <= n; i++)
    {
        cin >> t;
        if (t != -1)
        {
            a[t].push_back(i);
        }
        else d.push_back(i);
    }
    for (ll i = 0; i < d.size(); i++)
    {
        queue<ll> q;
        q.push(d[i]);
        visited[d[i]] = true;
        while (!q.empty())
        {
            ll s = q.front();
            q.pop();
            for (ll i : a[s])
            {
                if (!visited[i])
                {
                    de[i] = de[s] + 1;
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    ll ans = 0;
    for (ll i : de)
    {
        ans = max(ans, i);
    }
    cout << ans + 1;
}
