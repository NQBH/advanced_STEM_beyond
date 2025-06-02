#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t;

bool check(ll n) {
  if (n < 2)
    return false;
  if (n == 2 || n == 3 || n == 5)
    return true;
  if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
    return false;
  for (ll i = 7; i <= sqrt(n); i += 6) {
    if (n % i == 0 || n % (i + 4) == 0)
      return false;
  }
  return true;
}

int main() {
  cin >> t;
  while (t--) {
    ll x;
    cin >> x;
    x++;
    for (;; ++x) {
      if (check(x)) {
        cout << x << endl;
        break;
      }
    }
  }
  return 0;
}