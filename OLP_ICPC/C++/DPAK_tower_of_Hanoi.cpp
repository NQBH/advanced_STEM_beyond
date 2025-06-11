#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;
void move(int numDisk, int start, int temp, int target) {
    if (numDisk == 1) {
        ans.push_back({start, target});
        return;
    }
    move(numDisk - 1, start, target, temp);
    move(1, start, temp, target);
    move(numDisk - 1, temp, start, target);
}

int main() {
    int n; cin >> n;
    move(n, 1, 2, 3);
    cout << ans.size() << endl;
    for (auto [s, t] : ans) {
        cout << s << " " << t << endl;
    }
}