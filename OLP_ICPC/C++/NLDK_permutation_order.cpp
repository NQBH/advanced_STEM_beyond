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

const int M = 1e9 + 7;
const int N = 20;
ll Facting[21];

void GenFact() {
    Facting[0] = 1;
    Facting[1] = 1;
    Facting[2] = 2;
    fre(i, 3, N) {Facting[i] = (1LL * Facting[i - 1] * i);}
}

void Permu_order(int n, ll order) {
    ll one_order = Facting[n - 1];
    int step = n;
    vector<int> ans;
    deque<int> wait(n);
    frs(i, 0, n) {wait[i] = i + 1;}

    while (true) {
        if (n == 1) {ans.pb(1); break;}
        if (n == 2) {
            if (order == 1) {
                ans.pb(wait[0]);
                ans.pb(wait[1]);
            } else {
                ans.pb(wait[1]);
                ans.pb(wait[0]);
            }
            break;
        }
        if (order <= one_order) {
            ans.pb(wait[0]);
            wait.pop_front();
            n -= 1;
            if (n == 0) {break;}
            one_order = Facting[n - 1];
        } else {
            int temp = 0;
            ll alt = one_order;
            while (order > alt) {
                ++temp;
                alt += one_order;
            }
            ans.pb(wait[temp]);
            wait.erase(wait.begin() + temp);
            order -= (alt - one_order);
            n -= 1;
            if (n == 0) {break;}
            one_order = Facting[n - 1];
        }
    }
    frs(i, 0, step) {
        cout << ans[i] << " ";
    }
    cel
}

void Getting_order(int n, int a[]) {
    ll step = n, st = 0;
    ll ans = 0;
    while (step > 1) {
        ll counter = 0;
        frs(i, st + 1, n) {
            if (a[st] > a[i]) {++counter;}
        }
        ans += counter * (Facting[step - 1]);
        --step;
        ++st;
    }
    cout << (ans + 1) << el
}

void solve() {
    int n, p; cin >> p >> n;
    if (p == 1) {
        ll order;
        cin >> order;
        Permu_order(n, order);
    } else {
        int a[n];
        frs(i, 0, n) {cin >> a[i];}
        Getting_order(n, a);
    }
}

SORAI {
    Sanic_speed
    GenFact();
    int t; cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
