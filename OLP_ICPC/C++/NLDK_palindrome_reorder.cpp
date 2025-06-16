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

void solve() {
    string s, example = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> s;
    int sizer = s.size(), check = 0, odd, val;
    int a[26];
    fill_n(a, 26, 0);
    vector<int> posi;
    vector<int> value;
    deque<char> ans;
    frs(i, 0, sizer) {++a[s[i] - 'A'];}
    frs(i, 0, 26) {
        if (a[i] != 0) {
            if (a[i] % 2 == 1) {
                odd = i;
                val = a[i];
                ++check;
                if (check >= 2) {break;}
            } else {
                posi.pb(i);
                value.pb(a[i]);
            }
        }
    }
    if (check == 0) {
        frs(i, 0, posi.size()) {
            while (value[i] != 0) {
                ans.pb(example[posi[i]]);
                ans.push_front(example[posi[i]]);
                value[i] -= 2;
            }
        }
        frs(i, 0, ans.size()) {cout << ans[i];}
    } elif (check == 1) {
        if (val % 2 == 1) {--val; ans.pb(example[odd]);}
        while (val != 0) {
            ans.pb(example[odd]);
            ans.push_front(example[odd]);
            val -= 2;
        }
        frs(i, 0, posi.size()) {
            while (value[i] != 0) {
                ans.pb(example[posi[i]]);
                ans.push_front(example[posi[i]]);
                value[i] -= 2;
            }
        }
        frs(i, 0, ans.size()) {cout << ans[i];}
    } else {
        cout << "NO SOLUTION";
    }
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
