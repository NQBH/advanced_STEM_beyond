#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
    string realPIN = "123456"; 
    long long A;
    long long a;
    int max_trial;
    
    cout << "--- KHOI TAO HE THONG ATM ---" << endl;
    cout << "Nhap so du ban dau (A): "; cin >> A;
    cout << "Nhap so lan thu toi da (max_trial): "; cin >> max_trial;
    string inputPIN;
    int trial = 0;
    bool isAuthenticated = false;

    while (trial < max_trial) {
        cout << "\n[Lan thu " << trial + 1 << "] Nhap ma PIN (6 chu so): ";
        cin >> inputPIN;
        string reversedPIN = inputPIN;
        reverse(reversedPIN.begin(), reversedPIN.end());
        
        if (inputPIN != realPIN && reversedPIN == realPIN) {
            cout << "!!! CANH BAO AN NINH: Phat hien nhap ma nguoc !!!" << endl;
            cout << "He thong da bao security. Khong cho phep thao tac tiep." << endl;
            return 0;
        }
        if (inputPIN == realPIN) {
            isAuthenticated = true;
            break;
        } else {
            trial++;
            if (trial < max_trial) {
                cout << "Sai ma PIN. Vui long thu lai." << endl;
            }
        }
    }

    if (!isAuthenticated) {
        cout << "\n[THONG BAO] Nhap sai qua " << max_trial << " lan. THE CUA BAN DA BI KHOA!" << endl;
        return 0;
    }
    cout << "\nNhap so tien ban muon rut (a): ";
    cin >> a;

    if (a > A) {
        cout << "So tien rut lon hon so du kha dung" << endl;
    } else {
        A -= a;
        cout << "\nRut tien thanh cong!" << endl;
        cout << "------------------------------------------" << endl;
        cout << "            BIEN LAI GIAO DICH            " << endl;
        cout << "------------------------------------------" << endl;
        cout << " Ngay gio: 02/02/2026  23:30              " << endl;
        cout << " So may ATM: ATM0102                      " << endl;
        cout << " So tien rut:   " << setw(15) << a << " VND" << endl;
        cout << " So du con lai: " << setw(15) << A << " VND" << endl;
        cout << "------------------------------------------" << endl;
        cout << "      CAM ON QUY KHACH DA SU DUNG!        " << endl;
    }

    return 0;
}