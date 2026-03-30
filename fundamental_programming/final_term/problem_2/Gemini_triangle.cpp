#include <iostream>

using namespace std;

int main() {
    // Tối ưu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    if (cin >> a >> b >> c) {
        // Kiểm tra điều kiện các cạnh dương và bất đẳng thức tam giác
        if (a > 0 && b > 0 && c > 0 && a < b + c && b < c + a && c < a + b) {
            long long p = a + b + c;
            cout << p << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}