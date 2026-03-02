#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
    long long A, a;
    string pin_real, pin_input;
    int max_trial;
    cout << "Nhap so du tai khoan (VND): ";
    cin >> A;
    cout << "Nhap so tien can rut (VND): ";
    cin >> a;
    cout << "Nhap ma PIN (6 chu so): ";
    cin >> pin_real;
    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;
    int trials = 0;
    bool authenticated = false;
    while (trials < max_trial) {
        cout << "Nhap ma PIN: ";
        cin >> pin_input;
        string reversed_pin = pin_real;
        reverse(reversed_pin.begin(), reversed_pin.end());
        if (pin_input == reversed_pin) {
            cout << "Phat hien hanh vi dang ngo. The da bi khoa.\n";
            return 0;
        }
        if (pin_input == pin_real) {
            authenticated = true;
            break;
        } else {
            trials++;
            cout << "Sai ma PIN! (" << trials << "/" << max_trial << ")\n";
        }
    }
    if (!authenticated) {
        cout << "Ban da nhap sai qua so lan cho phep. The bi khoa!\n";
        return 0;
    }
    if (a > A) {
        cout << "So tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
        return 0;
    }
    A -= a;
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "\n========== HOA DON ATM ==========\n";
    cout << "Thoi gian giao dich: " << dt;
    cout << "So tien rut: " << a << " VND\n";
    cout << "So du con lai: " << A << " VND\n";
    cout << "Cam on quy khach da su dung dich vu!\n";
    cout << "=================================\n";
    return 0;
}
