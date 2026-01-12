

// BT1: (+1) Viết chương trình C++ nhập vào cạnh 1 hình vuông,
// rồi tính chu vi & diện tích hình vuông đó.


#include <iostream>
using namespace std;


int main() {
    float canhA;

    cout << "Nhap canh hinh vuong: ";
    cin >> canhA;

    // Kiem tra canh hop le
    if (canhA <= 0) {
        cout << -1;
        return 0;
    }

    float chuVi = 4 * canhA;
    float dienTich = canhA * canhA;

    cout << "Chu vi hinh vuong la: " << chuVi << endl;
    cout << "Dien tich hinh vuong la: " << dienTich << endl;

    return 0;
}


