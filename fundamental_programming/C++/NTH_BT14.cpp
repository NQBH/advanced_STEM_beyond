#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
using namespace std;

bool kiemTraPIN(string pin) {
    if (pin.length() != 6) return false;
    
    for (char c : pin) {
        if (c < '0' || c > '9') return false;
    }
    
    return true;
}

string daoNguoc(string s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

void inHoaDon(long long soDuCu, long long soTienRut, long long soDuMoi) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    cout << "\n";
    cout << "==========================================" << endl;
    cout << "          NGÂN HÀNG TMCP ABC             " << endl;
    cout << "        ATM WITHDRAWAL RECEIPT            " << endl;
    cout << "==========================================" << endl;
    cout << endl;
    
    cout << "Ngày: " << setfill('0') << setw(2) << ltm->tm_mday << "/" 
         << setw(2) << (1 + ltm->tm_mon) << "/" 
         << (1900 + ltm->tm_year) << endl;
    cout << "Giờ: " << setw(2) << ltm->tm_hour << ":" 
         << setw(2) << ltm->tm_min << ":" 
         << setw(2) << ltm->tm_sec << endl;
    cout << endl;
    
    cout << "Loại giao dịch: RÚT TIỀN MẶT" << endl;
    cout << "Số thẻ: ************1234" << endl;
    cout << endl;
    
    cout << "------------------------------------------" << endl;
    cout << "Số dư trước GD:     " << setw(15) << soDuCu << " VNĐ" << endl;
    cout << "Số tiền rút:        " << setw(15) << soTienRut << " VNĐ" << endl;
    cout << "Phí giao dịch:      " << setw(15) << 0 << " VNĐ" << endl;
    cout << "------------------------------------------" << endl;
    cout << "SỐ DƯ KHẢ DỤNG:     " << setw(15) << soDuMoi << " VNĐ" << endl;
    cout << "==========================================" << endl;
    cout << endl;
    cout << "     Cảm ơn Quý khách đã sử dụng dịch vụ!" << endl;
    cout << "       Vui lòng nhớ lấy tiền và thẻ      " << endl;
    cout << "==========================================" << endl;
}

int main() {
    long long A, a;
    int max_trial;
    string pinThuc;
    
    cout << "=== THIẾT LẬP THÔNG TIN TẠI KHOẢN ===" << endl;
    cout << "Nhập số dư tài khoản (A VNĐ): ";
    cin >> A;
    
    cout << "Nhập mã PIN (6 chữ số): ";
    cin >> pinThuc;
    
    while (!kiemTraPIN(pinThuc)) {
        cout << "Mã PIN phải là 6 chữ số! Nhập lại: ";
        cin >> pinThuc;
    }
    
    cout << "Nhập số lần nhập sai tối đa: ";
    cin >> max_trial;
    
    cout << "\n=== BẮT ĐẦU GIAO DỊCH ===" << endl;
    
    int soLanNhapSai = 0;
    bool xacThucThanhCong = false;
    string pinNhap;
    
    while (soLanNhapSai < max_trial) {
        cout << "\nNhập mã PIN để tiếp tục: ";
        cin >> pinNhap;
        
        if (pinNhap == daoNguoc(pinThuc)) {
            cout << "\n!!! CẢNH BÁO SECURITY !!!" << endl;
            cout << "Phát hiện nhập mã PIN ngược!" << endl;
            cout << "Hệ thống đã ghi nhận hành vi đáng ngờ!" << endl;
            cout << "Giao dịch bị hủy bỏ!" << endl;
            return 0;
        }
        
        if (pinNhap == pinThuc) {
            xacThucThanhCong = true;
            cout << "Xác thực thành công!" << endl;
            break;
        } else {
            soLanNhapSai++;
            if (soLanNhapSai < max_trial) {
                cout << "Mã PIN không chính xác! Bạn còn " 
                     << (max_trial - soLanNhapSai) << " lần thử." << endl;
            }
        }
    }
    
    if (!xacThucThanhCong) {
        cout << "\n!!! THẺ BỊ KHÓA !!!" << endl;
        cout << "Bạn đã nhập sai mã PIN quá " << max_trial << " lần!" << endl;
        cout << "Thẻ của bạn đã bị khóa. Vui lòng liên hệ ngân hàng!" << endl;
        return 0;
    }
    
    cout << "\nNhập số tiền cần rút (a VNĐ): ";
    cin >> a;
    
    if (a > A) {
        cout << "\n!!! GIAO DỊCH THẤT BẠI !!!" << endl;
        cout << "Số tiền rút lớn hơn số dư khả dụng." << endl;
        cout << "Bạn bị ảo tưởng sức mạnh tài chính à?" << endl;
        cout << "\nSố dư khả dụng: " << A << " VNĐ" << endl;
        cout << "Số tiền muốn rút: " << a << " VNĐ" << endl;
    } else {
        long long soDuMoi = A - a;
        
        cout << "\n=== GIAO DỊCH THÀNH CÔNG ===" << endl;
        cout << "Đang xử lý giao dịch..." << endl;
        cout << "Vui lòng nhận tiền!" << endl;
        
        inHoaDon(A, a, soDuMoi);
    }
    
    return 0;
}