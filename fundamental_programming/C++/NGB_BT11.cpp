#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a, b, c;
    double A, B, C;
    double a1, b1, c1;  
    double A1, B1, C1;  
    double x, y;
    // Nhập hệ số phương trình 1: ax + by = c
    cout << "Nhap he so phuong trinh 1 (ax + by = c):" << endl;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;
    // Nhập hệ số phương trình 2: Ax + By = C
    cout << "Nhap he so phuong trinh 2 (Ax + By = C):" << endl;
    cout << "Nhap A: ";
    cin >> A;
    cout << "Nhap B: ";
    cin >> B;
    cout << "Nhap C: ";
    cin >> C;
    // Kiểm tra trường hợp đặc biệt: cả 2 phương trình đều không có x
    if (a == 0 && A == 0) {
        cout << "Khong the giai (ca 2 phuong trinh deu khong co x)" << endl;
    } else {
        // Phương pháp khử: nhân chéo để khử x
        a1 = a * A;
        b1 = b * A;
        c1 = c * A;
        
        A1 = A * a;
        B1 = B * a;
        C1 = C * a;
        // Trừ 2 phương trình: (b1 - B1)y = c1 - C1
        double he_so_y = b1 - B1;
        double ve_phai = c1 - C1;
        if (he_so_y != 0) {
            // Tìm được y
            y = ve_phai / he_so_y;
            // Thế y vào phương trình 1 để tìm x
            if (a != 0) {
                x = (c - b * y) / a;
            }
            else {
                x = (C - B * y) / A;
            }
            
            cout << "He co nghiem duy nhat la:" << endl;
            cout << "x = " << x << endl;
            cout << "y = " << y << endl;
        }
        else {
            // he_so_y = 0
            if (ve_phai == 0) {
                cout << "He co vo so nghiem" << endl;
            }
            else {
                cout << "He vo nghiem" << endl;
            }
        }
    }
    
    return 0;
}