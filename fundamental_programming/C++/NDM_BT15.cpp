#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//bt1 midterm
void tinh_chuvi_dientich_hinhvuong(float a) {
    cout << a + a + a + a << '\n'; // Chu vi hinh vuong
    cout << a * a << '\n'; // Dien tich hinh vuong
}

//BT2 midterm
void tinh_chuvi_dientich_hinhchu_nhat(float d, float r) {
    if (d <= 0 || r <= 0) cout << "Wrong input.\n";
    else {
        float P2 = 2 * (d + r), S2 = d * r, Duongcheo = sqrt(d * d + r * r);
        cout << P2 << '\n'; // Chu vi hinh chu nhat
        cout << S2 << '\n'; // Dien tich hinh chu nhat
        cout << Duongcheo << '\n'; // Duong cheo hinh chu nhat
    }

}

//BT3 midterm
void kiemtra_HLP_va_HHCP(float a1, float b1, float c1) {

    if (a1 == b1 && b1 == c1 && a1 > 0) { // xac dinh hinh HLP
        cout << "HLP" << '\n';
        float Sxq = 4 * a1 * a1, Stp = 6 * a1 * a1, V = a1 * a1 * a1, d = sqrt(3 * a1 * a1);
        cout << "Dien tich xung quanh hinh lap phuong:" << Sxq << '\n';
        cout << "Dien tich toan phan hinh lap phuong:" << Stp << '\n';
        cout << "The tich hinh lap phuong:" << V << '\n';
        cout << "Dien tich mat phang hinh lap phuong:" << a1 * a1 << '\n';
        cout << "Duong cheo hinh lap phuong:" << d << '\n';
    }
    else if (a1 > 0 && b1 > 0 && c1 > 0) {
        cout << "HHCN" << '\n'; // Khong phai HLP => HHCN

        float Sxq = (a1 + b1) * 2 * c1;
        float Stp = Sxq + (a1 * b1) * 2;
        float V = a1 * b1 * c1;
        float duongcheohhcn = sqrt(a1 * a1 + b1 * b1 + c1 * c1);

        cout << Sxq << '\n'; // Dien tich xung quanh hinh hop chu nhat
        cout << Stp << '\n'; // Dien tich toan phan hinh hop chu nhat
        cout << V << '\n'; // The tich hinh hop chu nhat
        cout << duongcheohhcn << '\n'; // Duong cheo hinh hop chu nhat
    }
    else { // khong phai hinh hop chu nhat
        cout << -1 << '\n';
    }

}

//BT4 midterm
void ham_y_nghia(double x, double y) {

    if (x < 0) cout << "sqrt ERROR: x must be nonnegative" << endl;
    else cout << "sqrt(x) = " << sqrt(x) << '\n';

    cout << "pow = " << pow(x, y) << '\n';
    cout << "e^x = " << exp(x) << '\n';

    if (x <= 0) cout << "log ERROR: x must be > 0" << endl;
    else {
        cout << "ln x = " << log(x) << '\n';
        cout << "log10 x = " << log10(x) << '\n';
    }

    cout << "abs x = " << abs(x) << '\n';
    cout << "fabs x = " << fabs(x) << '\n';
    cout << "cos x = " << cos(x) << '\n';
    cout << "tan x = " << tan(x) << '\n';
    cout << "cot x = " << 1 / tan(x) << '\n';
    cout << "sin x = " << sin(x) << '\n';

    if (x < -1 || x > 1) cout << "acos, asin ERROR: x must be in [-1, 1]" << '\n';
    else {
        cout << "acos x = " << acos(x) << '\n';
        cout << "asin x = " << asin(x) << '\n';
    }

    cout << "atan x = " << atan(x) << '\n';
    cout << "floor x = " << floor(x) << '\n';
    cout << "ceil x = " << ceil(x) << '\n';

}

//BT5 midterm
void ptb1 (double a2, double b2) {

    if (a2 == 0 && b2 == 0) {
        cout << "Phuong trinh vo so nghiem";
    }
    else if (a2 == 0 && b2 != 0) {
        cout << "Phuong trinh vo nghiem";
    }
    else {
        cout << "Nghiem x = " << -b2 / a2   << '\n';
    }

}

