#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    getline(cin, s);
    int cnt = 1, max_cnt = 1, n = s.size();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) cnt++;
        else cnt = 1;
        max_cnt = max(cnt, max_cnt);
    }
    cout << max_cnt;
}