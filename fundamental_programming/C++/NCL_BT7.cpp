#include <iostream>
using namespace std;

int main() {
    int n;
    float so, max, min;

    cout << "Nhap so luong phan tu n: ";
    cin >> n;
    if (n <= 0) {
        cout << "So luong phan tu khong hop le!";
        
    }
    cout << "Nhap so thu 1: ";
    cin >> so;
    max = so;
    min = so;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i;
        cin >> so;

        if (so > max) {
            max = so;
        }
        if (so < min) {
            min = so;
        }
    }
    cout << "So lon nhat la: " << max << endl;
    cout << "So nho nhat la: " << min << endl;

}

