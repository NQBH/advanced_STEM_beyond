#include <cmath>
#include <iostream>
using namespace std;

void ChuVi_DienTich(int canh)
{
    float ChuVi = 4 * canh, DienTich = canh * canh;

    cout << "Chu vi hinh vuong bang:" << ChuVi << endl;
    cout << "Dien Tich hinh vuong bang:" << DienTich << endl;
}

void ChuVi_DienTich_DuongCheo(int chieudai, int chieurong) {



    float ChuVi = (chieudai + chieurong) * 2, DienTich = chieudai * chieurong, DuongCheo = sqrt(chieudai * chieudai + chieurong * chieurong);

    cout << "Chu vi hinh chu nhat bang:" << ChuVi << endl;
    cout << "Dien Tich hinh chu nhat bang:" << DienTich << endl;
    cout << "Duong Cheo hinh chu nhat bang:" << DuongCheo << endl;
}

void Sxq_Stp_V_d (float a, float b, float c) {
    if (a <= 0 || b <= 0 || c <= 0) cout << "-1\n";
    else {
        if (a > 0 && a == b && b == c) {
            cout << "HLP\n";
            float Sxq = 4 * a * a, Stp = 6 * a * a, V = a * a * a, d = sqrt(3) * a;
            cout << "Dien tich xung quanh Sxq = " << Sxq << '\n';
            cout << "Dien tich toan phan Stp = " << Stp << '\n';
            cout << "The tich V = " << V << '\n';
            cout << "Duong cheo d = " << d << '\n';

        } else { // case HHCN
            cout << "HHCN\n";
            float Sxq = 2 * (a + b) * c, Stp = 2 * (a * b + b * c + c * a), V = a * b * c, d = sqrt(a * a + b * b + c * c);
            cout << "Dien tich xung quanh Sxq = " << Sxq << '\n';
            cout << "Dien tich toan phan Stp = " << Stp << '\n';
            cout << "The tich V = " << V << '\n';
            cout << "Duong cheo d = " << d << '\n';
        }
    }
}

void all (double x, double y) {
    if (x < 0) {
        cout << "X must be nonnegative";
    }
    else cout << sqrt(x) << endl;
    cout << pow(x, y) << endl;
    cout << exp(x) << endl;
    cout << log(x) << endl;
    cout << log10(x) << endl;
    cout << "int=" << abs(x) << endl;
    cout << "long=" << long(x) << endl;
    cout << "double=" << fabs(x) << endl;
    cout << cos(x) << endl;
    cout << sin(x) << endl;
    cout << tan(x) << endl;
    cout << acos(x) << endl;
    cout << asin(x) << endl;
    cout << atan(x) << endl;
    cout << floor(x) << endl;
    cout << ceil(x) << endl;
}
void BT5 (double a, double b) {
    float x = -b / a;
    if (a == 0 && b == 0) {
        cout << "Vo so nghiem" << endl;
    }
    else if (b != 0) {
        cout << "Vo nghiem" << endl;
    }
    if (a != 0) {
        cout << x << endl;
    }
}

