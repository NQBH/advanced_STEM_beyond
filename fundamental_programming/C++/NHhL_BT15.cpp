#include <bits/stdc++.h>
using namespace std;

void BT1(int canh) {
    int ChuVi = canh * 4;
    cout << " Chu Vi Hình Vuông Cạnh " << canh << " bằng " << ChuVi << '\n';
    int DienTich = pow(canh, 2);
    cout << " Diện Tích Hình Vuông Cạnh " << canh << " bằng " << DienTich << '\n';
}

void BT2(double dai, double rong) {
    double ChuVi = (dai + rong) * 2;
    cout << " Chu Vi Hình Chữ Nhật Bằng " << ChuVi << '\n';
    double DienTich = dai * rong;
    cout << " Diện Tích Hình Chữ Nhật Bằng " << DienTich << '\n';
    double DuongCheo = sqrt(pow(dai, 2) + pow(rong, 2));
    cout << " Độ Dài Đường Chéo Bằng " << DuongCheo << '\n';
}

void BT3(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1 << '\n';
    } else {
        if (a == b && b == c) {
            cout << "HLP\n";
            double Sxq = 4 * pow(a, 2);
            cout << " Diện Tích xung quanh = " << Sxq << '\n';

            double Sxp = 6 * pow(a, 2);
            cout << " Diện Tích toàn phần = " << Sxp << '\n';

            double TheTich = pow(a, 3);
            cout << " Thể Tích = " << TheTich << '\n';
        } else {
            cout << "HHCN\n";
            double Sxq = 2 * (a + b) * c;
            cout << " Diện Tích xung quanh = " << Sxq << '\n';

            double Sxp = 2 * (a * b + b * c + c * a);
            cout << " Diện Tích toàn phần = " << Sxp << '\n';

            double TheTich = (double)a * b * c;
            cout << " Thể Tích = " << TheTich << '\n';
        }
    }
}

void BT4(double x, double y) {
    cout << "1. sqrt(" << x << ") = " << (x < 0 ? -1 : sqrt(x)) << '\n';
    cout << "2. pow(" << x << ", " << y << ") = " << pow(x, y) << '\n';
}

void BT5(double a, double b) {
    if (a == 0) {
        if (b == 0) cout << "Vô Số Nghiệm\n";
        else cout << "Vô Nghiệm\n";
    } else cout << "x = " << -b / a << '\n';
}

void BT6(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Giải Pháp Vô hạn\n";
            else cout << "Không Giải Pháp \n";
        } else cout << "x = " << -c / b << '\n';
    } else {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << "\nx2 = " << (-b - sqrt(delta)) / (2 * a) << '\n';
        } else if (delta == 0) cout << "Nghiệm Kép: x = " << -b / (2 * a) << '\n';
        else cout << "Nghiệm Phức (delta < 0)\n";
    }
}

void BT7(int n) {
    double val, maxN, minN;
    cout << "Nhập số: "; cin >> val;
    maxN = val; minN = val;
    for (int i = 2; i <= n; i++) {
        cout << "Nhập số " << i << ": "; cin >> val;
        if (val > maxN) maxN = val;
        if (val < minN) minN = val;
    }
    cout << "Max: " << maxN << "\nMin: " << minN << endl;
}

void BT8(int n) {
    int demduong = 0, demam = 0, dekhong = 0;
    double val;
    for (int i = 1; i <= n; i++) {
        cout << "Nhập số " << i << ": "; cin >> val;
        if (val > 0) demduong++;
        else if (val < 0) demam++;
        else dekhong++;
    }
    cout << "Số Dương: " << demduong << "\n Số Âm: " << demam << "\nSố 0: " << dekhong << endl;
}

void BT9(int n) {
    int a, demChan = 0, demLe = 0;
    for (int i = 1; i <= n; i++) {
        cout << "Nhập Số " << i << ": "; cin >> a;
        if (a % 2 == 0) demChan++;
        else demLe++;
    }
    cout << "Số Chẵn: " << demChan << "\nSố Lẻ: " << demLe << endl;
}

void BT10(int n) {
    string str;
    switch (n) {
    case 0: str = "Zero"; break; case 1: str = "One"; break; case 2: str = "Two"; break;
    case 3: str = "Three"; break; case 4: str = "Four"; break; case 5: str = "Five"; break;
    case 6: str = "Six"; break; case 7: str = "Seven"; break; case 8: str = "Eight"; break;
    case 9: str = "Nine"; break; case 10: str = "Ten"; break;
    default: str = (n < 0) ? "Negative" : "Greater than ten";
    }
    cout << "Result: " << str << '\n';
}

