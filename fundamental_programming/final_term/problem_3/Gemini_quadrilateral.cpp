#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Tối ưu hóa I/O trong C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c, d;
    if (cin >> a >> b >> c >> d) {
        // Kiểm tra điều kiện độ dài cạnh phải là số dương
        if (a > 0 && b > 0 && c > 0 && d > 0) {
            // Sử dụng long long để tránh tràn số khi tính tổng và nhân đôi
            long long max_edge = max({a, b, c, d});
            long long sum = a + b + c + d;
            
            // Áp dụng công thức 2 * max < tổng 4 cạnh
            if (2 * max_edge < sum) {
                cout << sum << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}