void BT6(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "Phuong trinh vo so nghiem";
            else
                cout << "Phuong trinh vo nghiem";
        } else {
            double x = -c / b;
            cout << "Phuong trinh bac nhat, nghiem x = " << x;
        }
    } else {
        double delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Phuong trinh vo nghiem";
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep x = " << x;
        } else {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:\n";
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }
}
void max_min(int a, int b, int c) {
    double max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    double min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    cout << "Max:" << max << endl;
    cout << "Min:" << min << endl;
}
void BT8(int n) {
    double v;
    int dd = 0, da = 0, dk = 0;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thuc " << i << ":" << endl;
        cin >> v;
        if (v > 0) {
            dd++;
        }
        else if (v < 0) {
            da++;
        }
        else if (v == 0) {
            dk++;
        }
    }
    cout << "Dem so duong:" << dd << endl;
    cout << "Dem so am:" << da << endl;
    cout << "Dem so khong:" << dk << endl;
}
void count_even_odd(int n) {
    long long v;
    int a, sc = 0, sl = 0;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> v;

        if (v % 2 == 0)
            sc++;
        else
            sl++;
    }

    cout << "Dem so chan: " << sc << endl;
    cout << "Dem so le: " << sl << endl;

}
void BT10(int n) {
    string str;
    switch (n)
    {
    case 0: str = "Zero"; break;
    case 1: str = "One"; break;
    case 2: str = "Two"; break;
    case 3: str = "Three"; break;
    case 4: str = "Four"; break;
    case 5: str = "Five"; break;
    case 6: str = "Six"; break;
    case 7: str = "Seven"; break;
    case 8: str = "Eight"; break;
    case 9: str = "Nine"; break;
    case 10: str = "Ten"; break;
    case 11: str = "Eleven"; break;
    case 12: str = "Twelve"; break;
    case 13: str = "Thirteen"; break;
    case 14: str = "Fourteen"; break;
    case 15: str = "Fifteen"; break;
    case 16: str = "Sixteen"; break;
    case 17: str = "Seventeen"; break;
    case 18: str = "Eighteen"; break;
    case 19: str = "Nineteen"; break;
    case 20: str = "Twenty"; break;
    default:
        str = "So khong hop le";
    }

    cout << str;
}
void BT11(double a, double b, double c, double A, double B, double C) {
    double D, Dx, Dy;

    D  = a * B - b * A;
    Dx = c * B - b * C;
    Dy = a * C - c * A;

    if (D != 0)
    {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He co nghiem duy nhat:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    else
    {
        if (Dx == 0 && Dy == 0)
            cout << "He co vo so nghiem";
        else
            cout << "He vo nghiem";
    }
}
void BT12(int n, int m) {
    double Sm = 0;
    for (int i = 1; i <= n; i++) {
        Sm += pow(i, m);
    }

    cout << "Sm = " << Sm << endl;
}
void BT13(int n, int m, long long M) {
    double Sm = 0;

    for (int i = 1; i <= n; i++) {
        if (Sm + pow(i, m) > M)
            break;
        Sm = pow(i, m);
    }

    cout << "Sm lon nhat <= M la: " << Sm << endl;
}
void BT14(long long a, long long A, int max_trial, string pin, string pin_nhap) {
    int dem = 0;
    string pin_dao = "";
    for (int i = pin.length() - 1; i >= 0; i--) {
        pin_dao += pin[i];
    }

    while (dem < max_trial) {
        cout << "Nhap PIN: ";
        cin >> pin_nhap;

        if (pin_nhap == pin_dao) {
            cout << "CANH BAO SECURITY! The bi khoa ngay.\n";
        }

        if (pin_nhap == pin) {
            break;
        } else {
            dem++;
            cout << "Sai PIN!\n";
        }
    }

    if (dem == max_trial) {
        cout << "Nhap sai qua so lan cho phep. The da bi khoa.\n";
    }

    if (a > A) {
        cout << "So tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
    } else {
        A -= a;
        cout << "\n===== HOA DON ATM =====\n";
        cout << "So tien rut: " << a << " VND\n";
        cout << "So du con lai: " << A << " VND\n";
    }
}
int main() {
    int canh;
    cin >> canh;
    ChuVi_DienTich(canh);

    int chieudai;
    int chieurong;
    cin >> chieudai;
    cin >> chieurong;
    ChuVi_DienTich_DuongCheo(chieudai, chieurong);

    float a, b, c;
    cin >> a >> b >> c;
    Sxq_Stp_V_d (a, b, c);

    double x, y;
    cin >> x >> y;
    all(x, y);

    cin >> a >> b;
    BT5(a, b);

    cin >> a >> b >> c;
    BT6(a, b, c);

    cin >> a >> b >> c;
    max_min(a, b, c);

    int n;
    cin >> n;
    BT8(n);

    cin >> n;
    count_even_odd(n);

    cin >> n;
    BT10(n);

    double A, B, C;
    cin >> a >> b >> c;
    cin >> A >> B >> C;
    BT11(a, b, c, A, B, C);

    int m;
    cin >> n;
    cin >> m;
    BT12(n, m);

    long long M;
    cin >> n;
    cin >> m;
    cin >> M;
    BT13(n, m, M);

    int max_trial;
    string pin, pin_nhap;
    cin >> A;
    cin >> a;
    cin >> pin;
    cin >> max_trial;
    BT14(a, A, max_trial, pin, pin_nhap);
}
