#include <iostream>
#include <string>
using namespace std;
string daoNguoc(string s) {
    string t = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        t += s[i];
    }
    return t;
}
int main() {
    string PIN_thuc, PIN_nhap;
    int max_trial, dem = 0;
    long long A, a;
    cout << "Nhap PIN thuc (6 chu so): ";
    cin >> PIN_thuc;
    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;
    while (dem < max_trial) {
        cout << "Nhap ma PIN: ";
        cin >> PIN_nhap;
        if (PIN_nhap == daoNguoc(PIN_thuc)) {
            cout << "SECURITY ALERT! The bi khoa.\n";
            return 0;
        }
        if (PIN_nhap == PIN_thuc) {
            cout << "Dang nhap thanh cong!\n";
            break;
        }
        dem++;
        cout << "Sai PIN!\n";
    }
    if (dem == max_trial) {
        cout << "Nhap sai qua so lan cho phep. The bi khoa!\n";
        return 0;
    }
    cout << "Nhap so du tai khoan A: ";
    cin >> A;
    cout << "Nhap so tien can rut a: ";
    cin >> a;
    if (a > A) {
        cout << "So tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
    } else {
        A -= a;
        cout << "\n===== HOA DON ATM =====\n";
        cout << "So tien da rut: " << a << " VND\n";
        cout << "So du con lai: " << A << " VND\n";
        cout << "Cam on ban da su dung dich vu!\n";
    }
    return 0;
}
