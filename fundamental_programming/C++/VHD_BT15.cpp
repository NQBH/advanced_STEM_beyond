#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// ===== BT1 =====
void BT1() {
    double a; cin >> a;
    cout << "Chu vi: " << 4 * a << endl;
    cout << "Dien tich: " << a*a << endl;
}

// ===== BT2 =====
void BT2() {
    double d, r; cin >> d >> r;
    cout << "Chu vi: " << 2 * (d + r) << endl;
    cout << "Dien tich: " << d*r << endl;
    cout << "Duong cheo: " << sqrt(d * d + r * r) << endl;
}

// ===== BT3 =====
void BT3() {
    int a, b, c; cin >> a >> b >> c;
    if (a > 0 && a == b && b == c) cout << "HLP\n";
    else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN\n";
        cout << "Sxq: " << 2 * (a + b)*c << endl;
        cout << "Stp: " << 2 * (a * b + b * c + a * c) << endl;
        cout << "Duong cheo: " << sqrt(a * a + b * b + c * c) << endl;
        cout << "The tich: " << a*b*c << endl;
    } else cout << -1 << endl;
}

// ===== BT4 =====
void BT4() {
    double x = 9, y = 2;
    cout << "sqrt: " << sqrt(x) << endl;
    cout << "pow: " << pow(x, y) << endl;
    cout << "exp: " << exp(2) << endl;
    cout << "log: " << log(x) << endl;
    cout << "log10: " << log10(x) << endl;
    cout << "abs: " << abs(-5) << endl;
    cout << "fabs: " << fabs(-5.5) << endl;
    cout << "cos: " << cos(0.5) << endl;
    cout << "sin: " << sin(0.5) << endl;
    cout << "tan: " << tan(0.5) << endl;
    cout << "acos: " << acos(0.5) << endl;
    cout << "asin: " << asin(0.5) << endl;
    cout << "atan: " << atan(0.5) << endl;
    cout << "floor: " << floor(5.7) << endl;
    cout << "ceil: " << ceil(5.7) << endl;
}

// ===== BT5 =====
void BT5() {
    double a, b; cin >> a >> b;
    if (a == 0) {
        if (b == 0) cout << "Vo so nghiem\n";
        else cout << "Vo nghiem\n";
    } else cout << "x=" << -b / a << endl;
}

// ===== BT6 =====
void BT6() {
    double a, b, c; cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Vo so nghiem\n";
            else cout << "Vo nghiem\n";
        } else cout << "x=" << -c / b << endl;
    }
    else {
        double d = b * b - 4 * a * c;
        if (d < 0) cout << "Vo nghiem\n";
        else if (d == 0) cout << "x=" << -b / (2 * a) << endl;
        else {
            cout << "x1=" << (-b + sqrt(d)) / (2 * a) << endl;
            cout << "x2=" << (-b - sqrt(d)) / (2 * a) << endl;
        }
    }
}

// ===== BT7 =====
void BT7() {
    double a, b, c; cin >> a >> b >> c;
    double max = a, min = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (b < min) min = b;
    if (c < min) min = c;
    cout << "Max=" << max << "\nMin=" << min << endl;
}

// ===== BT8 =====
void BT8() {
    int n; cin >> n;
    int am = 0, duong = 0, khong = 0;
    double x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x > 0) duong++;
        else if (x < 0) am++;
        else khong++;
    }
    cout << "Duong=" << duong << " Am=" << am << " So0=" << khong << endl;
}

// ===== BT9 =====
void BT9() {
    int n; cin >> n;
    int chan = 0, le = 0, x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x % 2 == 0) chan++;
        else le++;
    }
    cout << "Chan=" << chan << " Le=" << le << endl;
}

// ===== BT10 =====
void BT10() {
    int n; cin >> n;
    switch (n) {
    case 0: cout << "zero"; break;
    case 1: cout << "one"; break;
    case 2: cout << "two"; break;
    case 3: cout << "three"; break;
    case 4: cout << "four"; break;
    case 5: cout << "five"; break;
    case 6: cout << "six"; break;
    case 7: cout << "seven"; break;
    case 8: cout << "eight"; break;
    case 9: cout << "nine"; break;
    case 10: cout << "ten"; break;
    case 11: cout << "eleven"; break;
    case 12: cout << "twelve"; break;
    case 13: cout << "thirteen"; break;
    case 14: cout << "fourteen"; break;
    case 15: cout << "fifteen"; break;
    case 16: cout << "sixteen"; break;
    case 17: cout << "seventeen"; break;
    case 18: cout << "eighteen"; break;
    case 19: cout << "nineteen"; break;
    case 20: cout << "twenty"; break;
    default: cout << "Khong hop le";
    }
    cout << endl;
}

// ===== BT12 =====
void BT12() {
    int n, m; cin >> n >> m;
    long long S = 0;
    for (int i = 1; i <= n; i++) S += pow(i, m);
    cout << "Sm=" << S << endl;
}

// ===== BT13 =====
void BT13() {
    int n, m; long long M;
    cin >> n >> m >> M;
    long long S = 0;
    for (int i = 1; i <= n; i++) {
        if (S + pow(i, m) > M) break;
        S += pow(i, m);
    }
    cout << "Sm max <= M: " << S << endl;
}

// ===== BT14 =====
void BT14() {
    long long A, a; int max_trial;
    string pin, real_pin = "123456";
    cin >> A >> a >> max_trial;
    int dem = 0;
    while (dem < max_trial) {
        cin >> pin;
        string rev(pin.rbegin(), pin.rend());
        if (pin == rev && pin != real_pin) {
            cout << "Security Alert\n";
            return;
        }
        if (pin == real_pin) break;
        dem++;
        if (dem == max_trial) {
            cout << "Khoa the\n";
            return;
        }
    }
    if (a > A) cout << "Rut qua so du\n";
    else {
        A -= a;
        cout << "Rut thanh cong. So du con lai: " << A << endl;
    }
}

// ===== MAIN =====
int main() {
    int chon;
    do {
        cout << "\n===== MENU BT15 =====\n";
        cout << "1.BT1\n2.BT2\n3.BT3\n4.BT4\n5.BT5\n6.BT6\n";
        cout << "7.BT7\n8.BT8\n9.BT9\n10.BT10\n";
        cout << "11.BT12\n12.BT13\n13.BT14\n0.Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        switch (chon) {
        case 1: BT1(); break;
        case 2: BT2(); break;
        case 3: BT3(); break;
        case 4: BT4(); break;
        case 5: BT5(); break;
        case 6: BT6(); break;
        case 7: BT7(); break;
        case 8: BT8(); break;
        case 9: BT9(); break;
        case 10: BT10(); break;
        case 11: BT12(); break;
        case 12: BT13(); break;
        case 13: BT14(); break;
        case 0: cout << "Thoat\n"; break;
        default: cout << "Khong hop le\n";
        }

    } while (chon != 0);

    return 0;
}