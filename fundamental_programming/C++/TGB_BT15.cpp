#include <iostream>
#include <cmath>
using namespace std;

// BT1
void hv (float a, float b) {
    const float CHU_VI = 4 * a;
    const float DIEN_TICH = a * a;
    cout << "Chu vi: " << CHU_VI << '\n';
    cout << "dien tich: " << DIEN_TICH << '\n';
}
//BT2
void hcn (float a, float b) {
    const float CHU_VI = 2 * (a + b);
    const float DIEN_TICH = a * b;
    const float DO_DAI_DUONG_CHEO = sqrt(a * a + b * b);
    cout << "Chu vi: " << CHU_VI << '\n';
    cout << "Dien tich: " << DIEN_TICH << '\n';
    cout << "Do dai duong cheo: " << DO_DAI_DUONG_CHEO << '\n';
}
// BT3
void HLP ( float a, float b, float c) {
    if (a > 0 && a == b && b == c) {
        cout << "HLP" << '\n';
        float Sxq = 4 * a * a;
        float Stp = 6 * a * a;
        float V = a * a * a;
        float d = sqrt(3) * a;
        cout << "Dien tich xung quanh = " << Sxq << '\n';
        cout << "Dien tich toan phan = " << Stp << '\n';
        cout << "The tich = " << V << '\n';
        cout << "Duong cheo = " << d << '\n';
    } else {
        cout << "HHCN" << '\n';
        float Sxq = 2 * (a + b) * c;
        float Stp = 2 * (a * b + b * c + c * a);
        float V = a * b * c;
        float d = sqrt(a * a + b * b + c * c);
        cout << "Dien tich xung quanh = " << Sxq << '\n';
        cout << "Dien tich toan phan = " << Stp << '\n';
        cout << "The tich = " << V << '\n';
        cout << "Duong cheo = " << d << '\n';
    }
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1;
    }
}
// BT4
void listham ( double x, double y) {
    if (x >= 0)
        cout << "Can bac hai cua x = " << sqrt(x) << '\n';
    else
        cout << "sqrt(x) khong xac dinh" << '\n';

    cout << "x luy thua y=" << pow(x, y) << '\n';
    cout << "e mu x voi e la co so logarit tu nhien=" << exp(x)  << '\n';

    if (x > 0) {
        cout << "log(x) = " << log(x) << '\n';
        cout << "log10(x) = " << log10(x) << '\n';
    } else {
        cout << "log va log10 khong xac dinh" << '\n';
    }

    cout << "tri tuyet doi voi int x=" << abs(x) << '\n';
    cout << "tri tuyet doi voi long x=" << labs(x) << '\n';
    cout << "tri tuyet doi voi double x=" << fabs(x) << '\n';
    cout << "cos(x)=" << cos(x) << '\n';
    cout << "sin(x)=" << sin(x) << '\n';
    cout << "tan(x)=" << tan(x) << '\n';
    cout << "acos(x)=" << acos(x) << '\n';
    cout << "asin(x)=" << asin(x) << '\n';
    cout << "atan(x)=" << atan(x) << '\n';
    cout << "floor(x)=" << floor(x) << '\n';
    cout << "ceil(x)=" << ceil(x) << '\n';
}
// BT5
void ptb1 ( double a, double b) {
    if (a == 0 && b == 0) {
        cout << "vo so nghiem" << '\n';
    }
    else if (a == 0 && b != 0) {
        cout << "vo ngiem" << '\n';
    }
    else {
        cout << "x = " << -b / a << '\n';
    }
}
// BT6
void ptb2 ( double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "vo so nghiem." << '\n';
            } else {
                cout << "vo nghiem." << '\n';
            }
        } else {
            cout << "co nghiem duy nhat: x = " << -c / b << '\n';
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "2 nghiem phan biet:" << '\n';
            cout << "x1 = " << x1 << '\n';
            cout << "x2 = " << x2 << '\n';
        }
        else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "co nghiem kep: " << x << '\n';
        }
        else {
            double thuc = -b / (2 * a);
            double ao = sqrt(abs(delta)) / (2 * a);
            cout << "co nghiem phuc:" << '\n';
            cout << "x1 = " << thuc << " + " << abs(ao) << "i" << '\n';
            cout << "x2 = " << thuc << " - " << abs(ao) << "i" << '\n';
        }
    }
}
// BT7
void MaxMin(double a, double b, double c) {
    double max_Val = max(a, max(b, c));
    double min_Val = min(a, min(b, c));
    cout << "Max = " << max_Val << ", Min = " << min_Val << '\n';
}
// BT8
void dem_so(int n) {
    int So_0 = 0, So_Am = 0, So_Duong = 0;
    for (int i = 1; i <= n; ++i) {
        double a;
        cout << "so thuc thu " << i << '\n';
        cin >> a;
        if (a > 0)
            So_Duong++;
        else if (a < 0)
            So_Am++;
        else
            So_0++;
    }
    cout << "ket qua" << '\n';
    cout << "so duong: " << So_Duong << '\n';
    cout << "so am: " << So_Am << '\n';
    cout << "so khong: " << So_0 << '\n';
}
// BT9
void ds_chan_le(int n) {
    int Chan = 0, Le = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cout << "nguyen thu " << i << '\n';
        cin >> a;
        if (a % 2 == 0) {
            Chan++;
        } else {
            Le++;
        }
    }
    cout << " Ket qua" << '\n';
    cout << "so chan  " << Chan << '\n';
    cout << "so le " << Le << '\n';
}
// BT10
void enter_number_cout_english(int n) {
    int a;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        switch (a) {
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
        default: cout << "Khong hop le!";
        }
    }
}
// BT11
void gPT(double a, double b, double c, double A, double B, double C) {
    double D  = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D != 0) {
        cout << "nghiem duy nhat x = " << Dx / D << ", y = " << Dy / D << '\n';
    } else if (Dx == 0 && Dy == 0) {
        cout << "vo so nghiem" << '\n';
    } else {
        cout << "vo nghiem " << '\n';
    }
}
// BT12
void gpt_Sm(int m, int n) {
    double Sm = 0;
    if (m == 0) Sm = n;
    else for (int i = 1; i <= n; ++i) Sm += pow(i, m);
    cout << "Sm = " << Sm << '\n';
}
// BT13
void tinhTong(int m, double M) {
    double Sm = 0;
    int i = 1;
    double term = 1;
    cout << "Enter m, M = ";
    cin >> m >> M;
    while (Sm + term <= M) {
        Sm += term;
        ++i;
        term = pow(i, m);
    }
    cout << Sm << '\n';
}
// BT14
void rutTien(double A, const string& true_PIN, int max_trial) {
    double a;
    string input_PIN;
    bool ok = false;

    for (int i = 1; i <= max_trial; ++i) {
        cout << "\nEnter PIN = ";
        cin >> input_PIN;
        if (input_PIN == true_PIN) {
            ok = true;
            break;
        } else {
            cout << "\nWrong PIN. Re-enter PIN = ";
        }
    }

    if (ok) {
        cout << "Mã PIN đúng. Cho phép rút tiền.\n";
        cout << "\nEnter a = ";
        cin >> a;
        if (a > A) {
            cout << "Số tiền rút lớn hơn số dư khả dụng.\n";
        } else {
            cout << "Bạn đã rút thành công " << a << " VND.\n";
            cout << "Số dư khả dụng: " << A - a << " VND.\n";
            cout << "Bạn muốn in hóa đơn? (Yes/No)?\n";
            string bill;
            cin >> bill;
            if (bill == "Yes")
                cout << "Đang in hóa đơn. Vui lòng đợi...\n";
            else
                cout << "Không in hóa đơn.\n";
            cout << "Cảm ơn bạn đã giao dịch tại ngân hàng X.\n";
        }
    } else {
        cout << "Bạn đã bị khóa thẻ. Vui lòng liên hệ chi nhánh ngân hàng X gần nhất.\n";
    }
}

