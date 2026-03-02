#include <iostream>
#include <string>
using namespace std;

int main() {
    long long A, a;
    int max_trial, dem = 0;
    string pin, pin_nhap, pin_dao = "";

    cout << "Nhap so du A: ";
    cin >> A;
    cout << "Nhap so tien muon rut a: ";
    cin >> a;
    cout << "Nhap ma PIN (6 chu so): ";
    cin >> pin;
    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;

    // Tạo PIN đảo ngược
    for (int i = pin.length() - 1; i >= 0; i--) {
        pin_dao += pin[i];
    }

    // Nhập PIN
    while (dem < max_trial) {
        cout << "Nhap PIN: ";
        cin >> pin_nhap;

        if (pin_nhap == pin_dao) {
            cout << "CANH BAO SECURITY! The bi khoa ngay.\n";
            return 0;
        }

        if (pin_nhap == pin) {
            break;
        } else {
            dem++;
            cout << "Sai PIN!\n";
        }
    }

    if (dem == max_trial) {
        cout << "Nhap sai qua so lan cho phep. The da bi khoa.\n";
        return 0;
    }

    // Rút tiền
    if (a > A) {
        cout << "So tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
    } else {
        A -= a;
        cout << "\n===== HOA DON ATM =====\n";
        cout << "So tien rut: " << a << " VND\n";
        cout << "So du con lai: " << A << " VND\n";
    }

    return 0;
}
