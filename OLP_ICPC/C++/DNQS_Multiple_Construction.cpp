#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n % 2 != 0) {
            cout << "NO\n"; // Không thể chia đều nếu n lẻ
            continue;
        }

        cout << "YES\n";
        // In n số chẵn đầu tiên
        for (int i = 1; i <= n; ++i) {
            cout << i * 2 << " ";
        }
        // In n-1 số lẻ đầu tiên
        for (int i = 1; i < n; ++i) {
            cout << i * 2 - 1 << " ";
        }
        // Số cuối cùng để cân bằng tổng
        cout << n * 2 - 1 + n << "\n";
    }
    return 0;
}
