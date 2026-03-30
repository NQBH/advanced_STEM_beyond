#include <iostream>

using namespace std;

const long long MOD = 1000000007;

int main() {
    // Tối ưu I/O tốc độ cao
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long alpha, a, b, n;
    if (cin >> alpha >> a >> b >> n) {
        if (n < 0) {
            cout << -1 << "\n";
        } else {
            // Chuẩn hóa tất cả các tham số về số dư dương theo MOD
            long long current = (alpha % MOD + MOD) % MOD;
            long long a_mod = (a % MOD + MOD) % MOD;
            long long b_mod = (b % MOD + MOD) % MOD;

            // Vòng lặp O(n) tính dãy truy hồi
            for (int i = 0; i < n; ++i) {
                current = (a_mod * current + b_mod) % MOD;
            }

            cout << current << "\n";
        }
    }
    return 0;
}