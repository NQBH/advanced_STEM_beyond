#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n, k;
  cin >> n >> k;
  ll a[k];
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 0; i < (1ll << k); i++) {
    vector<ll> v;
    for (int j = 0; j < k; j++) {
      if ((i & (1 << j)) != 0) {
        v.push_back(a[j]);
      }
    }
    ll prod = 1;
    for (int j = 0; j < v.size(); j++) {
      if (prod > n / v[j]) {
        prod = n + 1;
        break;
      }
      prod *= v[j];
    }
    if (v.size() % 2 == 0)
      ans -= n / prod;
    else
      ans += n / prod;
  }
  ans += n;
  cout << ans;
}