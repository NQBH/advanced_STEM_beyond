#include <iostream>

using namespace std;

int main() {
    // Tối ưu hóa I/O tốc độ cao cho dữ liệu lớn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long b;
    if (cin >> n >> b) {
        if (b == 0) {
            cout << -1 << "\n";
            // Vẫn cần đọc nốt mảng a để tránh luồng input bị kẹt
            long long dummy;
            for (int i = 0; i < n; i++) cin >> dummy;
        } else {
            long long sum_val = 0;
            long long prod_val = 1 % b; // Khởi tạo an toàn cho trường hợp b = 1

            for (int i = 0; i < n; ++i) {
                long long x;
                cin >> x;
                
                // Chuẩn hóa x về số dư toán học (luôn >= 0)
                long long x_mod = (x % b + b) % b;
                
                // Cộng/nhân dồn và lấy dư ngay lập tức để tránh tràn số
                sum_val = (sum_val + x_mod) % b;
                prod_val = (prod_val * x_mod) % b;
            }
            
            cout << sum_val << " " << prod_val << "\n";
        }
    }
    return 0;
}