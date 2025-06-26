/*
    VTP - Tính p_k(n) và p(n) bruce-force
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX_SIZE = 1e4 + 5;

vector<int> current_pk;
int count_pk, n_calls;

void generate(int remain_n, int remain_k, int max_value) {
    ++n_calls;

    if (remain_k == 0 && remain_n == 0) ++count_pk;

    if (remain_k == 0 || remain_n <= 0) return;

    for (int i = min(max_value, remain_n); i >= 1; --i) {
        if (remain_n < remain_k - 1) continue;
        current_pk.push_back(i);
        generate(remain_n - i, remain_k - 1, i);
        current_pk.pop_back();
    }
}

int solve_pk(int n, int k) {
    count_pk = 0;
    n_calls = 0;
    current_pk.clear();

    if (k < 0) return 0;
    if (n < k) {
        cout << 0 << " ";
        return 0;
    }
    generate(n, k, n - (k - 1));
    cout << count_pk << " ";
    return count_pk;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int n; cin >> n;
    vector<int> p(n + 1, 0);

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            // solve_pk(i, j);
            p[i] += solve_pk(i, j);
        }
        cout << '\n';
    }
    for (int i = 0; i <= n; ++i) cout << p[i] << " ";

    return 0;
}