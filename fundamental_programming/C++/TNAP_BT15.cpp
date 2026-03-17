#include <bits/stdc++.h>
using namespace std ;
void baitap1 (double a ) {
    cout << "hinh vuong" << endl;
    cout << "CV " << a * 4 << " " << "DT " << a * a << endl;
}

void baitap2 (double a , double b) {
    cout << "Hinh chu nhat" << endl;
    cout << "CV " << (a + b) * 2 << " " << "DT " << a * b << endl ;
}
void baitap3 (double a, double b, double c) {
    if ( a == b && b == c) {
        cout << "HLP" << endl;
    }
    else {
        cout << "HHCN" << endl;
        float Sxp = 2 * (a + b) * c;
        float Stp = 2 * (a * b + c * a + b * c);
        float TheTich =  a * b * c;
        double DuongCheo = sqrt(a * a + b * b + c * c);
        cout << "Sxq " << Sxp << " " << "Stp " << Stp << " " << "The Tich " << TheTich << " " << "Duong cheo " << DuongCheo << endl;
    }
}
void baitap4(double x, double y, double A, double B, double C) {
    // sqrt
    if (x >= 0) cout << sqrt(x) << "\n";
    else cout << "Error\n";
    // pow
    if (x > 0) cout << pow(x, y) << "\n";
    else cout << "Error\n";
    // log
    if (x > 0) {
        cout << log(x) << "\n";
        cout << log10(x) << "\n";
    } else {
        cout << "Error\nError\n";
    }
    // abs
    cout << abs(A) << "\n";
    cout << llabs(B) << "\n";
    cout << fabs(C) << "\n";
    // lượng giác (x tính theo radian)
    cout << cos(x) << "\n";
    cout << sin(x) << "\n";
    if (tan(x) != 0)
        cout << tan(x) << "\n" << 1.0 / tan(x) << "\n";
    else
        cout << "Error\nError\n";

    if (x >= -1 && x <= 1) {
        cout << acos(x) << "\n";
        cout << asin(x) << "\n";
    } else {
        cout << "Error\nError\n";
    }
    cout << atan(x) << "\n";
    cout << floor(x) << "\n";
    cout << ceil(x) << "\n";
}
void baitap5(double a, double b) {
    if (a == 0) {
        if (b == 0) cout << "Vo so nghiem.\n";
        else cout << "Vo nghiem.\n";
    } else {
        if (b == 0) cout << "x = 0.\n";
        else cout << "x = " << - b / a << "\n";
    }
}
void baitap6(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Vo so nghiem.\n";
            else cout << "Vo nghiem.\n";
        } else {
            if (c == 0) cout << "x = 0.\n";
            else cout << "x = " << - c / b << "\n";
        }
    } else {
        double Delta = b * b - 4 * a * c;
        if (Delta < 0) {
            cout << "Phuong trinh co 2 nghiem phuc x1 = " << -b / (2 * a) << " - i" << sqrt(fabs(Delta)) / (2 * a) << " & ";
            cout << "x2 = " << -b / (2 * a) << " + i" << sqrt(fabs(Delta)) / (2 * a) << '\n';
        } else if (Delta == 0) {
            cout << "Phuong trinh co nghiem kep x = " << -b / (2 * a) << '\n';
        } else {
            cout << "Phuong trinh co 2 nghiem thuc x1 = " << (-b - sqrt(Delta)) / (2 * a) << " & x2 = " << (-b + sqrt(Delta)) / (2 * a) << '\n';
        }
    }
}
void baitap7(double a, double b, double c) {
    double maxVal = max({a, b, c});
    double minVal = min({a, b, c});

    cout << "Max " << maxVal << "\n";
    cout << "Min " << minVal << "\n";
}
void baitap8(int n) {
    if (n <= 0) {
        cout << "Error: n phai > 0\n";
        return;
    }
    int demduong = 0, demam = 0, demkhong = 0;
    double val;

    for (int i = 1; i <= n; i++) {
        cin >> val;

        if (val > 0) demduong++;
        else if (val < 0) demam++;
        else demkhong++;
    }

    cout << "So duong: " << demduong << "\n";
    cout << "So am: " << demam << "\n";
    cout << "So bang 0: " << demkhong << "\n";
}
void baitap9(int n) {
    if (n <= 0) {
        cout << "n phai la so nguyen duong\n";
        return;
    }
    int demChan = 0, demLe = 0;
    int so;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> so;
        if (so % 2 == 0)
            demChan++;
        else
            demLe++;
    }
    cout << "So chan co " << demChan << "\n";
    cout << "So le co " << demLe << "\n";
}
void baitap10(int n) {
    string str;

    switch (n)
    {
    case 0 : str = "Zero"; break;
    case 1 : str = "One"; break;
    case 2 : str = "Two"; break;
    case 3 : str = "Three"; break;
    case 4 : str = "Four"; break;
    case 5 : str = "Five"; break;
    case 6 : str = "Six"; break;
    case 7 : str = "Seven"; break;
    case 8 : str = "Eight"; break;
    case 9 : str = "Nine"; break;
    case 10 : str = "Ten"; break;
    case 11 : str = "Eleven"; break;
    case 12 : str = "Twelve"; break;
    case 13 : str = "Thirteen"; break;
    case 14 : str = "Fourteen"; break;
    case 15 : str = "Fifteen"; break;
    case 16 : str = "Sixteen"; break;
    case 17 : str = "Seventeen"; break;
    case 18 : str = "Eighteen"; break;
    case 19 : str = "Nineteen"; break;
    case 20 : str = "Twenty"; break;
    default:
        if (n < 0) str = "Negative";
        else str = "Greater than twenty";
    }

    cout << "Result: " << str << "\n";
}
void baitap11(double a, double b, double c, double A, double B, double C) {
    double D  = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;
    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He co nghiem duy nhat:\n";
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    else if (Dx != 0 || Dy != 0) {
        cout << "He vo nghiem.\n";
    }
    else {
        cout << "He vo so nghiem.\n";
    }
}
void baitap12 (int n , int m) {
    double sum = 0;
    for ( int i = 1; i <= n; i++) {
        sum  += pow(i, m);
    } cout << "Tong Sm " << sum << '.\n';
}
void baitap13(int n, int m, int M) {
    double Sm = 0;
    int i = 1;
    double term = pow(i, m);
    while (Sm + term <= M) {
        Sm += term;
        i++;
        term = pow(i, m);
    }

    cout << Sm << '\n';
}
void baitap14(double A, double a) {
    string maPIN_dung, maPIN_nhap;
    int soLanThuToiDa;

    cout << "Nhap ma PIN dung: ";
    cin >> maPIN_dung;

    cout << "Nhap so lan thu toi da: ";
    cin >> soLanThuToiDa;

    bool dangNhapThanhCong = false;

    for (int i = 1; i <= soLanThuToiDa; i++) {
        cout << "Nhap ma PIN: ";
        cin >> maPIN_nhap;

        if (maPIN_nhap == maPIN_dung) {
            dangNhapThanhCong = true;
            break;
        } else {
            cout << "Sai ma PIN.\n";
        }
    }

    if (!dangNhapThanhCong) {
        cout << "Ban da bi khoa the.\n";
        return;
    }

    cout << "Ma PIN dung. Nhap so tien muon rut: ";
    cin >> a;

    if (a > A) {
        cout << "So du khong du.\n";
    }
    else {
        cout << "Rut tien thanh cong: " << a << " VND\n";
        cout << "So du con lai: " << A - a << " VND\n";

        string inHoaDon;
        cout << "Ban co muon in hoa don? (Yes/No): ";
        cin >> inHoaDon;

        if (inHoaDon == "Yes")
            cout << "Dang in hoa don...\n";

        cout << "Giao dich hoan tat.\n";
    }
}

int main() {
    double a, b, c, x, y, A, B, C; int n, m, M; cin >> a >>  b >> c >> x >> y >> A >> B >> C >> n >> m >> M;
    baitap1 (a);
    baitap2 (a, b);
    baitap3 (a, b, c);
    baitap4 (x, y, A, B, C);
    baitap5(a, b);
    baitap6(a, b, c);
    baitap7(a, b, c);
    baitap8(n);
    baitap9(n);
    baitap10(n);
    baitap11(a, b, c, A, B, C);
    baitap12(n, m);
    baitap13(n, m, M);
    baitap14(A, a);
    return 0 ;
}