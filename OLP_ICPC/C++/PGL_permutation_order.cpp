#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll factorial(ll n) {
    ll res = 1;
    for (ll i = 2; i <= n; ++i) res *= i;
    return res;
}

void Generate_P(ll n, ll k) {
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) a[i]=i+1;
    k--;
    vector<ll> result;
    for (ll i = n; i >= 1; --i) {
        ll fact=factorial(i-1);
        ll index=k/fact;
        result.push_back(a[index]);
        a.erase(a.begin()+index);
        k%=fact;
    }
    for (auto x : result) cout << x << " ";
    cout << endl;
}

ll Rank(vector<int>& perm,ll n) {
    vector<bool> visit(n + 1, false);
    ll rank = 0;
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 1; j < perm[i]; ++j) {
            if (!visit[j]) count++;
        }
        rank += count * factorial(n - 1 - i);
        visit[perm[i]] = true;
    }
    return rank + 1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int a, n; cin >> a >> n;
        if (a == 1) {
            ll k; cin>>k;
            Generate_P(n, k);
        }
        if (a==2){
            vector<int> perm(n);
            for (int i=0;i<n;++i) cin >> perm[i];
            cout<<Rank(perm,n)<< endl;
        }
    }
    return 0;
}