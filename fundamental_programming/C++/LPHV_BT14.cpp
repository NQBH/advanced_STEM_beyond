#include<iostream>
#include<string>
using namespace std;
int main () {
    long long A, a;
    string pin_true, pin_input;
    int max_trial;
    cin >> A;
    cin >> a;
    cin >> max_trial;
    cin >> pin_true;
    int gioihan=0;
    bool giatri= false;
    while (gioihan < max_trial) {
        cin >> pin_input;
        string pin_dao (pin_true.rbegin(),pin_true.rend());
        if (pin_input == pin_dao) {
            cout << "Security!!! The ban da bi khoa" << endl;
            return 0;
        }
        if (pin_input == pin_true)  {
            giatri = true;
            break;
        } else  {
            gioihan++;
            if (gioihan < max_trial) 
                cout << "Nhap sai ma PIN. Vui long nhap lai" << endl;
        }
    }
    if (!giatri) {
        cout << "The ban da bi khoa do nhap sai qua so lan quy dinh" << endl;
        return 0;
    }
    if (a > A) {
        cout << "So tien rut lon hon so du kha dung. Ban bi ao tuong suc manh tai chinh a?" <<endl;
    } else {
        A -= a;
        cout << "-----HOA DON RUT TIEN-----" <<endl;
        cout << "So tien rut: " << a << " VND" <<endl;
        cout << "So du con lai: " << A << " VND" <<endl;
        cout << "-----Cam own quy khach da su dung dich vu cua ATM VIETCOMBANK!" <<endl;
    }
    return 0;
}