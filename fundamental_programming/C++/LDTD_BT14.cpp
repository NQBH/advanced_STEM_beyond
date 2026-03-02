#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    
    double A; // Số dư tài khoản
    double a; // Số tiền muốn rút
    string pin_real = "123456"; 
    string pin_input;
    int max_trial;
    int count = 0;

    cout << "--- CHUONG TRINH MO PHONG ATM ---" << endl;
    cout << "Nhap so du hien tai (A): "; cin >> A;
    cout << "Nhap so lan thu toi da (max_trial): "; cin >> max_trial;

    // Chuẩn bị mã PIN ngược để kiểm tra bảo mật
    string pin_reverse = pin_real;
    reverse(pin_reverse.begin(), pin_reverse.end());// lenh reverse lam dao nguoc so vua nhap

    // 1. phan nhap ma PIN
    while (count < max_trial) {
        cout << "Nhap ma PIN (6 chu so): ";
        cin >> pin_input;

        if (pin_input == pin_reverse) {
            cout << "!!! CANH BAO  !!! Ban nhap ma nguoc. Cam truy cap!" << endl;
            return 0; 
        }

        if (pin_input == pin_real) {
            cout << "Dang nhap thanh cong!" << endl;
            break; 
        } else {
            count++;
            cout << "Sai ma PIN. Con lai " << max_trial - count << " lan thu." << endl;
        }

        if (count == max_trial) {
            cout << "KHOA THE! Ban da nhap sai qua so lan quy dinh." << endl;
            return 0;
        }
    }

    // 2. Qua trinh rut tien
    cout << "Nhap so tien ban muon rut (a): ";
    cin >> a;

    if (a > A) {
        cout << "So tien rut lon hon so du kha dung ?" << endl;
    } else {
        A = A - a; // Tru tien trong tai khoan
        cout << "\n----------------------------" << endl;
        cout << "      BIEN LAI GIAO DICH     " << endl;
        cout << "----------------------------" << endl;
        cout << "Trang thai: Thanh cong" << endl;
        cout << "So tien rut: " << a << " VND" << endl;
        cout << "So du con lai: " << A << " VND" << endl;
        cout << "Cam on quy khach!" << endl;
        cout << "----------------------------" << endl;
    }

    return 0;
}