#include <iostream>

using namespace std;

int main() {

    int a, b, c, d;
    int determinant;

    cout << "--- TINH DINH THUC MA TRAN THUC 2x2 ---\n";
    cout << "Ma tran co dang:\n";
    cout << "| a  b |\n";
    cout << "| c  d |\n";

    cout << "\nNhap a: ";
    cin >> a;
    
    cout << "Nhap b: ";
    cin >> b;
    
    cout << "Nhap c: ";
    cin >> c;
    
    cout << "Nhap d: ";
    cin >> d;

    determinant = (a * d) - (b * c);
    
    cout << "\n-----------------------------------------\n";
    cout << "Ma tran da nhap:\n";
    cout << "| " << a << "  " << b << " |\n";
    cout << "| " << c << "  " << d << " |\n";
    
    cout << "\nDinh thuc (ad - bc) la: " << determinant << "\n";
    cout << "-----------------------------------------\n";

    return 0;
}