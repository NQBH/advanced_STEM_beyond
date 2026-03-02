/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
    long long A, a;
    int max_trial;
    string pin_real = "123456";   
    string pin_input;
    int count = 0;

    cout << "Nhap so du tai khoan: ";
    cin >> A;
    cout << "Nhap so tien can rut: ";
    cin >> a;
    cout << "Nhap so lan nhap PIN toi da: ";
    cin >> max_trial;

    while (true) {
        cout << "Nhap ma PIN (6 chu so): ";
        cin >> pin_input;

        if (pin_input == daoNguoc(pin_real)) {
            cout << "Phat hien nhap PIN nguoc. The da bi khoa!";
            return 0;
        }

        if (pin_input == pin_real) {
            cout << "Nhap PIN thanh cong!\n";
            break;
        }
        count++;
        cout << "Nhap sai PIN!\n";

        if (count >= max_trial) {
            cout << "Ban da nhap sai qua so lan cho phep. The da bi khoa!";
            return 0;
        }
    }

    if (a > A) {
        cout << "So tien rut lon hon so du kha dung.\n";
        cout << "Da bao can nua vien thoi!";
    } else {
        A -= a;
        cout << "\nHOA DON ATM\n";
        cout << "So tien rut: " << a << " VND\n";
        cout << "So du con lai: " << A << " VND\n";
    }

    return 0;
}