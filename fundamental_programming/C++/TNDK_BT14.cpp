#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
    long long A, a;
    string pinDung, pinNhap;
    int max_trial;
    int trial = 0;

    cout << "Nhap so du tai khoan (A): ";
    cin >> A;
    cout << "Nhap so tien can rut (a): ";
    cin >> a;
    cout << "Nhap ma PIN dung (6 chu so): ";
    cin >> pinDung;
    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;

    string pinDao = pinDung;
    reverse(pinDao.begin(), pinDao.end());

    while (trial < max_trial) {
        cout << "\nNhap ma PIN: ";
        cin >> pinNhap;

        if (pinNhap == pinDung) {
            cout << "Xac thuc thanh cong!\n";
            break;
        }

        if (pinNhap == pinDao) {
            cout << "CANH BAO SECURITY!\n";
            cout << "Da bao ve bao ve ngan hang!\n";
            return 0;
        }

        trial++;
        if (trial == max_trial) {
            cout << "\nTHE DA BI KHOA!\n";
            cout << "Nhap sai PIN qua so lan cho phep!\n";
            cout << "Da bao ve bao ve ngan hang!\n";
            return 0;
        }

        cout << "Ma PIN sai! Con " << (max_trial - trial) << " lan thu.\n";
    }

    if (a > A) {
        cout << "\nSo tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
        return 0;
    }

    A -= a;

    time_t now = time(0);
    cout << "\n========== HOA DON ATM ==========\n";
    cout << "Thoi gian: " << ctime(&now);
    cout << "So tien rut: " << a << " VND\n";
    cout << "So du con lai: " << A << " VND\n";
    cout << "Cam on quy khach da su dung dich vu!\n";
    cout << "=================================\n";

    return 0;
}