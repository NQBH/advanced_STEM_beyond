#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*ll t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i =0; i<n; i++)
        {
            cin >> a[i];
        }
        if (k == 1) cout << 0 << '\n';
        else
        {
            sort(a.begin(),a.end());
            bool visited[n] = {false};
            ll kq = 0;
            for (ll i = 0; i<n; ++i)
            {
                ll j = n-1;
                if (visited[i] or i==j) continue;
                if (a[i]+a[j]==k and visited[j]==false)
                {
                    kq++;
                    visited[j] = true;
                    visited[i] = true;
                }
                else
                {
                    while (j>i)
                    {
                        if (a[i]+a[j]<=k and !visited[j]) break;
                        j--;
                    }
                    if (i==j) continue;
                    if (a[i]+a[j]==k)
                    {
                        kq++;
                        visited[j] = true;
                        visited[i] = true;
                    }
                    else j = n-1;
                }
            }
            cout << kq << "\n";
        }
    }
    }
    */
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (k == 1) cout << 0 << '\n';
        else
        {
            ll i = 0, j = n - 1;
            ll kq = 0;
            sort(a.begin(), a.end());
            while (i < j)
            {
                ll sum = a[i] + a[j];
                if (sum == k)
                {
                    kq++;
                    i++;
                    j--;
                }
                else if (sum > k)
                {
                    j--;
                }
                else i++;

            }
            cout << kq << "\n";
        }
    }
}
