#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define ull unsigned ll
#define endl '\n'
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
bool check[1000001];
vector <string> ans;

void solve() {
    string s;
    cin >> s;

    int c[26] = { 0 };
    for (char ch : s) {
        c[ch - 'A']++;
    }

    bool hasOdd = false;
    string tmp = s;
    for (int i = 0; i < 26; ++i) {
        if (c[i] % 2 == 1) {
            if (hasOdd) {
                cout << "NO SOLUTION\n";
                return;
            }
            tmp[tmp.size() / 2] = 'A' + i;
            c[i]--;
            hasOdd = true;
        }
    }
    int j = 0;
    for (int i = 0; i < 26; ++i) {
        while (c[i] > 0) {
            tmp[j] = tmp[tmp.size() - j - 1] = 'A' + i;
            c[i] -= 2;
            j++;
        }
    }

    cout << tmp << endl;
}



int main() {
    fastIO;
    //freopen("input.inp", "r", stdin);
    int numTest = 1; //cin >> numTest;

    for (int testCase = 1; testCase <= numTest; testCase++) {
        solve();
    }

    return 0;
}