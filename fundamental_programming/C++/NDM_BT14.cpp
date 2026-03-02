#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    long long A, a;
    int max_trial;
    string TruePIN, inputPIN;
    int trial = 0;

    cout << "Nhap so tien tai khoan (VND): ";
    cin >> A;

    cout << "Nhap so tien muon rut (VND): ";
    cin >> a;

    cout << "Nhap ma PIN that (6 chu so): ";
    cin >> TruePIN;

    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;

    while (trial < max_trial) {
        cout << "Nhap ma PIN (6 chu so): ";
        cin >> inputPIN;

        string reversedPIN = TruePIN;
        reverse(reversedPIN.begin(), reversedPIN.end());

        if (inputPIN == reversedPIN) {
            cout << "SECURITY ALERT!\n";
            cout << "Phat hien nhap PIN nguoc. The bi khoa!\n";
            return 0;
        }

        if (inputPIN == TruePIN) {
            if (a > A) {
                cout << "So tien rut lon hon so du kha dung.\n";
                cout << "Ban bi ao tuong suc manh tai chinh a?\n";
            } 
            else {
                A -= a;
                cout << "\n===== HOA DON ATM =====\n";
                cout << "So tien da rut: " << a << " VND\n";
                cout << "So du con lai: " << A << " VND\n";
                cout << "Cam on ban da su dung dich vu!\n";
                cout << "=======================\n";
            }
        }
        else {
            trial++;
            cout << "Ma PIN sai! Con " << (max_trial - trial) << " lan thu.\n";
        }
    }

    cout << "Ban da nhap sai qua so lan quy dinh. Tai khoan da bi khoa.\n";
    return 0;
}
