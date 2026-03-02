#include <iostream>
#include <string>
using namespace std;
// Ham dao nguoc chuoi
string reverseString (string s) {
    string rev = "";
    for (int i = s.length () - 1; i >= 0; i--) {
        rev += s[i];
    }
    return rev;
}

int main() {
    long long A;            // so du ban dau
    long long a;           // so tien can rut
    int max_trial;        // so lan nhap sai toi da
    string pin_real;     // ma PIN that
    string pin_input;   // ma PIN nhap vao

    cout << "Nhap so du tai khoan (VND):  ";
    cin >> A;

    cout << "Nhap so tien can rut (VND): ";
    cin >> a;

    cout << "Nhap so lan nhap ma pin toi da: ";
    cin >> max_trial;

    cout << "Nhap ma PIN that (6 chu so): ";
    cin >> pin_real;

    int trial = 0;
    bool authenticated = false;

    while (trial < max_trial) {
        cout << "Nhap ma PIN: ";
        cin >> pin_input;

        // Kiem tra PIN dao nguoc
        if (pin_input  == reverseString(pin_real) ) {
            cout << "Canh bao SECURITY!!! khoa the ngay lap tuc! \n";
            return 0;

        }

        if (pin_input == pin_real) {
            authenticated = true;
            break;
        } else {
            trial++;
            cout << "Sai PIN! Ban con " << max_trial - trial << "Lan thu .\n";
        }
    }

    if (!authenticated) {
        cout << "Ban da nhap sao qua so lan cho phep . The bi khoa!\n";
        return 0;
    }

    // Xu ly rut tien
    if (a > A) {
        cout << "So tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
    } else {
        A -= a;
        cout << "\n ==== HOA DON ATM ====\n";
        cout << "So tien rut: " << a << "VND\n";
        cout << "So du con lai: " << A << "VND\n";
        cout << "Giao dich thanh cong!\n";
        cout << "Cam on ban da su dung dich vu!\n";
        cout << "==================== \n ";
    }



    return 0;
}
