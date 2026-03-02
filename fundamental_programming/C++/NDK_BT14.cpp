#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    long long A;
    long long a;
    int max_trial;
    string realPIN = "123456";
    string pinInput;
    cout << "--- HE THONG QUAN LY ATM ---" << endl;
    cout << "Nhap so du tai khoan hien co: ";
    cin >> A;
    cout << "Nhap gioi han so lan nhap sai PIN (max_trial): ";
    cin >> max_trial;
    cout << "----------------------------------------" << endl;
    int count = 0;
    bool isLoginSuccess = false;

    cout << "\n>> Vui long dua the vao may..." << endl;

    while (count < max_trial) {
        cout << "Nhap ma PIN (Lan thu " << count + 1 << "/" << max_trial << "): ";
        cin >> pinInput;
        count++;

        if (pinInput == realPIN) {
            isLoginSuccess = true;
            break;
        }
        string temp = pinInput;
        reverse(temp.begin(), temp.end());

        if (temp == realPIN) {
            cout << "\n!!! CANH BAO BAO MAT !!!" << endl;
            cout << "Phat hien ma PIN dao nguoc. Nghi ngo gian lan." << endl;
            cout << "THE DA BI KHOA NGAY LAP TUC!" << endl;
            return 0;
        }
        if (count < max_trial) {
            cout << ">> Ma PIN sai. Vui long thu lai." << endl;
        }
    }

    if (!isLoginSuccess) {
        cout << "\n>> Ban da nhap sai qua " << max_trial << " lan." << endl;
        cout << ">> THE DA BI KHOA DE DAM BAO AN TOAN." << endl;
        return 0;
    }

    cout << "\n>> DANG NHAP THANH CONG!" << endl;
    cout << "So du kha dung: " << A << " VND" << endl;
    cout << "Nhap so tien muon rut (a): ";
    cin >> a;
    if (a > A) {
        cout << "\n----------------------------------------" << endl;
        cout << "THONG BAO GIAO DICH THAT BAI:" << endl;
        cout << ">> So tien rut lon hon so du kha dung." << endl;
        cout << ">> DI NGU MA MO RUT BAY NHIEU DO TIEN DI ,O DAY KHONG DU ROIII =))))))" << endl;
        cout << "----------------------------------------" << endl;
    }
    else {
        A = A - a;
        cout << "\n... Dang giao dich ... (Ting ting) ..." << endl;
        cout << "\n******************************************" << endl;
        cout << "* HOA DON GIAO DICH            *" << endl;
        cout << "* NGAN HANG C++ BANK           *" << endl;
        cout << "******************************************" << endl;
        cout << " NGAY: 02/02/2026        GIO: 14:30      " << endl;
        cout << " SO THE: XXXXXXXXXXXX1234                " << endl;
        cout << " ----------------------------------------" << endl;
        cout << " LOAI GIAO DICH:         RUT TIEN MAT    " << endl;
        cout << " SO TIEN RUT:            " << a << " VND" << endl;
        cout << " PHI DICH VU:            0 VND           " << endl;
        cout << " ----------------------------------------" << endl;
        cout << " SO DU CON LAI:          " << A << " VND" << endl;
        cout << "******************************************" << endl;
        cout << "* CAM ON QUY KHACH DA SU DUNG       *" << endl;
        cout << "******************************************" << endl;
    }

    return 0;
}