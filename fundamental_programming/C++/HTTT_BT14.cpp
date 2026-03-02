#include <iostream>
#include <string>
using namespace std;

// Hàm đảo ngược chuỗi PIN
string daoNguoc(string s) {
    string kq = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        kq += s[i];
    }
    return kq;
}

int main() {
    long long A, a;
    string PIN, nhapPIN;
    int max_trial, dem = 0;

    cout << "Nhap so du A: ";
    cin >> A;
    cout << "Nhap so tien muon rut a: ";
    cin >> a;
    cout << "Nhap PIN that (6 chu so): ";
    cin >> PIN;
    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;

    // Nhap PIN
    while (dem < max_trial) {
        cout << "Nhap PIN: ";
        cin >> nhapPIN;

        if (nhapPIN == daoNguoc(PIN)) {
            cout << "Canh bao an ninh! Khoa the ngay!" << endl;
            return 0;
        }

        if (nhapPIN == PIN) break;

        cout << "Sai PIN!" << endl;
        dem++;
    }

    if (dem == max_trial) {
        cout << "Nhap sai qua so lan! The da bi khoa." << endl;
        return 0;
    }

    // Rut tien
    if (a > A) {
        cout << "So tien rut lon hon so du kha dung. "
             << "Ban bi ao tuong suc manh tai chinh a?" << endl;
    } else {
        cout << "Rut tien thanh cong!" << endl;
        cout << "So du con lai: " << A - a << " VND" << endl;
    }

    return 0;
}
