#include <iostream>
#include <cmath>
using namespace std;

//BT1
void bt1(long long C) {
    long long cv = 4 * C;
    long long dt = C * C;
    cout << " chu vi hv: " << cv << "\n";
    cout << " dien tich hv: " << dt << "\n";
}
//BT2
void bt2(double cd, double cr) {
    double cv = 2 * (cd + cr);
    double dt = cd * cr;
    double dc = sqrt(cd * cd + cr * cr);
    cout << " chu vi hcn la: " << cv << "\n";
    cout << " dien tich hcn la: " << dt << "\n";
    cout << " duong cheo hcn la: " << dc << "\n";
}
//BT3
void bt3(long long a, long long b, long long c) {
    if (a > 0 && a == b && b == c) {
        cout << "HLP";
    }
    else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN";
        long long tt = a * b * c;
        long long dtXQ = 2 * (a + b) * c;
        long long dtTP = 2 * (a * b + b * c + a * c);
        double Dc = sqrt(a * a + b * b + c * c);
        cout << "Dien tich xung quanh: " << dtXQ << "\n";
        cout << "Dien tich toan phan: " << dtTP << "\n";
        cout << "Duong cheo: " << Dc << "\n";
        cout << "The tich: " << tt << "\n";
    }
    else {
        cout << -1;
    }
}
//BT4
void bt4(double x, double y) {
    if (x < 0) {
        cout << "x must be nonnegative";
    }
    else {
        cout << sqrt(x) << "\n";
        cout << pow(x, y) << "\n";
        cout << exp(x) << "\n";
    }
    if (x > 0) {
        cout << log(x) << "\n";
        cout << log10(x) << "\n";
    }
    else {
        cout << "x must be nonnegative";
    }
    cout << abs((int)x) << "\n";
    cout << labs((long)x) << "\n";
    cout << fabs(x) << "\n";

    cout << cos(x) << "\n";
    cout << sin(x) << "\n";
    cout << tan(x) << "\n";
    if (x >= -1 && x <= 1) {
        cout << acos(x) << "\n";
        cout << asin(x) << "\n";
    }
    else {
        cout << "x must be nonnegative";
    }
    cout << atan(x) << "\n";
    cout << floor(x) << "\n";
    cout << ceil(x) << "\n";
}
//BT5
void bt5(double A, double B) {
    if (A == 0 && B == 0) {
        cout << "INFINITE SOLUTIONS";
    }
    else if (A == 0) {
        cout << "NO SOLUTION";
    }
    else {
        double X = -B / A;
        cout << X << "\n";
    }
}
//BT6
void bt6(double a1, double b1, double c1) {
    double Delta = b1 * b1 - 4 * a1 * c1;
    if (a1 == 0 && b1 == 0 && c1 == 0) {
        cout << "INFINITE SOLUTIONS";
    }
    else if (a1 == 0 && b1 == 0) {
        cout << "NO SOLUTION";
    }
    else if (a1 == 0) {
        double x1 = -c1 / b1;
        cout << "co 1 nghiem" << x1;
    }
    else if (Delta < 0) {
        cout << "NO SOLUTION";
    }
    else if (Delta == 0) {
        double x2 = -b1 / (2 * a1);
        cout << "co nghiem kep" << x2 << "\n";
    }
    else {
        double x3 = (-b1 + sqrt(Delta)) / (2 * a1);
        double x4 = (-b1 - sqrt(Delta)) / (2 * a1);
        cout << "co 2 nghiem phan biet";
        cout << x3 << "\n";
        cout << x4 << "\n";
    }
}
//BT7
void bt7(double a2, double b2, double c2) {
    double sln = a2;
    if (b2 > sln) {
        sln = b2;
    }
    if (c2 > sln) {
        sln = c2;
    }
    double snn = a2;
    if (b2 < snn) {
        snn = b2;
    }
    if (c2 < snn) {
        snn = c2;
    }
    cout << "So nho nhat la: " << snn << "\n";
    cout << "So lon nhat la: " << sln << "\n";

    int n;
    cout << "n=";
    cin >> n;
    double x;
    cin >> x;
    double sln1 = x;
    double snn1 = x;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (x > sln1)
            sln1 = x;
        if (x < snn1)
            snn1 = x;
    }
    cout << "So nho nhat la: " << snn1 << endl;
    cout << "So lon nhat la: " << sln1 << endl;
}
//BT8
void bt8(long long n) {
    long long duong = 0, am = 0;
    double E;
    for (int i = 0; i < n; i++) {
        cin >> E;
        if (E > 0)
            duong = duong + 1;
        if (E < 0)
            am = am + 1;
    }
    cout << "so so duong la: " << duong << endl;
    cout << "so so am la: " << am << endl;
}
//BT9
void bt9(long long n1) {
    long long chan = 0, le = 0;
    long long E1;
    for (int j = 0; j < n1; j++) {
        cin >> E1;
        if (E1 % 2 == 0)
            chan = chan + 1;
        if (E1 % 2 != 0)
            le = le + 1;
    }
    cout << chan << " " << le;

}
//BT10
void bt10(long long n2) {
    switch (n2) {
    case 1:
        cout << "One";
        break;
    case 2:
        cout << "Two";
        break;
    case 3:
        cout << "Three";
        break;
    case 4:
        cout << "Four";
        break;
    case 5:
        cout << "Five";
        break;
    case 6:
        cout << "Six";
        break;
    case 7:
        cout << "Seven";
        break;
    case 8:
        cout << "Eight";
        break;
    case 9:
        cout << "Nine";
        break;
    case 10:
        cout << "Ten";
        break;
    case 11:
        cout << "Eleven";
        break;
    case 12:
        cout << "Twelve";
        break;
    case 13:
        cout << "Thirteen";
        break;
    case 14:
        cout << "Fourteen";
        break;
    case 15:
        cout << "Fifteen";
        break;
    case 16:
        cout << "Sixteen";
        break;
    case 17:
        cout << "Seventeen";
        break;
    case 18:
        cout << "Eighteen";
        break;
    case 19:
        cout << "Nineteen";
        break;
    case 20:
        cout << "Twenty";
        break;
    default:
        cout << "het so trong khoang 1 toi 10";
    }
}
//BT11
void bt11(double a3, double b3, double c3, double A3, double B3, double C3) {
    double D  = a3 * B3 - A3 * b3;
    double Dx = c3 * B3 - C3 * b3;
    double Dy = a3 * C3 - A3 * c3;

    if (D != 0) {
        cout << "nghiem duy nhat: x = " << Dx / D << ", y = " << Dy / D;
    }
    else if (Dx == 0 && Dy == 0) {
        cout << "vo so nghiem";
    }
    else {
        cout << "vo nghiem";
    }
}
//BT12
void bt12(long long M, long long N) {
    double S = 0;
    for (int k = 0; k <= N; k++) {
        S += pow(k, M);
    }
    cout << "Sm= " << " " << S;
}
//BT13
void bt13(long long M1, long long N1, long long MM) {
    double S1 = 0;
    long long i1 = 1;
    while (i1 <= N1) {
        long long s = pow(i1, M1);
        if (S1 + s <= MM) {
            S1 += s;
            i1++;
        } else {
            break;
        }
    }
    cout << S1;
}
//BT14
void bt14(double Aa, double aA, long long pin, long long pin_input, long long solanthu ) {
    int solan = 0;
    bool khoa = false;
    while (solan < solanthu) {
        cout << "Nhap ma PIN: ";
        cin >> pin_input;
        if (pin_input == pin) {
            cout << "Dang nhap thanh cong\n";
            break;
        }
        solan++;
        if (solan < solanthu) {
            cout << "Sai ma PIN. Vui long thu lai.\n";
        }
    }
    if (aA > Aa) {
        cout << "So tien rut lon hon so du\n";
    } else {
        Aa -= aA;
        cout << "Rut tien thanh cong. So du con lai: " << Aa << '\n';
    }
}
int main() {
//BT1
    long long C;
    cin >> C;
    bt1(C);
//BT2
    double cd, cr;
    cin >> cd >> cr;
    bt2(cd, cr);
//BT3
    long long a, b, c;
    cin >> a >> b >> c;
    bt3(a, b, c);
//BT4
    double x, y;
    cin >> x >> y;
    bt4(x, y);
//BT5
    double A, B;
    cin >> A >> B;
    bt5(A, B);
//BT6
    double a1, b1, c1;
    cin >> a1 >> b1 >> c1;
    bt6(a1, b1, c1);
//BT7
    double a2, b2, c2;
    cin >> a2 >> b2 >> c2;
    bt7(a2, b2, c2);
//BT8
    long long n;
    cin >> n;
    bt8(n);
//BT9
    long long n1;
    cin >> n1;
    bt9(n1);
//BT10
    long long n2;
    cin >> n2;
    bt10(n2);
//BT11
    double a3, b3, c3, A3, B3, C3;
    cin >> a3 >> b3 >> c3;
    cin >> A3 >> B3 >> C3;
    bt11(a3, b3, c3, A3, B3, C3);
//BT12
    long long M, N;
    cin >> M >> N;
    bt12(M, N);
//BT13
    long long M1, N1, MM;
    cin >> M1 >> N1 >> MM;
    bt13(M1, N1, MM);
//BT14
    double Aa, aA;
    long long pin, pin_input;
    long long solanthu;
    cin >> Aa >> aA;
    cin >> pin >> solanthu;
    bt14(Aa, aA, pin, pin_input, solanthu);
    return 0;
}