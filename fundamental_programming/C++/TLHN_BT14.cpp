#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    long long so_du, so_rut;
    string pin_that, pin_nhap;
    int so_lan_toi_da;

    // Nhap du liệu


    cout << "Nhap so du tai khoan (VND): ";
    cin >> so_du;

    cout << "Nhap so tien muon rut (VND): ";
    cin >> so_rut;



    // nhập PIN thật (bắt buộc 6 chữ số)


    do {
        cout << "Nhap ma PIN (6 chu so): ";
        cin >> pin_that;
    } while (pin_that.length() != 6);

    cout << "Nhap so lan nhap PIN toi da: ";
    cin >> so_lan_toi_da;


    // Khởi tạo PIN đảo ngược
    string pin_nguoc = pin_that;
    reverse(pin_nguoc.begin(), pin_nguoc.end());

    bool dung_pin = false;



    // Nhập mã PIn


    for (int i = 1; i <= so_lan_toi_da; i++) {
        cout << "Nhap PIN (lan " << i << "): ";
        cin >> pin_nhap;

        if (pin_nhap == pin_nguoc) {
            cout << "Security! The bi khoa." << endl;
            return 0;
        }

        if (pin_nhap == pin_that) {
            dung_pin = true;
            break;
        }

        cout << "PIN sai!" << endl;
    }

    if (!dung_pin) {
        cout << "Ban da nhap sai qua so lan cho phep. The bi khoa." << endl;
        return 0;
    }




    // Xử lý rút tiền
    if (so_rut > so_du) {
        cout << "So tien rut lon hon so du kha dung. Ban bi ao tuong suc manh tai chinh a?" << endl;
    } else {
        so_du -= so_rut;
        cout << endl << "===== HOA DON ATM =====" << endl;
        cout << "So tien rut: " << so_rut << " VND" << endl;
        cout << "So du con lai: " << so_du << " VND" << endl;
        cout << "Giao dich rut tien thanh cong" << endl;
    }

    return 0;
}
