#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float a11, a12, a21, a22;

    cout << "--- NHAP MA TRAN 2x2 \n";
    cout << "Nhap phan tu a1 1 : ";
    cin >> a11;
    cout << "Nhap phan tu a1 2: ";
    cin >> a12;
    cout << "Nhap phan tu a2 1: ";
    cin >> a21;
    cout << "Nhap phan tu a2 2: ";
    cin >> a22;

    cout << "\n nhap ma tran :\n";
    cout << fixed << setprecision(2);
    cout << a11 << "  " << a12 << "\n";
    cout << a21 << "  " << a22 << "\n";

    float cheo_chinh = a11 * a22;
    float t_cheo_phu = a12 * a21;
    float dinh_thuc = cheo_chinh - t_cheo_phu;

   
    cout << "Dinh thuc cua ma tran la: " << dinh_thuc << endl;

    return 0;
}