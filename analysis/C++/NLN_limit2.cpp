#include <iostream> 
#include <cmath>    
#include <algorithm> 

int main() {
    std::cout << "Nhập giá trị M > 0: ";
    double M;
    std::cin >> M; 
    if (std::cin.fail()) {
        std::cerr << "Lỗi: Đầu vào không hợp lệ. Vui lòng nhập một số.\n"; 
        return 1; 
    }

    if (M <= 0) {
        std::cerr << "M phải lớn hơn 0.\n"; 
        return 1;
    }

    double m_squared_minus_2 = M * M - 2.0; 
    int N_candidate = static_cast<int>(std::ceil(m_squared_minus_2));
    int N = std::max(0, N_candidate);
    std::cout << "Giá trị N (số nguyên không âm nhỏ nhất sao cho sqrt(N+2) >= M) cho M = " << M << " là: " << N << "\n";

    return 0; 
}