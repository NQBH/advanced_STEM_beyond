#include <iostream>
#include <string>

using namespace std;

int main() {
    long long A, a;
    int so_lan_thu;
    int count = 0;
    string Ma_PIN = "123456";
    string PIN_Nguoc = "654321";
    string input_PIN;

    cout << "Nhap so du tai khoan: "; cin >> A;
    cout << "Nhap so_lan_thu: "; cin >> so_lan_thu;

    while (true) {
        cout << "Nhap ma PIN: ";
        cin >> input_PIN;

        if (input_PIN == Ma_PIN) {
            break;
        }

        if (input_PIN == PIN_Nguoc) {
            cout << "Security alert! Khong cho nhap PIN nua." << endl;
            return 0;
        }

        count++;
        if (count >= so_lan_thu) {
            cout << "Khoa the!" << endl;
            return 0;
        }
        
        cout << "Ma PIN sai." << endl;
    }

    cout << "Nhap so tien can rut a: ";
    cin >> a;

    if (a > A) {
        cout << "So tien rut lon hon so du kha dung. Ban bi ao tuong suc manh tai chinh a?" << endl;
    } else {
        A -= a;
        cout << "Rut thanh cong. So du con lai: " << A << " VND" << endl;
    }

    return 0;
}