#include <bits/stdc++.h>
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

SORAI{
    Sanic_speed
    int n, ans = 0; cin >> n;
    cin.ignore();
    vector<string> team(n);
    vector<int> solved(n);
    vector<int> penalty(n, 0);
    frs(i, 0, n) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        ss >> team[i];
        vector<int> a;
        int b;
        while (ss >> b)
            a.pb(b);
        for (int j = 0; j < a.size(); j += 2)
            if (a[j + 1] != 0) {
                ++solved[i];
                penalty[i] += a[j + 1];
                if (a[j] != 1) penalty[i] += (a[j] - 1) * 20;
            }
    }
    frs(i, 1, n) {
        if (solved[i] > solved[ans]) ans = i;
        elif(solved[i] == solved[ans])
            if (penalty[i] < penalty[ans]) ans = i;
    }
    cout << team[ans] << " " << solved[ans] << " " << penalty[ans];
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
