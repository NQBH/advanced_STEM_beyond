#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Thiết lập hiển thị số thực 2 chữ số sau dấu phẩy
    cout << fixed << setprecision(2);
    
    cout << "--- KIEM TRA TOAN BO CAC HAM TRONG BANG 2.15 ---" << endl << endl;

    // 1. Nhom Luy thua & Can (sqrt, pow, exp)
    cout << "1. Luy thua & Can:" << endl;
    cout << "   - sqrt(25.0) = " << sqrt(25.0) << endl;
    cout << "   - pow(2.0, 3.0) = " << pow(2.0, 3.0) << endl;
    cout << "   - exp(1.0) = " << exp(1.0) << " (so e)" << endl;

    // 2. Nhom Logarit (log, log10)
    cout << "2. Logarit:" << endl;
    cout << "   - log(2.718) = " << log(2.71828) << " (logarit co so e)" << endl;
    cout << "   - log10(100.0) = " << log10(100.0) << " (logarit co so 10)" << endl;

    // 3. Nhom Tri tuyet doi (abs, labs, fabs)
    cout << "3. Tri tuyet doi:" << endl;
    cout << "   - abs(-5) = " << abs(-5) << " (cho kieu int)" << endl;
    long so_long = -123456789;
    cout << "   - labs(" << so_long << ") = " << labs(so_long) << " (cho kieu long)" << endl;
    cout << "   - fabs(-7.89) = " << fabs(-7.89) << " (cho kieu double)" << endl;

    // 4. Nhom Luong giac (cos, sin, tan) - Don vi Radian
    cout << "4. Luong giac:" << endl;
    double rad = 0.5236; // Tuong duong 30 do
    cout << "   - sin(0.5236) = " << sin(rad) << endl;
    cout << "   - cos(0.5236) = " << cos(rad) << endl;
    cout << "   - tan(0.5236) = " << tan(rad) << endl;

    // 5. Nhom Luong giac nguoc (acos, asin, atan)
    cout << "5. Luong giac nguoc:" << endl;
    cout << "   - asin(0.5) = " << asin(0.5) << " rad" << endl;
    cout << "   - acos(0.5) = " << acos(0.5) << " rad" << endl;
    cout << "   - atan(1.0) = " << atan(1.0) << " rad" << endl;

    // 6. Nhom Lam tron (floor, ceil)
    cout << "6. Lam tron:" << endl;
    cout << "   - floor(3.9) = " << floor(3.9) << " (lay so nguyen nho hon)" << endl;
    cout << "   - ceil(3.1) = " << ceil(3.1) << " (lay so nguyen lon hon)" << endl;

    return 0;
}