#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. Khai bao bien
    long long A;        // So du (A)
    long long a;        // So tien can rut (a)
    int max_trial;      // So lan cho phep nhap sai
    
    string ma_pin_chuan = "123456"; // Ma PIN mac dinh
    string ma_nhap;                 // Ma PIN nguoi dung nhap
    bool check_login = false;       // Bien kiem tra xem da dang nhap duoc chua

    // 2. Nhap du lieu dau vao
    cout << "Nhap so du hien tai (A): ";
    cin >> A;
    cout << "Nhap so lan cho phep sai PIN (max_trial): ";
    cin >> max_trial;

    // 3. Xu ly nhap PIN (Dung vong lap for va break nhu tren bang)
    cout << "\n--- MOI BAN NHAP MA PIN ---\n";
    
    for (int i = 1; i <= max_trial; i++) {
        cout << "Lan nhap thu " << i << ": ";
        cin >> ma_nhap;

        // --- Doan nay tu tao ma dao nguoc de kiem tra bao mat ---
        // Kien thuc: Duyet chuoi nhu mang (array)
        string pin_nguoc = "";
        for (int j = 5; j >= 0; j--) { // Chay nguoc tu cuoi ve dau (vi PIN co 6 so)
            pin_nguoc = pin_nguoc + ma_pin_chuan[j];
        }

        // Kiem tra 1: Nhap ma dao nguoc -> Bao dong ngay
        if (ma_nhap == pin_nguoc) {
            cout << "!!! CANH BAO !!! Phat hien xam nhap trai phep." << endl;
            cout << "He thong se bi khoa vinh vien." << endl;
            return 0; // Ket thuc chuong trinh luon (Lenh return trong ham main)
        }

        // Kiem tra 2: Nhap dung -> Dung break de thoat vong lap
        if (ma_nhap == ma_pin_chuan) {
            check_login = true;
            break; // Kien thuc: Lenh break thoat khoi vong lap
        } 
        
        // Kiem tra 3: Nhap sai -> Bao loi
        else {
            cout << "Ma PIN sai!" << endl;
            // Neu day la lan cuoi cung thi bao khoa the
            if (i == max_trial) {
                cout << "Ban da nhap sai qua " << max_trial << " lan. KHOA THE!" << endl;
                return 0;
            }
        }
    }

    // 4. Xu ly rut tien (Chi chay khi da dang nhap dung)
    if (check_login == true) {
        cout << "\nDang nhap thanh cong!" << endl;
        cout << "Nhap so tien muon rut (a): ";
        cin >> a;

        if (a > A) {
            // Cau thong bao theo yeu cau de bai
            cout << "So tien rut lon hon so du kha dung. Ban bi ao tuong suc manh tai chinh a?" << endl;
        } else {
            // Tru tien
            A = A - a; // Cap nhat so du moi

            // In hoa don (Tham khao mau ngan hang)
            cout << "\n===================================" << endl;
            cout << "       NGAN HANG SINH VIEN         " << endl;
            cout << "        HOA DON RUT TIEN           " << endl;
            cout << "===================================" << endl;
            cout << "So tien rut:   " << a << " VND" << endl;
            cout << "So du con lai: " << A << " VND" << endl;
            cout << "Noi dung:      Rut tien tai ATM" << endl;
            cout << "===================================" << endl;
            cout << "Cam on quy khach!" << endl;
        }
    }

    return 0;
}