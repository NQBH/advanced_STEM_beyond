#include<iostream>
using namespace std;

int dao(int x) {
    int nghichdao = 0;
    while (x > 0) {
        nghichdao = nghichdao * 10 + x % 10;
        x /= 10;
    }
    return nghichdao;
}

int main() {
    int A, a, max_trial, dem = 0;;
    int PIN, inPIN;

    cout << "so tien(VND) ban co: ";
    cin >> A;
    while (cin.fail() || A < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai so tien (lon hon 0, chi nhap so): ";
        cin >> A;
    }

    cout << "tao ma PIN (6 so): ";
    cin >> PIN;
    while (cin.fail() || PIN < 100000 ||PIN > 999999) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai PIN (chi nhap 6 so, khong nhap chu): ";
        cin >> PIN;
    }

    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;
    while (cin.fail() || max_trial <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai so lan thu (lon hon 0, chi nhap so): ";
        cin >> max_trial;
    }
    
    cout << "---------------------------------" << endl;

    while (dem < max_trial) {
        cout << "\nNhap PIN: ";
        cin >> inPIN;

        if (inPIN == dao(PIN)) {
            cout << "SECURITY ALERT! Ban da nhap PIN nguoc. The bi khoa!\n";
            return 0;
        }

        if (inPIN == PIN) {
            cout << "Xac thuc thanh cong!\n";
            break;
        }

        dem++;
        cout << "Sai PIN! Ban con " << max_trial - dem << " lan thu.\n";
    }

    if (dem == max_trial) {
        cout << "Ban da nhap sai qua so lan cho phep. The bi khoa!\n";
        return 0;
    }

    cout << "nhap so tien can rut: ";
    cin >> a;

    if (a > A) {
        cout << "So tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
        return 0;
    } else {
        A -= a;
    }

        cout << "\n========= HOA DON ATM =========\n";
        cout << "So tien rut : " << a << " VND\n";
        cout << "So du con lai: " << A << " VND\n";
        cout << "Cam on quy khach da su dung dich vu!\n";
        cout << "================================\n";
    }
