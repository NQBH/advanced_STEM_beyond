#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> 
using namespace std;
double tinhDinhThuc2x2(double a, double b, double c, double d) {
    return (a * d) - (b * c);
}
int main() {
    double a, b, c, d;
    
    cout << "--- Tinh dinh thuc ma tran THUC 2x2 ---" << endl;
    cout << "Nhap ma tran A co dang (a b; c d)" << endl;

    cout << "Nhap a (hang 1, cot 1): ";
    if (!(cin >> a)) {
        cerr << "Loi: vui long nhap lai." << endl;
        return 1;
    }
    cout << "Nhap b (hang 1, cot 2): ";
    if (!(cin >> b)) {
        cerr << "Loi: vui long nhap lai." << endl;
        return 1;
    }
    cout << "Nhap c (hang 2, cot 1): ";
    if (!(cin >> c)) {
        cerr << "Loi: vui long nhap lai." << endl;
        return 1;
    }
    cout << "Nhap d (hang 2, cot 2): ";
    if (!(cin >> d)) {
        cerr << "Loi: vui long nhap lai." << endl;
        return 1;
    }
    double ket_qua = tinhDinhThuc2x2(a, b, c, d);
    cout << "\nMa tran A vua nhap:" << endl;
    cout << "(" << a << " " << b << ")" << endl;
    cout << "(" << c << " " << d << ")" << endl;
    cout << "\nDinh thuc cua ma tran A (ad - bc) la: " << ket_qua << endl;
    return 0;
}