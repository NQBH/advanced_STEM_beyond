#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int m, n, k;
vector<pair<int,int>> a;

void subtask1() {
    
}
void subtask2() {

}

signed main() {
    cin >> m >> n >> k;
    a.resize(k + 1);
    for (int t = 1; t <= k; t++) {
        cin >> a[t].first >> a[t].second;
    }    
    if (m <= 10 && n <= 10 && k == 0) return subtask1(), 0;
    if (m <= 1000 && n <= 1000) return subtask2(), 0;
    if (k == 0) return subtask3(), 0;
    if (k <= 5) return subtask4(), 0;
    return subtask5(), 0;
}