//BT6 midterm
void ptb2 (double a4, double b4, double c4) {

    cout << "Phuong trinh: " << a4 << "x^2 + " << b4 << "x + " << c4 << " = 0\n";

    if (a4 == 0) {
        if (b4 == 0) {
            if (c4 == 0)
                cout << "Phuong trinh vo so nghiem";
            else
                cout << "Phuong trinh vo nghiem";
        } else {
            cout << "Phuong trinh co mot nghiem: x = " << -c4 / b4;
        }
        return;
    }


    double delta = b4 * b4 - 4 * a4 * c4;

    if (delta > 0) {
        cout << "Phuong trinh co hai nghiem phan biet\n";
        cout << "x1 = " << (-b4 + sqrt(delta)) / (2 * a4) << endl;
        cout << "x2 = " << (-b4 - sqrt(delta)) / (2 * a4) << endl;
    }
    else if (delta == 0) {
        cout << "Phuong trinh co nghiem kep\n";
        cout << "x = " << -b4 / (2 * a4);
    }
    else {
        double thuc = -b4 / (2 * a4);
        double ao = sqrt(-delta) / (2 * a4);

        cout << "Phuong trinh co hai nghiem phuc\n";
        cout << "x1 = " << thuc << " + " << ao << "i\n";
        cout << "x2 = " << thuc << " - " << ao << "i\n";
    }
}

//BT7 midterm
void vmax_vmin(double a5, double b5, double c5) {
    double vmax;
    if (a5 >= b5 && a5 >= c5) {
        vmax = a5;
    } else if (b5 >= a5 && b5 >= c5) {
        vmax = b5;
    } else {
        vmax = c5;
    }

    double vmin;
    if (a5 <= b5 && a5 <= c5) {
        vmin = a5;
    } else if (b5 <= a5 && b5 <= c5) {
        vmin = b5;
    } else {
        vmin = c5;
    }

    cout << "Max: " << vmax << '\n';
    cout << "Min: " << vmin << '\n';

}

//BT8 midterm
void dem_so_duong_am_khong(int n) {
    int demduong = 0, demam = 0, demkhong = 0;
    double val;

    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> val;
        if (val > 0) {
            demduong++;
        }
        else if (val < 0) {
            demam++;
        }
        else {
            demkhong++;
        }
    }
    cout << "So luong so duong: " << demduong << '\n';
    cout << "So luong so am: " << demam << '\n';
    cout << "So luong so khong: " << demkhong << '\n';
}

//BT9 midterm
void dem_chan_le(int n2) {
    int demchan = 0, demle = 0;
    for (int i = 1; i <= n2; i++) {
        int val2;
        cout << "Nhap so thu " << i << ": ";
        cin >> val2;
        if (val2 % 2 == 0) {
            demchan++;
        } else {
            demle++;
        }

    }
    cout << "So luong so chan: " << demchan << '\n';
    cout << "So luong so le: " << demle << '\n';
}

//BT10 midterm
void so_chu(int n3) {
    switch (n3) {
    case 0: cout << "Zero"; break;
    case 1: cout << "One"; break;
    case 2: cout << "Two"; break;
    case 3: cout << "Three"; break;
    case 4: cout << "Four"; break;
    case 5: cout << "Five"; break;
    case 6: cout << "Six"; break;
    case 7: cout << "Seven"; break;
    case 8: cout << "Eight"; break;
    case 9: cout << "Nine"; break;
    case 10: cout << "Ten"; break;
    case 11: cout << "Eleven"; break;
    case 12: cout << "Twelve"; break;
    case 13: cout << "Thirteen"; break;
    case 14: cout << "Fourteen"; break;
    case 15: cout << "Fifteen"; break;
    case 16: cout << "Sixteen"; break;
    case 17: cout << "Seventeen"; break;
    case 18: cout << "Eighteen"; break;
    case 19: cout << "Nineteen"; break;
    case 20: cout << "Twenty"; break;
    default: cout << "Number out of range"; break;
    }
}

//BT11 midterm
void hpt(double a6, double b6, double c6, double A, double B, double C) {

    cout << "Giai he pt:\n ax + by = c\n Ax + By = C\n";
    cout << "___________________________\n";

    cout << "Xac nhan:" << "a = " << a6 << ", b = " << b6 << ", c = " << c6 << endl;
    cout << "Xac nhan:" << "A = " << A << ", B = " << B << ", C = " << C << endl;

    double D  = a6 * B - A * b6;
    double Dx = c6 * B - C * b6;
    double Dy = a6 * C - A * c6;

    cout << "___________________________\n";
    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He phuong trinh co 1 nghiem duy nhat:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    else {
        if (Dx != 0 || Dy != 0) {
            cout << "He phuong trinh vo nghiem" << endl;
        }
        else {
            cout << "He phuong trinh vo so nghiem" << endl;
        }
    }
}
//BT12 midterm
void s_sm (int n4, int m4) {
    double S = 0;
    for (int i = 1; i <= n4; ++i) S += pow(i, m4);

    cout << "S = " << S << endl;
}

