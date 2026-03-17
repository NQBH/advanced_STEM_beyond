#include <bits/stdc++.h>
using namespace std ;
void hv (double a ) {
    cout << "chu vi hv = " << a * a << endl;
    cout << "dien tich hv = " << a * 4 << endl;
}

void hcn (double a , double b) {
    cout << "chu vi hcn = " << (a + b) / 2;
    cout << "dien tich hcn = " <<  a * b ;
    cout << "duong cheo hcn = " << sqrt(a * a + b * b) ;
}

void kiemtrahinh (double  a , double b , double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "-1\n"; return ;
    }
    if (a > 0 && a == b && b == c) {
        cout << "HLP\n" << endl ;
        cout << "dien tich xq = " << 4 * a * a << endl;
        cout << "Dien tich toan phan Stp = " << 6 * a * a << endl;
        cout << "The tich V = " <<  a * a * a << endl  ;
        cout << "Duong cheo d = " << sqrt(3) * a ;

    }
    if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN" << endl ;
        cout << "Dien tich xung quanh Sxq = " << 2 * (a + b) * c << endl ;
        cout << "Dien tich toan phan Stp = " << 2 * (a * b + b * c + c * a) << endl ;
        cout << "The tich V = " <<  a * b * c << endl ;
        cout << "Duong cheo d = " << sqrt(a * a + b * b + c * c);
    }
}
void testthucacham (double x , double y , double A , double B , double C ) {
    if (x < 0) {
        cout << "Error" << endl ;
    }
    if (x >= 0) {
        cout << sqrt(x) << endl ;
    }
    if (x > 0) {
        cout << pow(x, y) << endl ;
    }
    cout << log(x) << '\n';
    cout << log10(x) << '\n';
    cout << abs(A) << '\n';
    cout << fabs(B) << '\n';
    cout << fabs(C) << '\n';

    cout << cos(x) << '\n';
    cout << sin(x) << '\n';
    cout << tan(x) << '\n';
    cout << 1.0 / tan(x) << '\n';
    if (x >= -1 && x <= 1) {
        cout << acos(x) << '\n';
    }
    if (x >= -1 && x <= 1) {
        cout << asin(x) << '\n';
    }
    cout << atan(x) << '\n';

    cout << floor(x) << '\n';
    cout << ceil(x) << '\n';
}
void BT5 (double a , double b ) {
    if (a == 0) {
        if (b == 0) {
            cout << "Vo so nghiem.\n";
        }
        else cout << "Vo nghiem.\n";
    } else {
        if (b == 0) {
            cout << "x = 0.\n";
        }
        else cout << "x = " << - b / a << "\n";
    }
}
void BT6(double a, double b, double c) {
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
void BT7(double a, double b, double c) {
    double maxVal = max({a, b, c});
    double minVal = min({a, b, c});

    cout << "Max " << maxVal << "\n";
    cout << "Min " << minVal << "\n";
}
void BT8(int n) {
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
void BT9(int n) {
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
void BT10(int n) {
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
void BT11(double a, double b, double c, double A, long long B, double C) {
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
void BT12 (int n , int m) {
    double sum = 0;
    for ( int i = 1; i <= n; i++) {
        sum  += pow(i, m);
    } cout << "Tong Sm " << sum << '.\n';
}
void BT13(int n, int m, int M) {
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
void BT14(double A, string pin_dung, int max_trial) {
    string pin;
    int dem = 0;

    while (dem < max_trial) {
        cout << "Nhap PIN: ";
        cin >> pin;


        string dao = pin;
        reverse(dao.begin(), dao.end());

        if (pin == dao && pin != pin_dung) {
            cout << "Security! Phat hien nhap PIN nguoc.\n";
            return;
        }

        if (pin == pin_dung) {
            cout << "Dang nhap thanh cong!\n";
            break;
        }
        else {
            dem++;
            cout << "Sai PIN!\n";
        }
    }

    if (dem == max_trial) {
        cout << "The bi khoa do nhap sai qua so lan cho phep.\n";
        return;
    }

    double a;
    cout << "Nhap so tien can rut: ";
    cin >> a;

    if (a > A) {
        cout << "So tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
    }
    else {
        A -= a;
        cout << "Rut tien thanh cong!\n";
        cout << "===== HOA DON ATM =====\n";
        cout << "So tien vua rut: " << a << " VND\n";
        cout << "So du con lai: " << A << " VND\n";
        cout << "=======================\n";
    }
}


int main () {
    double a , b , c , x , y , m , n ,  A , B , C , M ;
    cin >> a >> b >> c >> x >> y >> m >> n >> A >> B >> C >> M ;
    hv(a);
    hcn(a , b);
    kiemtrahinh(a , b , c );
    testthucacham(x , y , A , B , C);
    BT5(x , y);
    BT6(a , b , c);
    BT7(a , b , c);
    BT8(n);
    BT9(n);
    BT10(n);
    BT11(a , b , c , A , B , C );
    BT12(m , n);
    BT13(n , m , M );
    string pin ;
    int max_trial ;
    cout << "Nhap so du ban dau: ";
    cin >> A;

    cout << "Nhap PIN thuc (6 so): ";
    cin >> pin;

    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;
    BT14(A, pin, max_trial);
}