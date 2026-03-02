#include <iostream>

using namespace std;

int main() {
    // Khai bao cac he so cho 2 phuong trinh:
    // a1*x + b1*y = c1
    // a2*x + b2*y = c2
    float a1, b1, c1, a2, b2, c2;
    float D, Dx, Dy, x, y;

    // Nhap du lieu tu ban phim
    cout << "Nhap he so cho phuong trinh thu nhat (a1, b1, c1): ";
    cin >> a1 >> b1 >> c1;
    cout << "Nhap he so cho phuong trinh thu hai (a2, b2, c2): ";
    cin >> a2 >> b2 >> c2;

    // Tinh cac dinh thuc D, Dx, Dy theo cong thuc Cramer
    D = a1 * b2 - a2 * b1;
    Dx = c1 * b2 - c2 * b1;
    Dy = a1 * c2 - a2 * c1;

    // Bien luan cac truong hop
    if (D != 0) {
        // Truong hop 1: He co nghiem duy nhat
        x = Dx / D;
        y = Dy / D;
        cout << "He phuong trinh co nghiem duy nhat:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        // Truong hop D = 0
        if (Dx == 0 && Dy == 0) {
            // Truong hop 2: Vo so nghiem
            cout << "He phuong trinh co vo so nghiem." << endl;
        } else {
            // Truong hop 3: Vo nghiem
            cout << "He phuong trinh vo nghiem." << endl;
        }
    }

    return 0;
}