void BT11(double a, double b, double c, double A, double B, double C) {
    double D  = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;
    if (D != 0) cout << "Nghiệm Duy nhất: \n x = " << Dx / D << "\n y = " << Dy / D << "\n";
    else if (Dx != 0 || Dy != 0) cout << "Hệ Vô Nghiệm.\n";
    else cout << "Hệ Số vô Nghiệm.\n";
}

void BT12(int n, int m) {
    double tong = 0;
    for (int i = 1; i <= n; ++i) {
        tong += pow(i, m);
    }
    cout << "Tổng Sm = " << tong << '\n';
}

void BT13(int n, int m, double M) {
    double tong = 0;
    for (int i = 1; i <= n; ++i) {
        double sohang = pow(i, m);
        if (tong + sohang > M) {
            break;
        }
        tong += sohang;
    }
    cout << "Tổng Sm Lớn Nhất (<= " << M << ") là: " << tong << endl;
}
void BT14(long long A, int max_lan) {
    string PINnhap;
    int count = 0; bool bikhoa = false;
    while (count < max_lan) {
        cout << "vui Lòng Nhập Mã PIN: "; cin >> PINnhap;
        if (PINnhap == "123456") break;
        if (PINnhap == "654321") {
            cout << "Phát hiện nhập mã ngược PIN. Hệ Thống Khóa!\n";
            bikhoa = true; break;
        }
        count++; cout << "Mã PIN Sai! Bạn Còn " << (max_lan - count) << " Lần Thứ.\n";
    }
    if (bikhoa || count >= max_lan) {
        cout << "THẺ ĐÃ BỊ KHÓA.\n"; return;
    }
    long long a;
    cout << "Đang Nhập Thành Công. Số Dư: " << A << "\nNhập Số tiền muốn rút: "; cin >> a;
    if (a > A) cout << "Số tiền lớn hơn số dư!\n";
    else cout << "Rút Thành Công! Số Dư Còn: " << A - a << " VND\n";
}

int main() {

    int n, m, x_int;
    double a, b, c, A, B, C;
    double gioi_han_M;
    long long so_du;


    cout << "~Bài tập 1~\nNhập Cạnh hình Vuông: ";
    cin >> n;
    BT1(n);

    cout << "\n~Bài tập 2~\nNhập chiều dài, rộng: ";
    cin >> a >> b;
    BT2(a, b);

    cout << "\n~Bài tập 3~\nNhập 3 cạnh a, b, c: ";
    cin >> x_int >> n >> m;
    BT3(x_int, n, m);

    cout << "\n~Bài tập 4~\nNhập X, Y (để tính mũ): ";
    cin >> a >> b;
    BT4(a, b);

    cout << "\n~Bài tập 5~\nNhập a, b (PT bậc 1): ";
    cin >> a >> b;
    BT5(a, b);

    cout << "\n~Bài tập 6~\nNhập a, b, c (PT bậc 2): ";
    cin >> a >> b >> c;
    BT6(a, b, c);

    cout << "\n~Bài tập 7,8,9~\nNhập số lượng N: ";
    cin >> n;
    if (n > 0) {
        cout << "- BT7:\n"; BT7(n);
        cout << "- BT8:\n"; BT8(n);
        cout << "- BT9:\n"; BT9(n);
    }

    cout << "\n~Bài tập 10~\nNhap n (tu 0-20): ";
    cin >> n;
    BT10(n);

    cout << "\n~Bài tập 11~\nNhập a, b, c (PT1): ";
    cin >> a >> b >> c;
    cout << "Nhap A, B, C (PT2): ";
    cin >> A >> B >> C;
    BT11(a, b, c, A, B, C);

    cout << "\n~Bài tập 12 & 13~\nNhập N (số pt) va m (số mũ): ";
    cin >> n >> m;
    BT12(n, m);

    cout << "Nhập giới Hạn tổng M: ";
    cin >> gioi_han_M;
    BT13(n, m, gioi_han_M);

    cout << "\n~Bài tập 14 (NOVA BANK)~\nNhập số dư ban đầu: ";
    cin >> so_du;
    cout << "Nhập Số lần sai PIN tối đa: ";
    cin >> n;
    BT14(so_du, n);

    return 0;
}