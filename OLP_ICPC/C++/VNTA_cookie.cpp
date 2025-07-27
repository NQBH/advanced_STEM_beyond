#include <bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<ll, ll> memo;
ll A;

ll dp(ll N) {
    if (N == 1) return 1; // chỉ nướng 1 bánh, 1 giây
    if (memo.count(N)) return memo[N];

    ll res = N; // không chia nữa, nướng N bánh từng cái một, không ăn

    for (ll x = 2; x * x <= N; ++x) {
        if (N % x == 0) {
            ll y = N / x;
            // chia thành 2 phần: nướng x cái, ăn mất A giây, sau đó dp y
            ll cost = x + A + dp(y);
            res = min(res, cost);

            // do không chắc x<=y nên cũng thử ngược lại
            cost = y + A + dp(x);
            res = min(res, cost);
        }
    }

    return memo[N] = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N >> A;
    cout << dp(N);

    return 0;
}