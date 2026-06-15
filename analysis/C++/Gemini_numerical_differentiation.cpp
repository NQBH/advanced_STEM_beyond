#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// ==============================================================================
// 1. KHAI BÁO CON TRỎ HÀM (Theo đúng yêu cầu bắt buộc của đề bài)
// Định nghĩa kiểu FuncPtr đại diện cho một hàm nhận 1 tham số double và trả về 1 double
// ==============================================================================
typedef double (*FuncPtr)(double);


// ==============================================================================
// 2. CÁC CÔNG THỨC XẤP XỈ ĐẠO HÀM (Vế phải chỉ chứa f(x), đã bỏ sai số O(h^n))
// Lấy từ: Wikipedia - Finite difference coefficients
// ==============================================================================

// --- ĐẠO HÀM BẬC 1 ---

// 1. Sai phân tiến 2 điểm (Forward difference) - Sai số O(h)
double diff1_forward_1(FuncPtr f, double x, double h) {
    return (f(x + h) - f(x)) / h;
}

// 2. Sai phân lùi 2 điểm (Backward difference) - Sai số O(h)
double diff1_backward_1(FuncPtr f, double x, double h) {
    return (f(x) - f(x - h)) / h;
}

// 3. Sai phân trung tâm 2 điểm (Central difference) - Sai số O(h^2)
double diff1_central_2(FuncPtr f, double x, double h) {
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

// 4. Sai phân tiến 3 điểm (Forward difference 3-point) - Sai số O(h^2)
double diff1_forward_2(FuncPtr f, double x, double h) {
    return (-3.0 * f(x) + 4.0 * f(x + h) - f(x + 2.0 * h)) / (2.0 * h);
}

// 5. Sai phân lùi 3 điểm (Backward difference 3-point) - Sai số O(h^2)
double diff1_backward_2(FuncPtr f, double x, double h) {
    return (3.0 * f(x) - 4.0 * f(x - h) + f(x - 2.0 * h)) / (2.0 * h);
}

// 6. Sai phân trung tâm 5 điểm (Central difference 5-point) - Sai số O(h^4)
double diff1_central_4(FuncPtr f, double x, double h) {
    return (f(x - 2.0 * h) - 8.0 * f(x - h) + 8.0 * f(x + h) - f(x + 2.0 * h)) / (12.0 * h);
}

// --- ĐẠO HÀM BẬC 2 ---

// 7. Sai phân trung tâm đạo hàm bậc 2 - Sai số O(h^2)
double diff2_central_2(FuncPtr f, double x, double h) {
    return (f(x + h) - 2.0 * f(x) + f(x - h)) / (h * h);
}

// 8. Sai phân tiến đạo hàm bậc 2 - Sai số O(h)
double diff2_forward_1(FuncPtr f, double x, double h) {
    return (f(x + 2.0 * h) - 2.0 * f(x + h) + f(x)) / (h * h);
}

// 9. Sai phân lùi đạo hàm bậc 2 - Sai số O(h)
double diff2_backward_1(FuncPtr f, double x, double h) {
    return (f(x) - 2.0 * f(x - h) + f(x - 2.0 * h)) / (h * h);
}

// 10. Sai phân trung tâm 5 điểm đạo hàm bậc 2 - Sai số O(h^4)
double diff2_central_4(FuncPtr f, double x, double h) {
    return (-f(x - 2.0 * h) + 16.0 * f(x - h) - 30.0 * f(x) + 16.0 * f(x + h) - f(x + 2.0 * h)) / (12.0 * h * h);
}


// ==============================================================================
// 3. HÀM TEST VÀ CHƯƠNG TRÌNH CHÍNH
// ==============================================================================

// Ví dụ chọn hàm: f(x) = e^x * sin(x)
double my_func(double x) {
    return exp(x) * sin(x);
}

// Đạo hàm giải tích bậc 1 (để so sánh tính sai số thực tế): f'(x) = e^x(sin(x) + cos(x))
double exact_diff1(double x) {
    return exp(x) * (sin(x) + cos(x));
}

// Đạo hàm giải tích bậc 2: f''(x) = 2e^x * cos(x)
double exact_diff2(double x) {
    return 2.0 * exp(x) * cos(x);
}

int main() {
    double x, h;
    
    cout << "===== BT15: NUMERICAL DIFFERENTIATION =====" << endl;
    cout << "Ham dang test: f(x) = e^x * sin(x)" << endl;
    
    cout << "Nhap gia tri x: ";
    if (!(cin >> x)) return 1;
    
    cout << "Nhap buoc nhay h (vi du: 0.01): ";
    if (!(cin >> h)) return 1;
    
    if (h == 0) {
        cout << "Loi: Buoc nhay h phai khac 0!" << endl;
        return 1;
    }

    cout << fixed << setprecision(6);
    double exact1 = exact_diff1(x);
    double exact2 = exact_diff2(x);
    
    cout << "\n---------------- DAO HAM BAC 1 ----------------\n";
    cout << ">> Gia tri CHINH XAC (Exact) : " << exact1 << endl;
    // Chú ý cách gọi: Truyền thẳng tên hàm my_func vào, C++ sẽ tự động ép kiểu thành con trỏ hàm
    cout << "1. Forward O(h)              : " << diff1_forward_1(my_func, x, h) << " (Sai so: " << abs(diff1_forward_1(my_func, x, h) - exact1) << ")\n";
    cout << "2. Backward O(h)             : " << diff1_backward_1(my_func, x, h) << " (Sai so: " << abs(diff1_backward_1(my_func, x, h) - exact1) << ")\n";
    cout << "3. Central O(h^2)            : " << diff1_central_2(my_func, x, h) << " (Sai so: " << abs(diff1_central_2(my_func, x, h) - exact1) << ")\n";
    cout << "4. Forward 3-point O(h^2)    : " << diff1_forward_2(my_func, x, h) << " (Sai so: " << abs(diff1_forward_2(my_func, x, h) - exact1) << ")\n";
    cout << "5. Backward 3-point O(h^2)   : " << diff1_backward_2(my_func, x, h) << " (Sai so: " << abs(diff1_backward_2(my_func, x, h) - exact1) << ")\n";
    cout << "6. Central 5-point O(h^4)    : " << diff1_central_4(my_func, x, h) << " (Sai so: " << abs(diff1_central_4(my_func, x, h) - exact1) << ")\n";

    cout << "\n---------------- DAO HAM BAC 2 ----------------\n";
    cout << ">> Gia tri CHINH XAC (Exact) : " << exact2 << endl;
    cout << "7. Central O(h^2)            : " << diff2_central_2(my_func, x, h) << " (Sai so: " << abs(diff2_central_2(my_func, x, h) - exact2) << ")\n";
    cout << "8. Forward O(h)              : " << diff2_forward_1(my_func, x, h) << " (Sai so: " << abs(diff2_forward_1(my_func, x, h) - exact2) << ")\n";
    cout << "9. Backward O(h)             : " << diff2_backward_1(my_func, x, h) << " (Sai so: " << abs(diff2_backward_1(my_func, x, h) - exact2) << ")\n";
    cout << "10. Central 5-point O(h^4)   : " << diff2_central_4(my_func, x, h) << " (Sai so: " << abs(diff2_central_4(my_func, x, h) - exact2) << ")\n";
    cout << "-----------------------------------------------\n";

    return 0;
}