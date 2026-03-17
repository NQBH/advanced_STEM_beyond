#include <iostream>
#include <cmath>
using namespace std;

// BT1 midterm
void tong_hieu_tich_thuong(long long a, long long b) {
    long long tong = a + b, hieu = a - b, tich = a * b;
    cout << tong << " " << hieu << " " << tich << " ";
    if (!b) cout << "division by zero";
    else cout << a / b;
}

// BT2 midterm
void hcn(long long a, long long b) {
    if (a <= 0 || b <= 0) cout << "-1";
    else {
        long long chu_vi = (a + b) * 2;
        long long dien_tich = a * b;
        cout << chu_vi << " " << dien_tich;
    }
}

// BT3 midterm
void ptb1(long long a, long long b) {
    if (!a) {
        if (!b) cout << "infinity";
        else cout << 0;
    } else cout << 1;
}

// BT4 midterm
void ptb2(long long a, long long b, long long c) {
    if (!a) {
        if (!b) {
            if (!c) cout << "infinity";
            else cout << 0;
        } else cout << 1;
    } else {
        long long delta = b * b - 4 * a * c;
        if (delta > 0) cout << 2;
        else if (!delta) cout << 1;
        else cout << 0;
    }
}

// BT5 midterm
void count_even_odd(int n) {
    int a, even = 0, odd = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a & 1) ++odd;
        else ++even;
    }
    cout << even << ' ' << odd;
}

// BT6 midterm
void ptb2_thuc(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            cout << (c == 0 ? "Vo so nghiem.\n" : "Vo nghiem.\n");
        } else {
            cout << "x = " << -c / b << '\n';
        }
    } else {
        double Delta = b*b - 4*a*c;
        if (Delta < 0) {
            cout << "2 nghiem phuc: x1 = " << -b/(2*a) << " - i" << sqrt(-Delta)/(2*a)
                 << ", x2 = " << -b/(2*a) << " + i" << sqrt(-Delta)/(2*a) << '\n';
        } else if (Delta == 0) {
            cout << "Nghiem kep: x = " << -b/(2*a) << '\n';
        } else {
            cout << "2 nghiem thuc: x1 = " << (-b - sqrt(Delta))/(2*a)
                 << ", x2 = " << (-b + sqrt(Delta))/(2*a) << '\n';
        }
    }
}

// BT7 midterm
void tim_MaxMin(double a, double b, double c) {
    double maxVal = max(a, max(b, c));
    double minVal = min(a, min(b, c));
    cout << "Max = " << maxVal << ", Min = " << minVal << endl;
}

// BT8 midterm
void dem_so(int n) {
    int am = 0, duong = 0, zero = 0;
    for (int i = 1; i <= n; ++i) {
        double a;
        cin >> a; 
        if (a > 0) duong++;
        else if (a < 0) am++;
        else zero++;
    }
    cout << "Duong=" << duong << " Am=" << am << " Zero=" << zero << endl;
}

// BT9 midterm
void dem_so_cha_le(int n){
    int chan = 0, le = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) chan++;
        else le++;
    }
    cout << "Chan=" << chan << " Le=" << le << endl;
}

//BT10 midterm
void nhap_so_nguyen_xuat_tieng_anh(int n){
    int a;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        switch (a){
        case 0:  cout << "zero";  break;
        case 1:  cout << "one";   break;
        case 2:  cout << "two";   break;
        case 3:  cout << "three"; break;
        case 4:  cout << "four";  break;
        case 5:  cout << "five";  break;
        case 6:  cout << "six";   break;
        case 7:  cout << "seven"; break;
        case 8:  cout << "eight"; break;
        case 9:  cout << "nine";  break;
        case 10: cout << "ten";   break;
        case 11: cout << "eleven"; break;
        case 12: cout << "twelve"; break;
        case 13: cout << "thirteen"; break;
        case 14: cout << "fourteen"; break;
        case 15: cout << "fifteen";  break;
        case 16: cout << "sixteen";  break;
        case 17: cout << "seventeen"; break;
        case 18: cout << "eighteen";  break;
        case 19: cout << "nineteen";  break;
        case 20: cout << "twenty";    break;
        }
        cout << endl;
    }
}

// BT11 midterm
void giaiHePT(double a, double b, double c, double A, double B, double C) {
    double D  = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D != 0) {
        cout << "He co nghiem duy nhat: x = " << Dx / D 
             << ", y = " << Dy / D << endl;
    } else if (Dx == 0 && Dy == 0) {
        cout << "He co vo so nghiem (VSN)" << endl;
    } else {
        cout << "He vo nghiem (VN)" << endl;
    }
}

//BT12 midterm
void giaiptinh_Sm(int m, int n){
    double Sm = 0;
    for (int i = 1; i <= n; ++i) Sm += pow(i, m);
    cout << "Sm = " << Sm << '\n';
}

//BT13 midterm
void tinhTong(int m, double M) {
    double Sm = 0, term = 1;
    int i = 1;
    while (Sm + term <= M) {
        Sm += term;
        term = pow(++i, m);
    }
    cout << "Sm = " << Sm << '\n';
}

//BT14 midterm
void rutTien(double A, double a, const string& real_password, int max_trial) {
    if (a > A) {
        cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?\n";
        return;
    }

    string input_password;
    bool ok = false;
    for (int i = 1; i <= max_trial; ++i) {
        cin >> input_password;
        if (input_password == real_password) {
            ok = true;
            break;
        }
    }

    if (ok) cout << "Mã PIN đúng. Cho rút tiền.\n";
    else cout << "Bạn đã bị khóa thẻ.\n";
}

int main() {
    long long a, b, c;
    int n, m;

    // BT1
    cin >> a >> b;
    tong_hieu_tich_thuong(a, b);

    // BT2
    cin >> a >> b;
    hcn(a, b);

    // BT3
    cin >> a >> b;
    ptb1(a, b);

    // BT4
    cin >> a >> b >> c;
    ptb2(a, b, c);

    // BT5
    cin >> n;
    count_even_odd(n);

    // BT6
    double da, db, dc;
    cin >> da >> db >> dc;
    ptb2_thuc(da, db, dc);

    // BT7
    cin >> da >> db >> dc;
    tim_MaxMin(da, db, dc);

    // BT8
    cout << "Nhap n (so luong so thuc): ";
    cin >> n;
    dem_so(n);

    // BT9
    cout << "Nhap n (so luong so nguyen): ";
    cin >> n;
    dem_so_cha_le(n);

    // BT10
    cout << "Nhap n: ";
    cin >> n;
    nhap_so_nguyen_xuat_tieng_anh(n);

    // BT11
    double A1, B1, C1, A2, B2, C2;
    cout << "Nhap he so cua pt1: ";
    cin >> A1 >> B1 >> C1;
    cout << "Nhap he so cua pt2: ";
    cin >> A2 >> B2 >> C2;
    giaiHePT(A1, B1, C1, A2, B2, C2);

    // BT12
    cout << "Nhap m va n: ";
    cin >> m >> n;
    giaiptinh_Sm(m, n);

    // BT13
    double M;
    cout << "Enter m, M = ";
    cin >> m >> M;
    tinhTong(m, M);

    // BT14
    double A, a_rut;
    string real_password;
    int max_trial;
    cout << "Nhap so du va so tien muon rut: ";
    cin >> A >> a_rut;
    cout << "Nhap mat khau that va so lan thu toi da: ";
    cin >> real_password >> max_trial;
    rutTien(A, a_rut, real_password, max_trial);

    return 0;
}