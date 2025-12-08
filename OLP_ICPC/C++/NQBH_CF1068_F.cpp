#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 150005;
const int SQRT_K = 320; // Block size and threshold for x

int a[MAXN];
long long pref[MAXN];
struct Result {
    short cnt;
    short rem;
};
Result dp[MAXN][SQRT_K + 1];

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    // Input and Prefix Sums
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for (int x = 1; x <= SQRT_K; ++x) {
        for (int blk_start = 1; blk_start <= n; blk_start += SQRT_K) {
            int blk_end = min(n, blk_start + SQRT_K - 1);            
            long long current_sum = 0;
            int resets = 0;
            int r_ptr = blk_end;
            long long window_sum = 0;
            for (int i = blk_end; i >= blk_start; --i) {
                long long target = pref[i-1] + x;
                int j = lower_bound(pref + i, pref + blk_end + 1, target) - pref;                
                if (j > blk_end) dp[i][x] = {0, (short)(pref[blk_end] - pref[i-1])};
                else {
                    if (j == blk_end) dp[i][x] = {1, 0};
                    else {
                        Result res_next = dp[j+1][x];
                        dp[i][x] = {(short)(1 + res_next.cnt), res_next.rem};
                    }
                }
            }
        }
    }
    for (int k = 0; k < q; ++k) {
        int l, r;
        long long x;
        cin >> l >> r >> x;

        int total_cnt = 0;
        long long current_val = 0;

        if (x > SQRT_K) {
            int cur = l;
            while (cur <= r) {                
                long long target = x - current_val + pref[cur-1];
                int idx = lower_bound(pref + cur, pref + r + 1, target) - pref;                
                if (idx > r) {
                    current_val += (pref[r] - pref[cur-1]);
                    cur = r + 1;
                } else {
                    total_cnt++;
                    current_val = 0;
                    cur = idx + 1;
                }
            }
        } else {
            int cur = l;
            while (cur <= r) {
                int blk_id = (cur - 1) / SQRT_K;
                int blk_end = min(n, (blk_id + 1) * SQRT_K);
                int actual_end = min(r, blk_end);
                if (cur != blk_id * SQRT_K + 1 || r < blk_end) {
                     // Process single range [cur, actual_end]
                     long long target = x - current_val + pref[cur-1];
                     int idx = lower_bound(pref + cur, pref + actual_end + 1, target) - pref;
                     
                     if (idx > actual_end) {
                         current_val += (pref[actual_end] - pref[cur-1]);
                         cur = actual_end + 1;
                     } else {
                         total_cnt++;
                         current_val = 0;
                         cur = idx + 1;
                     }
                } else {
                    long long block_sum = pref[blk_end] - pref[cur-1];
                    if (current_val + block_sum < x) {
                        current_val += block_sum;
                        cur = blk_end + 1;
                    } else {
                        long long target = x - current_val + pref[cur-1];
                        int idx = lower_bound(pref + cur, pref + blk_end + 1, target) - pref;
                        total_cnt++;
                        current_val = 0;
                        if (idx < blk_end) {
                            Result res = dp[idx+1][x];
                            total_cnt += res.cnt;
                            current_val = res.rem;
                        }
                        cur = blk_end + 1;
                    }
                }
            }
        }
        cout << total_cnt << " " << current_val << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    while (t--) solve();
}
// TLE test 