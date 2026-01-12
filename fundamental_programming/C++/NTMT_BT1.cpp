#include <iostream>
using namespace std;
int main() {
    float canh;
    cout << "Nhap do dai canh hinh vuong" << '\n';
    cin >> canh;
    if (canh > 0) {
        float C = canh * 4;
        float S = canh * canh;
        cout << "Chu vi hinh chu nhat la " << C << '\n';
        cout << "Dien tich hinh chu nhat la " << S << '\n';
    }
    else {
        cout << "Vui long nhap so thuc duong" << '\n';
    }
}