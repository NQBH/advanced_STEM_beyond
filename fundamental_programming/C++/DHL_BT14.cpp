#include <iostream>
using namespace std;

int main() {
    int A, a;           
    int pin_real;       
    int pin_input;      
    int max_trial;      
    int count = 0;      

    // Nhap du lieu
    cout << "Nhap so du tai khoan: ";
    cin >> A;

    cout << "Nhap so tien muon rut: ";
    cin >> a;

    cout << "Nhap ma PIN that (6 chu so): ";
    cin >> pin_real;

    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;

    // Nhap PIN
    while (count < max_trial) {
        cout << "Nhap ma PIN: ";
        cin >> pin_input;

        if (pin_input == pin_real) {
            break;   // dung PIN -> thoat vong lap
        } else {
            cout << "Sai PIN!\n";
            count++;
        }
    }

    // Neu nhap sai qua so lan
    if (count == max_trial) {
        cout << "Ban da nhap sai qua so lan. The bi khoa!\n";
        return 0;
    }

    // Kiem tra rut tien
    if (a > A) {
        cout << "So tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
    } else {
        A = A - a;
        cout << "\n===== HOA DON ATM =====\n";
        cout << "So tien rut: " << a << " VND\n";
        cout << "So du con lai: " << A << " VND\n";
        cout << "=======================\n";
    }

    return 0;
}
