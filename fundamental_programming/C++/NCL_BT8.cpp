#include <iostream>
using namespace std;

int main() {
    int n;
    int demDuong = 0, demAm = 0, demKhong = 0;

    cout << "Nhap so luong phan tu n: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Sai: n phai la so nguyen duong!";
    }

    cout << "Nhap " << n << " so thuc:\n";
    
    for (int i = 1; i <= n; i++) {
        float so;
        cout << "a" << i;
        cin >> so;
        
        if (so > 0) {
            demDuong++;
        } else if (so < 0) {
            demAm++;
        } else {
            demKhong++;
        }
    }

    cout << "Ket qua: ";
    cout << "So so duong: " << demDuong << endl;
    cout << "So so am: " << demAm << endl;
    cout << "So so khong: " << demKhong << endl;

}