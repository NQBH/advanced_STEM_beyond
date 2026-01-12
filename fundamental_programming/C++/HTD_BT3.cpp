#include <iostream>
#include <cmath> // Thu vien de dung sqrt
using namespace std;

int main() {
    // 1. Khai bao 3 canh a, b, c la so nguyen
    int a, b, c;

    cout << "Nhap 3 canh: ";
    cin >> a >> b >> c;

    // 2. Kiem tra xem co phai so duong khong
    // Neu a hoac b hoac c nho hon hoac bang 0 thi sai -> in -1
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1;
    }
    // 3. Kiem tra Hinh Lap Phuong (3 canh bang nhau)
    else if (a == b && b == c) {
        cout << "HLP";
    }
    // 4. Con lai la Hinh Hop Chu Nhat
    else {
        cout << "HHCN" << endl;

        // Tinh toan
        // Phai ep kieu sang float de tinh toan cho chinh xac (vi ket qua co the le)
        float sxq = 2 * (a + b) * c;
        float stp = 2 * (a * b + b * c + c * a);
        float thetich = a * b * c;

        // Duong cheo = can bac 2 cua (a^2 + b^2 + c^2)
        // vi a, b, c la int nen nhan vao co the tran so, nen ep kieu float
        float dcheo = sqrt((float)a * a + b * b + c * c);

        // Xuat ket qua
        cout << "Dien tich xung quanh: " << sxq << endl;
        cout << "Dien tich toan phan: " << stp << endl;
        cout << "Duong cheo: " << dcheo << endl;
        cout << "The tich: " << thetich;
    }

    return 0;
}