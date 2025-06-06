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

vector<ll> sum1;
vector<ll> sum2;
ll k;
ll ans = 0;

void Backing1(int n, ll a[], int posi, ll sum) {
    if (posi == n) {ret}
    ll temp = sum + a[posi];
    sum1.pb(temp);
    frs(i, posi + 1, n) {
        Backing1(n, a, i, temp);
    }
}

void Backing2(int n, ll b[], int posi, ll sum) {
    if (posi == n) {ret}
    ll temp = sum + b[posi];
    sum2.pb(temp);
    frs(i, posi + 1, n) {
        Backing2(n, b, i, temp);
    }
}

void solve() {
    int n, s;
    cin >> n >> k;
    ll a[n / 2];
    if (n & 1) {s = n / 2 + 1;} else {s = n / 2;}
    ll b[s];
    frs(i, 0, n / 2) {cin >> a[i];}
    frs(i, 0, s) {cin >> b[i];}
    frs(i, 0, (n / 2 - 1)) {
        Backing1(n / 2, a, i, 0);
    }
    sum1.pb(a[n / 2 - 1]);
    frs(i, 0, (s - 1)) {
        Backing2(s, b, i, 0);
    }
    sum2.pb(b[s - 1]);
    sort(all(sum1), greater<ll>());
    sort(all(sum2));
    int temp = 0;
    /*
    frs(i, 0, sum1.size()) {
        if (sum1[i] > k) {break;}
        if (sum1[i] == k) {ans += 1;}
        elif (sum1[i] == sum1[i-1]) {
            ans += temp;
        } else {
            temp = 0;
            int need = k - sum1[i];
            frs(j, 0, sum2.size()) {
                if (sum2[j] == need) {++temp;}
                elif (sum2[j] > need) {break;}
            }
            ans += temp;
        }
    }
    */
    int s1 = 0, s2 = 0;
    for (s1; s1 < sum1.size(); ++s1) {
        if (sum1[s1] == k) {++ans;}
        elif (sum1[s1] < k) {break;}
    }
    for (s1; s1 < sum1.size(); ++s1) {
        if (s1 > 0) {
            if (sum1[s1] == sum1[s1 - 1]) {
                ans += temp;
                continue;
            }
        }
        temp = 0;
        for (s2; s2 < sum2.size(); ++s2) {
            if (sum1[s1] + sum2[s2] == k) {++temp;}
            elif (sum1[s1] + sum2[s2] > k) {break;}
        }
        ans += temp;
        if (s2 >= sum2.size()) {break;}
    }
    for (s2; s2 < sum2.size(); ++s2) {
        if (sum2[s2] == k) {++ans;}
        if (sum2[s2] > k) {break;}
    }
    cout << ans << el
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
