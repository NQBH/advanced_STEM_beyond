#include <iostream>

using namespace std;

// Hàm kiểm tra số nguyên tố tối ưu O(sqrt(n))
bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Chỉ kiểm tra các số có dạng 6k - 1 và 6k + 1
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Tối ưu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        if (n < 2) {
            cout << "none\n";
        } else if (is_prime(n)) {
            cout << "prime\n";
        } else {
            cout << "composite\n";
        }
    }
    return 0;
}