//BT13 midterm
void s_sm_while (int n5, int m5, long long M) {
    long long lSm = 0;
    double S1 = 0;
    int i = 1;

    while (i <= n5) {
        if (S1 + pow(i, m5) > M) {
            break;
        }

        S1 += pow(i, m5);
        ++i;
    }

    cout << "S = " << S1 << endl;

    i = 1;
    while (lSm <= M) {
        lSm += pow(i, m5);
        ++i;
    }
    cout << "Sm = " << lSm << endl;
}

//BT14 midterm
void atm (long long A2, long long a7, int max_trial, string TruePIN) {
    string inputPIN;
    int trial = 0;

    while (trial < max_trial) {
        cout << "Nhap ma PIN (6 chu so): ";
        cin >> inputPIN;

        string reversedPIN = TruePIN;
        reverse(reversedPIN.begin(), reversedPIN.end());

        if (inputPIN == reversedPIN) {
            cout << "SECURITY ALERT!\n";
            cout << "Phat hien nhap PIN nguoc. The bi khoa!\n";
            return;
        }

        if (inputPIN == TruePIN) {
            if (a7 > A2) {
                cout << "So tien rut lon hon so du kha dung.\n";
                cout << "Ban bi ao tuong suc manh tai chinh a?\n";
            }
            else {
                A2 -= a7;
                cout << "\n===== HOA DON ATM =====\n";
                cout << "So tien da rut: " << a7 << " VND\n";
                cout << "So du con lai: " << A2 << " VND\n";
                cout << "Cam on ban da su dung dich vu!\n";
                cout << "=======================\n";
                return;
            }
        }
        else {
            trial++;
            cout << "Ma PIN sai! Con " << (max_trial - trial) << " lan thu.\n";
        }
    }

    cout << "Ban da nhap sai qua so lan quy dinh. Tai khoan da bi khoa.\n";
}

int main() {
    //BT1 midterm
    float a;
    cin >> a;
    tinh_chuvi_dientich_hinhvuong(a);

    //BT2 midterm
    float d, r;
    cin >> d >> r;
    tinh_chuvi_dientich_hinhchu_nhat(d, r);

    //BT3 midterm
    float a1, b1, c1;
    cin >> a1 >> b1 >> c1;
    kiemtra_HLP_va_HHCP(a1, b1, c1);

    //BT4 midterm
    double x, y;
    cin >> x >> y;
    ham_y_nghia(x, y);

    //BT5 midterm
    double a2, b2;
    cin >> a2 >> b2;
    ptb1(a2, b2);

    //BT6 midterm
    double a4, b4, c4;
    cin >> a4 >> b4 >> c4;
    ptb2(a4, b4, c4);

    //BT7 midterm
    double a5, b5, c5;
    cin >> a5 >> b5 >> c5;
    vmax_vmin(a5, b5, c5);

    //BT8 midterm
    int n;
    cin >> n;
    dem_so_duong_am_khong(n);

    //BT9 midterm
    int n2;
    cin >> n2;
    dem_chan_le(n2);

    //BT10 midterm
    cout << "Enter a number (0-20): ";
    int n3;
    cin >> n3;
    so_chu(n3);

    //BT11 midterm
    double a6, b6, c6, A, B, C;
    cin >> a6 >> b6 >> c6 >> A >> B >> C;
    hpt(a6, b6, c6, A, B, C);

    //BT12 midterm
    int n4, m4;
    cin >> n4 >> m4;
    s_sm(n4, m4);

    //BT13 midterm
    int n5, m5;
    long long M;
    cin >> n5 >> m5 >> M;
    s_sm_while(n5, m5, M);

    //BT14 midterm
    long long A2, a7;
    int max_trial;
    string TruePIN;
    cin >> A2 >> a7 >> max_trial >> TruePIN;
    atm(A2, a7, max_trial, TruePIN);
}