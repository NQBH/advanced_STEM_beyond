#include <iostream>

using namespace std;

const long long MOD = 1000000007;

int main() {
    // Tối ưu I/O tốc độ cao
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long alpha, beta, a, b, c, n;
    if (cin >> alpha >> beta >> a >> b >> c >> n) {
        if (n < 0) {
            cout << -1 << "\n";
        } else {
            // Chuẩn hóa tất cả các tham số về số dư dương theo MOD
            long long a0 = (alpha % MOD + MOD) % MOD;
            long long a1 = (beta % MOD + MOD) % MOD;
            long long a_mod = (a % MOD + MOD) % MOD;
            long long b_mod = (b % MOD + MOD) % MOD;
            long long c_mod = (c % MOD + MOD) % MOD;

            if (n == 0) {
                cout << a0 << "\n";
            } else if (n == 1) {
                cout << a1 << "\n";
            } else {
                long long prev2 = a0;
                long long prev1 = a1;
                long long curr = 0;
                
                // Vòng lặp O(n) tính dãy truy hồi
                for (int i = 2; i <= n; ++i) {
                    curr = (a_mod * prev1) % MOD;
                    curr = (curr + b_mod * prev2) % MOD;
                    curr = (curr + c_mod) % MOD;
                    
                    prev2 = prev1;
                    prev1 = curr;
                }

                cout << curr << "\n";
            }
        }
    }
    return 0;
}