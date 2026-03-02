#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A;
    long long a;
    int max;
    
    string PINdung = "123456";
    string PINnguoc = "654321";
    string PINnhap;

    cout << "~~~ Cấu Hình ATM ~~~\n";
    cout << "Nhập số dư A: ";
    cin >> A;
    cout << "Nhập giới hạn sai PIN (max): ";
    cin >> max;

    cout << "\n-----------------------------\n";
    cout << "   WELCOME TO NOVA BANK      \n";
    cout << "-----------------------------\n";

    int count = 0; 
    bool bikhoa = false;

    while (count < max) {
        cout << "Vui lòng nhập mã PIN: ";
        cin >> PINnhap;

        if (PINnhap == PINdung) {
            break;
        }
        if (PINnhap == PINnguoc) {
            cout << "\n!!! Cảnh báo !!! Phát hiện nhập ngược mã PIN.\n";
            cout << "Hệ thống tự động kích hoạt bảo mật. Không cho phép thử lại.\n";
            bikhoa = true;
            break;
        }
        count++;
        cout << "Mã PIN Sai! Bạn còn " << (max - count) << " lần thử.\n";
    }
    if (bikhoa || count >= max) {
        cout << "\nTHẺ ĐÃ BỊ KHÓA. Vui lòng liên hệ ngân hàng!\n";
        return 0;
    }
    cout << "\n~~~Đăng Nhập Thành Công~~~\n";
    cout << "Số dư hiện tại: " << A << " VND\n";
    cout << "Nhập số tiền muốn rút (a): ";
    cin >> a;

    if (a > A) {
        cout << "\nSố tiền Lớn hơn Số Dư. Nghèo đòi rút ATM?\n";
    } else {
        A = A - a;

        cout << "\nĐang Thực hiện giao dịch...\n";
        cout << "Rút tiền thành công!\n";
        cout << "________________________________\n";
        cout << "|        Hóa Đơn giao dịch     \n";
        cout << "|------------------------------\n";
        cout << "| Ngân Hàng: NOVA BANK         \n";
        cout << "| Số tiền rút:   " << a << " VND\n";
        cout << "| Số dư còn lại: " << A << " VND\n";
        cout << "|______________________________\n";
        cout << "   cảm ơn và hẹn gặp lại!       \n";
    }

    return 0;
}
