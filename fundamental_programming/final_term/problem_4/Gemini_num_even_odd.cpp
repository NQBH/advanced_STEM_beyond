#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // Tối ưu I/O tốc độ cao
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (cin >> a >> b) {
        // Đề phòng input bẫy a > b
        if (a > b) {
            swap(a, b);
        }

        // Tính tổng số lượng phần tử trong đoạn
        // Bắt buộc dùng long long vì b - a + 1 có thể lên tới 4*10^9
        long long n = b - a + 1;
        
        // Mặc định số chẵn và lẻ sẽ bằng một nửa tổng số phần tử
        long long evens = n / 2;
        long long odds = n / 2;
        
        // Nếu tổng số phần tử là lẻ, sẽ có 1 số bị dư ra
        // Tính chẵn/lẻ của số dư này phụ thuộc vào số bắt đầu (a)
        if (n % 2 != 0) {
            if (abs(a % 2) == 1) {
                odds++;
            } else {
                evens++;
            }
        }
        
        cout << evens << " " << odds << "\n";
    }
    return 0;
}