#include <iostream>
using namespace std;

int main() {
    // Tối ưu I/O trong C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (cin >> a >> b) {
        if (b == 0) {
            cout << -1 << "\n";
        } else {
            // Tính số dư r
            long long r = a % b;
            
            // Nếu r âm, cộng thêm b để r thỏa mãn 0 <= r <= b - 1
            if (r < 0) {
                r += b;
            }
            
            // Tính thương q
            long long q = (a - r) / b;
            
            cout << q << " " << r << "\n";
        }
    }
    return 0;
}