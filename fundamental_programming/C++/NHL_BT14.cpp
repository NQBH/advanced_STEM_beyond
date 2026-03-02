#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
    long long a, A, solanthu;
    string PIN, pinnhapvao;
    cout << "nhập số tiền đang có A: ";
    cin >> A;
    cout << "nhập mã PIN bạn muốn: ";
    cin >> PIN;
    PIN.length() == 6;
    while (PIN.length() != 6) {
        cout << "mã pin đã chọn phải đủ 6 chữ số" << '\n';
        cout << "vui lòng chọn lại mã pin: ";
        cin >> PIN;
    }
    cout << "số lần có thể nhập mã PIN: ";
    cin >> solanthu;

    int i = 0;
    while (i < solanthu) {
        cout << "nhập mã PIN của bạn: ";
        cin >> pinnhapvao;
        if (pinnhapvao.length() != 6) {cout << "mã pin bắt buộc phải có 6 chữ số" << '\n';}
        string pindao = PIN;
        reverse(pindao.begin(), pindao.end());
        if (pinnhapvao == pindao) {
            cout << "đã rút ra số tiền: " << A / 2 << '\n';
            cout << "đã báo với với security";
            break;
        }

        if (pinnhapvao == PIN) {
            cout << "nhập số tiền muốn rút a: ";
            cin >> a;
            if (a > A) {cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?";}
            else {
                cout << "Rút thành công" << '\n';
                cout << "          HÓA ĐƠN RÚT TIỀN" << '\n';
                cout << "                      ngày 2 tháng 2 năm 2026" << '\n';
                cout << "                            " << '\n';
                cout << "                            " << '\n';
                cout << "MB Bank" << '\n';
                cout << "Thông tin người rút: Nguyễn Huy Long" << '\n';
                cout << "số tiền đã rút: " << a << '\n';
                cout << "bằng chữ: " << '\n';
                cout << "số dư còn lại: " << A - a << '\n';
                cout << "                       " << '\n';
                cout << "                            " << '\n';
                cout << "                            " << '\n';
                cout << "                                    người rút kí tên           " << '\n';
                cout << "                                    Nguyễn Huy long           " << '\n';

            }
            break;
        }
        else {
            cout << "sai mã PIN" << '\n';
            i++;
            if (i >= solanthu) {
                cout << "thẻ của bạn đã bị khóa";
            }
        }

    }


}