int main() {
    long long a, b, c;
    int n, m;

    // BT1
    cin >> a >> b;
    hv(a, b);

    // BT2
    cin >> a >> b;
    hcn(a, b);

    // BT3
    cin >> a >> b;
    HLP(a, b, c);

    // BT4
    cin >> a >> b;
    listham (a, b);

    // BT5
    cin >> n;
    ptb1(a, b);

    // BT6
    double da, db, dc;
    cin >> da >> db >> dc;
    ptb2(da, db, dc);

    // BT7
    cin >> da >> db >> dc;
    MaxMin(da, db, dc);

    // BT8
    cout << "Nhap n (so thuc): ";
    cin >> n;
    dem_so(n);

    // BT9
    cout << "Nhap n (so nguyen): ";
    cin >> n;
    ds_chan_le(n);

    // BT10
    cout << "Nhap n: ";
    cin >> n;
    enter_number_cout_english(n);

    // BT11
    double A1, B1, C1, A2, B2, C2;
    cout << "Nhap so pt1: ";
    cin >> A1 >> B1 >> C1;
    cout << "Nhap so pt2: ";
    cin >> A2 >> B2 >> C2;
    gPT(A1, B1, C1, A2, B2, C2);

    // BT12
    cout << "Nhap m va n: ";
    cin >> m >> n;
    gpt_Sm(m, n);

    // BT13
    double M;
    cout << "Enter m, M = ";
    cin >> m >> M;
    tinhTong(m, M);

    // BT14
    double A;
    string true_PIN;
    int max_trial;

    cout << "nhap so du  ";
    cin >> A;
    cout << "nhao true PIN  ";
    cin >> true_PIN;
    cout << " nhap so lan thu toi da  ";
    cin >> max_trial;

    rutTien(A, true_PIN, max_trial);

    return 0;
}