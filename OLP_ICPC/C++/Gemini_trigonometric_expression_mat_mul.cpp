#include <iostream>
#include <vector>

using namespace std;

// Cấu trúc Ma trận 2x2
struct Matrix {
    long long mat[2][2];
    
    Matrix() {
        mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
    }
};

// Hàm nhân ma trận modulo m
Matrix multiply(Matrix A, Matrix B, long long m) {
    Matrix C;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                // Lưu ý: A.mat[i][k] * B.mat[k][j] có thể lên tới 10^16, nằm trong long long
                // Xử lý số âm cẩn thận bằng cách cộng thêm m trước khi chia dư
                long long val = (A.mat[i][k] * B.mat[k][j]) % m;
                C.mat[i][j] = (C.mat[i][j] + val + m) % m;
            }
        }
    }
    return C;
}

// Hàm lũy thừa ma trận: A^p modulo m
Matrix power(Matrix A, long long p, long long m) {
    Matrix res;
    res.mat[0][0] = 1; res.mat[1][1] = 1; // Ma trận đơn vị
    A.mat[0][1] %= m; // Đảm bảo số âm ban đầu (nếu có) được xử lý
    
    while (p > 0) {
        if (p & 1) res = multiply(res, A, m);
        A = multiply(A, A, m);
        p >>= 1;
    }
    return res;
}

void solve() {
    long long n, m;
    cin >> n >> m;

    // Trường hợp cơ bản
    if (n == 0) { // Mặc dù đề bài n >= 1, nhưng xét cho đầy đủ
        cout << 2 % m << "\n";
        return;
    }
    if (n == 1) {
        cout << 4 % m << "\n";
        return;
    }

    // Thiết lập ma trận chuyển đổi T = {{4, -1}, {1, 0}}
    Matrix T;
    T.mat[0][0] = 4; 
    T.mat[0][1] = -1; // Sẽ được xử lý modulo trong hàm nhân
    T.mat[1][0] = 1; 
    T.mat[1][1] = 0;

    // Tính T^(n-1)
    T = power(T, n - 1, m);

    // S_n = T[0][0]*S_1 + T[0][1]*S_0
    // S_1 = 4, S_0 = 2
    long long s1 = 4;
    long long s0 = 2;

    long long term1 = (T.mat[0][0] * s1) % m;
    long long term2 = (T.mat[0][1] * s0) % m;
    
    long long ans = (term1 + term2) % m;
    ans = (ans + m) % m; // Đảm bảo kết quả dương

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}