#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

//  BT1, 2, 3
void hinh_hoc(ll a, ll b = 0, ll c = 0, int mode = 1) {
    if (mode == 1) { // Hình vuông
        cout << "Chu vi HV: " << a * 4 << ", Dien tich HV: " << a * a << endl;
    } else if (mode == 2) { // Hình chữ nhật
        cout << "Chu vi HCN: " << (a + b) * 2 << ", Dien tich HCN: " << a * b
             << ", Duong cheo: " << sqrt(a * a + b * b) << endl;
    } else if (mode == 3) { // Hình hộp / Lập phương
        if (a <= 0 || b <= 0 || c <= 0) { cout << "Canh khong hop le!" << endl; return; }
        if (a == b && b == c) cout << "Day la Hinh Lap Phuong (HLP)" << endl;
        else {
            ll xq = (a + b) * 2 * c;
            ll tp = xq + 2 * a * b;
            cout << "S xq: " << xq << ", S tp: " << tp
                 << ", Duong cheo: " << sqrt(a * a + b * b + c * c)
                 << ", The tich: " << a * b * c << endl;
        }
    }
}

//  BT5, 6
void phuong_trinh(ll a, ll b, ll c = 0, bool bac2 = false) {
    if (!bac2) { // Bậc 1: ax + b = 0
        cout << "PT Bac 1: ";
        if (a) cout << "x = " << (double) - b / a << endl;
        else cout << (b == 0 ? "Vo so nghiem" : "Vo nghiem") << endl;
    } else { // Bậc 2: ax^2 + bx + c = 0
        cout << "PT Bac 2: ";
        if (!a) phuong_trinh(b, c);
        else {
            ll d = b * b - 4 * a * c;
            if (d < 0) cout << "Vo nghiem" << endl;
            else if (d == 0) cout << "Nghiem kep x = " << (double) - b / (2 * a) << endl;
            else cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << ", x2 = " << (-b - sqrt(d)) / (2 * a) << endl;
        }
    }
}

// BT7, 8, 9
void thong_ke(int n) {
    if (n <= 0) return;
    ll x, mi, ma, duong = 0, am = 0, zero = 0, chan = 0, le = 0;
    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i == 0) mi = ma = x;
        else { ma = max(ma, x); mi = min(mi, x); }
        if (x > 0) duong++; else if (x < 0) am++; else zero++;
        if (x % 2 == 0) chan++; else le++;
    }
    cout << "--- Ket qua thong ke ---" << endl;
    cout << "Max/Min: " << ma << " / " << mi << endl;
    cout << "Duong/Am/Zero: " << duong << " / " << am << " / " << zero << endl;
    cout << "Chan/Le: " << chan << " / " << le << endl;
}

//  BT10
void doc_so_bang_tieng_anh(int n) {
    string numbers[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"
                       };
    for (int i = 0; i <= n; i++) {
        cout << i << " -> ";
        if (i <= 20) cout << numbers[i] << endl;
        else cout << "So nay lon qua, chua co ket qua!" << endl;
    }
}

//  BT12, 13
void tinh_tong_luy_thua(int n, int m) {
    double tong = 0;
    for (int i = 1; i <= n; i++) tong += pow(i, m);
    cout << "Tong S(" << n << "^" << m << ") = " << tong << endl;
}

void tim_n_lon_nhat(double m, double M) {
    double S = 0; int n = 0;
    for (int i = 1; ; i++) {
        double next_val = pow(i, m);
        if (S + next_val > M) break;
        S += next_val;
        n = i;
    }
    if (n == 0) cout << "Khong co gia tri n nao thoa man." << endl;
    else cout << "n lon nhat de S <= " << M << " la: " << n << " (Tong S = " << S << ")" << endl;
}

//  BT14
void mo_phong_atm() {
    double balance, amount;
    string pin_real = "123456", pin_input;
    int max_trial, count = 0;

    cout << "\n--- ATM SIMULATOR ---" << endl;
    cout << "Nhap so du ban dau: "; cin >> balance;
    cout << "Nhap so lan thu PIN toi da: "; cin >> max_trial;

    string pin_reverse = pin_real;
    reverse(pin_reverse.begin(), pin_reverse.end());

    while (count < max_trial) {
        cout << "Nhap ma PIN: "; cin >> pin_input;
        if (pin_input == pin_reverse) {
            cout << "!!! CANH BAO !!! Ban nhap ma nguoc. Cam truy cap!" << endl;
            return;
        }
        if (pin_input == pin_real) {
            cout << "Dang nhap thanh cong!" << endl;
            break;
        } else {
            count++;
            cout << "Sai PIN. Con lai " << max_trial - count << " lan." << endl;
        }
        if (count == max_trial) { cout << "KHOA THE!" << endl; return; }
    }

    cout << "Nhap so tien muon rut: "; cin >> amount;
    if (amount > balance) cout << "So du khong du!" << endl;
    else {
        balance -= amount;
        cout << "Thanh cong. So du con lai: " << balance << " VND" << endl;
    }
}


int main() {
    // 1.
    cout << "--- BT Hinh hoc ---" << endl;
    hinh_hoc(5, 0, 0, 1); // HV canh 5
    hinh_hoc(4, 5, 0, 2); // HCN 4x5

    // 2.
    cout << "\n--- BT Phuong trinh ---" << endl;
    phuong_trinh(2, -4);        // 2x - 4 = 0
    phuong_trinh(1, -3, 2, true); // x^2 - 3x + 2 = 0

    // 3.
    cout << "\n--- đoc so & Luy thua ---" << endl;
    doc_so_bang_tieng_anh(3);
    tinh_tong_luy_thua(3, 2);
    tim_n_lon_nhat(2, 20);

    // 4.
    thong_ke(5);
    mo_phong_atm();

    return 0;
}