#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
string s;
vector<bool> visited;

set<string> ans;
void backTracking(string current) {
    if (current.size() == s.size()) {
        ans.insert(current);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (visited[i]) continue;

        visited[i] = true;
        current.push_back(s[i]);

        backTracking(current);

        current.pop_back();
        visited[i] = false;
    }
}
signed main() {

    cin >> s;
    visited.resize(s.size(), false);
    backTracking("");
    cout << ans.size() << endl;
    for (auto c : ans) {
        cout << c << endl;
    }
}