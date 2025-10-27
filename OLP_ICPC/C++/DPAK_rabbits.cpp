#include <bits/stdc++.h>
#define APC signed
#define int long long
using namespace std;

const int oo = 1e9;

void mergeVector(vector<int>&a, vector<int> &b) {

    for (auto & i : b) a.push_back(i);
}
APC main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        n = s.size();
        s = " " + s;
        vector<vector<int>> posGroups; 
        for (int i = 1; i <= n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j <= n && s[j] == '0') j++; // block [i..j-1]
                int L = i, R = j - 1;
                vector<int> g;
                for (int p = L; p <= R; p++) g.push_back(p);
                posGroups.push_back(g);
                i = j;
            } 
            else {
                i++;
            }
        }
    
        vector<char> isBlockZero(n + 1, 0);
        for (auto &g : posGroups) {
            if (g.size() >= 2) {
                for (int p : g) isBlockZero[p] = 1;
            }
        }

        vector<vector<int>> groups;
        for (auto &g : posGroups) {
            if (g.size() == 1) {
                int x = g[0];
                if (!groups.empty() && groups.back().back() + 2 == x) {
                    groups.back().push_back(x);
                } else {
                    groups.push_back(vector<int>{x});
                }
            }
        }

        bool game = true;
        for (auto &p : groups) {
            int L = p.front();
            int R = p.back();
            bool capLeft  = (L == 1) || (L - 2 >= 1 && isBlockZero[L - 2]);
            bool capRight = (R == n) || (R + 2 <= n && isBlockZero[R + 2]);

            if (!capLeft && !capRight && (p.size() % 2 == 1)) {
                game = false; break;
            }
        }
        /*
        1010101
        10101001
        */


        cout << (game ? "YES" : "NO") << endl;
    }
}
