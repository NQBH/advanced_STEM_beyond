#include <bits/stdc++.h>
using namespace std;

// Ham kiem tra mot phan hoach co phai la tu lien hop hay khong
bool is_self_conjugate(const vector<int> &partition) {
    if (partition.empty()) return false;
    int max_len = partition[0]; // vi partition da sap xep giam dan
    vector<int> conjugate;
    for (int i = 1; i <= max_len; i++) {
        int count = 0;
        for (int val : partition) {
            if (val >= i)
                count++;
            else
                break;
        }
        conjugate.push_back(count);
    }
    return conjugate == partition;
}

// Sinh cac phan hoach tu lien hop cua n, neu k != -1 thi chi lay cac phan co k phan tu
void backtrack_self_conjugate(int remaining, vector<int> &curr, int max_val,
                              int n, int k, vector<vector<int>> &result) {
    if (remaining == 0) {
        if ((k == -1 || (int)curr.size() == k)) {
            vector<int> sorted_part = curr;
            sort(sorted_part.rbegin(), sorted_part.rend());
            if (is_self_conjugate(sorted_part)) {
                result.push_back(sorted_part);
            }
        }
        return;
    }
    for (int i = min(remaining, max_val); i >= 1; --i) {
        curr.push_back(i);
        backtrack_self_conjugate(remaining - i, curr, i, n, k, result);
        curr.pop_back();
    }
}

vector<vector<int>> generate_self_conjugate_partitions(int n, int k = -1) {
    vector<vector<int>> result;
    vector<int> curr;
    backtrack_self_conjugate(n, curr, n, n, k, result);
    return result;
}

// Sinh cac phan hoach cua n chi bao gom so le
void backtrack_odd(int remaining, vector<int> &curr, int min_odd,
                   vector<vector<int>> &result) {
    if (remaining == 0) {
        result.push_back(curr);
        return;
    }
    for (int i = min_odd; i <= remaining; i += 2) {
        curr.push_back(i);
        backtrack_odd(remaining - i, curr, i, result);
        curr.pop_back();
    }
}

vector<vector<int>> generate_odd_partitions(int n) {
    vector<vector<int>> result;
    vector<int> curr;
    backtrack_odd(n, curr, 1, result);
    return result;
}

// (c.i) De quy co nho
int p_k_selfconj_recursive(int n, int k, map<pair<int, int>, int> &memo) {
    pair<int, int> key = {n, k};
    if (memo.count(key)) return memo[key];
    if (n == 0 && k == 0) return 1;
    if (n <= 0 || k <= 0) return 0;

    int count = 0;
    vector<int> curr;

    function<void(int, int, vector<int> &, int)> backtrack = [&](int remaining, int parts_left, vector<int> &curr, int max_val) {
        if (remaining == 0 && parts_left == 0) {
            vector<int> sorted_part = curr;
            sort(sorted_part.rbegin(), sorted_part.rend());
            if (is_self_conjugate(sorted_part))
                count++;
            return;
        }
        if (remaining <= 0 || parts_left <= 0) return;
        for (int i = min(remaining, max_val); i >= 1; --i) {
            curr.push_back(i);
            backtrack(remaining - i, parts_left - 1, curr, i);
            curr.pop_back();
        }
    };

    backtrack(n, k, curr, n);
    memo[key] = count;
    return count;
}

// (c.ii) Quy hoach dong: Kiem tra tu lien hop cho tung phan hoach sinh ra
int p_k_selfconj_dp(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for (int sum_val = 1; sum_val <= n; ++sum_val) {
        for (int parts = 1; parts <= min(k, sum_val); ++parts) {
            int count = 0;
            vector<int> curr;

            function<void(int, int, vector<int> &, int)> backtrack = [&](int remaining, int parts_left, vector<int> &curr, int max_val) {
                if (remaining == 0 && parts_left == 0) {
                    vector<int> sorted_part = curr;
                    sort(sorted_part.rbegin(), sorted_part.rend());
                    if (is_self_conjugate(sorted_part))
                        count++;
                    return;
                }
                if (remaining <= 0 || parts_left <= 0) return;
                for (int i = min(remaining, max_val); i >= 1; --i) {
                    curr.push_back(i);
                    backtrack(remaining - i, parts_left - 1, curr, i);
                    curr.pop_back();
                }
            };

            backtrack(sum_val, parts, curr, sum_val);
            dp[sum_val][parts] = count;
        }
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cout << "Nhap n (so can phan hoach): ";
    cin >> n;
    cout << "Nhap k (so phan cua tu lien hop): ";
    cin >> k;

    // (a) Dem va in cac phan hoach tu lien hop co k phan
    cout << "\n(a) Cac phan hoach tu lien hop cua " << n << " co " << k << " phan:\n";
    auto sc_parts = generate_self_conjugate_partitions(n, k);
    for (auto &p : sc_parts) {
        cout << "  ";
        for (int x : p) cout << x << " ";
        cout << "\n";
    }
    cout << "=> So phan hoach tu lien hop p_k^selfcjg(" << n << "," << k << ") = " << sc_parts.size() << "\n";

    // (b) So sanh voi phan hoach co cac so le
    auto odd_parts = generate_odd_partitions(n);
    cout << "\n(b) So phan hoach cua " << n << " co cac phan tu la so le:\n";
    for (auto &p : odd_parts) {
        cout << "  ";
        for (int x : p) cout << x << " ";
        cout << "\n";
    }
    cout << "=> Tong cong co " << odd_parts.size() << " phan hoach co so phan tu la so le\n";

    // (c.i) De quy
    map<pair<int, int>, int> memo;
    int res_recursive = p_k_selfconj_recursive(n, k, memo);
    cout << "\n(c.i) Tinh bang de quy: p_k^selfcjg(" << n << "," << k << ") = " << res_recursive << "\n";

    // (c.ii) Quy hoach dong
    int res_dp = p_k_selfconj_dp(n, k);
    cout << "(c.ii) Tinh bang quy hoach dong: p_k^selfcjg(" << n << "," << k << ") = " << res_dp << "\n";

    return 0;
}