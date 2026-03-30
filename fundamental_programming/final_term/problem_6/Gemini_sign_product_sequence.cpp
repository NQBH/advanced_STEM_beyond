#include <iostream>

using namespace std;

int main() {
    // Tối ưu I/O tốc độ cao
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        int neg_count = 0;
        bool has_zero = false;

        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            
            if (a == 0) {
                has_zero = true;
            } else if (a < 0) {
                neg_count++;
            }
        }

        // Chốt kết quả dựa trên logic đếm
        if (has_zero) {
            cout << 0 << "\n";
        } else if (neg_count % 2 != 0) {
            cout << -1 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
    return 0;
}