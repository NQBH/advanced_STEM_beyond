#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Tạo mảng các số nguyên tố cơ sở để dùng cho sàng phân đoạn
vector<long long> get_base_primes(long long limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<long long> primes;
    for (long long p = 2; p <= limit; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
            for (long long i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return primes;
}

int main() {
    // Tối ưu I/O tốc độ cao
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Tìm các số nguyên tố lên tới căn bậc 2 của 2*10^9
    long long max_val = 2000000000;
    long long limit = sqrt(max_val) + 1;
    vector<long long> base_primes = get_base_primes(limit);

    long long a, b;
    if (cin >> a >> b) {
        // 1. Tính số lượng các số <= 1 (không là nguyên tố, không là hợp số)
        // Các số <= 1 nằm trong đoạn [a, min(b, 1)]
        long long neither_count = 0;
        long long upper_neither = min(b, 1LL);
        if (a <= upper_neither) {
            neither_count = upper_neither - a + 1;
        }

        // 2. Nếu đoạn chỉ chứa các số <= 1 thì in kết quả và kết thúc
        if (b < 2) {
            cout << 0 << " " << 0 << " " << neither_count << "\n";
            return 0;
        }

        // 3. Sàng phân đoạn cho các số >= 2 trong khoảng [L, R]
        long long L = max(a, 2LL);
        long long R = b;
        long long range_size = R - L + 1;
        
        vector<bool> is_prime(range_size, true);

        for (long long p : base_primes) {
            // Tối ưu: Nếu bình phương của p vượt quá R thì dừng
            if (p * p > R) break;

            // Tìm bội số nhỏ nhất của p lớn hơn hoặc bằng L
            long long start = (L + p - 1) / p * p;
            
            // Tránh gạch bỏ chính số nguyên tố p
            if (start < p * p) {
                start = p * p;
            }

            // Gạch bỏ các bội số của p trong đoạn [L, R]
            for (long long j = start; j <= R; j += p) {
                is_prime[j - L] = false;
            }
        }

        // Đếm số lượng số nguyên tố
        long long prime_count = 0;
        for (long long i = 0; i < range_size; ++i) {
            if (is_prime[i]) {
                prime_count++;
            }
        }

        // Số hợp số = Tổng số phần tử trong đoạn [L, R] - Số nguyên tố
        long long composite_count = range_size - prime_count;

        cout << prime_count << " " << composite_count << " " << neither_count << "\n";
    }
    return 0;
}