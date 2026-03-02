#include <iostream>

using namespace std;



int main() {

// Khai bao bien kieu float cho tong quat (so thuc)

    float a, b, c;


// Nhap lien tu ti cho le

    cout << "Nhap 3 so a, b, c: ";

    cin >> a >> b >> c;



// --- TIM MAX ---

    float max = a; // Gia su ong a lon nhat

    if (b > max) {

        max = b; // b lon hon thi lay b

    }

    if (c > max) {

        max = c; // c lon hon thi lay c

    }



// --- TIM MIN ---

    float min = a; // Gia su ong a nho nhat

    if (b < min) {

        min = b; // b nho hon thi lay b

    }

    if (c < min) {

        min = c; // c nho hon thi lay c

    }



// Xuat ket qua

    cout << "Max: " << max << endl;

    cout << "Min: " << min << endl;



    return 0;

}
BT7: mở rộng
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong n: ";
    cin >> n;

    // Bien temp de luu so vua nhap
    float temp;

    // Nhap so dau tien de lam moc so sanh
    cout << "Nhap so thu 1: ";
    cin >> temp;

    // Gan luon max min la so dau tien
    float max = temp;
    float min = temp;

    // Chay vong lap tu so thu 2 tro di
    for (int i = 2; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> temp;

        // So sanh tim max
        if (temp > max) {
            max = temp;
        }

        // So sanh tim min
        if (temp < min) {
            min = temp;
        }
    }

    cout << "So lon nhat: " << max << endl;
    cout << "So nho nhat: " << min << endl;

    return 0;
}

