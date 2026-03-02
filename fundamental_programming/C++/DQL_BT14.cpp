#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    long long A, a;
    string pin_real, pin_input;
    int max_trial, trial = 0;

    cout << "Nhap so du tai khoan (A): ";
    cin >> A;
    cout << "Nhap so tien can rut (a): ";
    cin >> a;

    cout << "Nhap ma PIN that (6 chu so): ";
    cin >> pin_real;

    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;

    string pin_reverse = pin_real;
    reverse(pin_reverse.begin(), pin_reverse.end());

    while (trial < max_trial) {
        cout << "Nhap ma PIN: ";
        cin >> pin_input;

        if (pin_input == pin_reverse) {
            cout << "!!! CANH BAO AN NINH !!!\n";
            cout << "Phat hien nhap PIN nguoc. Khoa the ngay lap tuc.\n";
            return 0;
        }

        if (pin_input == pin_real) {
            cout << "Xac thuc thanh cong \n";

            if (a > A) {
                cout << "So tien rut lon hon so du kha dung.\n";
                cout << "Ban bi ao tuong suc manh tai chinh a? \n";
            } else {
                A -= a;
                cout << "\n========== HOA DON ATM ==========\n";
                cout << "So tien rut: " << a << " VND\n";
                cout << "So du con lai: " << A << " VND\n";
                cout << "Cam on quy khach. Hen gap lai! \n";
                cout << "================================\n";
            }
            return 0;
        }

        trial++;
        cout << "Sai Ma PIN. Con " << max_trial - trial << " lan thu.\n";
    }

    cout << "Nhap sai qua so lan cho phep. The da bi khoa \n";
    return 0;
}