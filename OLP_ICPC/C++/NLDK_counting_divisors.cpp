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

const int N = 1000005;
bool Primer[1000009];
int solution[1000002];

void Sorai_Era_sieve() {
    Primer[0] = Primer[1] = true;
    for (int i = 4; i <= N; i += 2) {
        Primer[i] = true;
    }
    for (ll i = 3; i <= N; i += 2) {
        if (!Primer[i]) {
            for (ll j = i*i; j <= N; j += i) {
                Primer[j] = true;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    int nt = n;
    if (solution[n] != -1) {
        cout << solution[n] << el
    } elif (n == 1) {
        cout << 1 << el
    } elif (!Primer[n]) {
        cout << 2 << el
        solution[n] = 2;
    } else {
        int ans = 1, temp = 1, step = 3;
        vector<int> s;
        while (n % 2 == 0) {
            ++temp;
            n /= 2;
        }
        s.pb(temp);
        while (n != 1) {
            if (!Primer[n]) {
                s.pb(2);
                break;
            } elif (n % step == 0) {
                temp = 1;
                while (n % step == 0) {
                    ++temp;
                    n /= step;
                }
                s.pb(temp);
            }
            step += 2;
            while (Primer[step] == true) {step += 2;}
        }
        frs(i, 0, s.size()) {ans *= s[i];}
        cout << ans << el
        solution[nt] = ans;
    }
}

SORAI {
    Sanic_speed
    fill_n(Primer, N, false);
    Sorai_Era_sieve();
    fill_n(solution, N, -1);
    int t; cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/

