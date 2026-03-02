#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong n: ";
    cin >> n;

    // Khai bao 3 bien dem.
    // QUAN TRONG: Phai gan bang 0 tu dau, neu khong may se lay gia tri rac!
    int dem0 = 0;
    int demAm = 0;
    int demDuong = 0;

    float temp; // Bien tam de luu so vua nhap

    // Chay vong lap tu 1 den n de nhap so
    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> temp;

        // Kiem tra tung truong hop
        if (temp == 0) {
            dem0++; // Gap so 0 thi tang bien dem so 0 len 1
        }
        else if (temp < 0) {
            demAm++; // Nho hon 0 thi tang bien dem so am
        }
        else {
            demDuong++; // Truong hop con lai la so duong (temp > 0)
        }
    }

    // Xuat ket qua ra man hinh
    cout << "--------------------" << endl;
    cout << "So luong so 0: " << dem0 << endl;
    cout << "So luong so am: " << demAm << endl;
    cout << "So luong so duong: " << demDuong << endl;

    return 0;
}