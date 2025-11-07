#include <bits/stdc++.h>
#include <unordered_map>
#ifndef ONLINE_JUDGE
#include "debug.h"
#endif 

#define int long long
#define yes cout << "yes\n"
#define no cout << "no\n"
#define endl '\n';
#define all(a) a.begin(), a.end()
using namespace std;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;

string vowels = "aeiou";
signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> ch(5, 0);
        while (n-- > 0) {
            int num = n;
            ch[num % 5]++;
        }
        for (int i = 0; i < 5; i++) {
            while (ch[i]--) {
                if (i == 0) {
                    cout << 'o';
                }
                else if (i == 1) {
                    cout << 'e';
                }
                else if (i == 2) {
                    cout << 'u';
                }
                else if (i == 3) {
                    cout << 'a';
                }
                else {
                    cout << 'i';
                }
            }
        }
        cout << endl;
     }
    return 0;
}