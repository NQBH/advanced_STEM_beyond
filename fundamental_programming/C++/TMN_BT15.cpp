#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/* ===== BAI 1 ===== */
void bai1() {
    float canh = 20;
    cout << "Dien tich = " << canh * canh << endl;
    cout << "Chu vi = " << canh * 4 << endl;
}

/* ===== BAI 2 ===== */
void bai2() {
    float a, b;
    cin >> a >> b;
    cout << "Dien tich = " << a*b << endl;
    cout << "Chu vi = " << 2 * (a + b) << endl;
    cout << "Duong cheo = " << sqrt(a * a + b * b) << endl;
}

/* ===== BAI 3 ===== */
void bai3() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1;
        return;
    }

    if (a == b && b == c) {
        cout << "HLP";
    } else {
        cout << "HHCN\n";
        cout << "Sxq = " << 2 * c*(a + b) << endl;
        cout << "Stp = " << 2 * (a * b + a * c + b * c) << endl;
        cout << "Duong cheo = " << sqrt(a * a + b * b + c * c) << endl;
        cout << "The tich = " << a*b*c << endl;
    }
}

/* ===== BAI 4 ===== */
void bai4() {
    double x;
    cin >> x;

    if (x >= 0) cout << "sqrt = " << sqrt(x) << endl;
    cout << "exp = " << exp(x) << endl;
}

/* ===== BAI 5 ===== */
void bai5() {
    double a, b;
    cin >> a >> b;

    if (a == 0) {
        if (b == 0) cout << "Vo so nghiem";
        else cout << "Vo nghiem";
    } else {
        cout << "x = " << -b / a;
    }
}

/* ===== BAI 6 ===== */
void bai6() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Vo so nghiem";
            else cout << "Vo nghiem";
        } else cout << "x = " << -c / b;
    } else {
        double d = b * b - 4 * a * c;
        if (d < 0) cout << "Vo nghiem";
        else if (d == 0) cout << "Nghiem kep = " << -b / (2 * a);
        else {
            cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(d)) / (2 * a);
        }
    }
}

/* ===== BAI 7 ===== */
void bai7() {
    double a, b, c;
    cin >> a >> b >> c;
    cout << "Min = " << min(a, min(b, c)) << endl;
    cout << "Max = " << max(a, max(b, c));
}

/* ===== BAI 8 ===== */
void bai8() {
    int n;
    cin >> n;
    double x;
    int duong = 0, am = 0, so0 = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0) duong++;
        else if (x < 0) am++;
        else so0++;
    }

    cout << "So duong = " << duong << endl;
    cout << "So am = " << am << endl;
    cout << "So 0 = " << so0;
}

/* ===== BAI 9 ===== */
void bai9() {
    int n, x, chan = 0, le = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) chan++;
        else le++;
    }
    cout << "Chan = " << chan << endl;
    cout << "Le = " << le;
}

/* ===== BAI 10 ===== */
void bai10() {
    int n;
    cin >> n;
    switch (n) {
    case 0: cout << "zero"; break;
    case 1: cout << "one"; break;
    case 2: cout << "two"; break;
    default: cout << "other";
    }
}

/* ===== BAI 11 ===== */
void bai11() {
    double a, b, c, A, B, C;
    cin >> a >> b >> c >> A >> B >> C;

    double D = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D == 0) {
        if (Dx == 0 && Dy == 0) cout << "Vo so nghiem";
        else cout << "Vo nghiem";
    } else {
        cout << "x = " << Dx / D << ", y = " << Dy / D;
    }
}

/* ===== BAI 12 ===== */
void bai12() {
    int n, m;
    cin >> n >> m;

    long long Sm = 0;

    for (int i = 1; i <= n; i++) {
        long long p = 1;
        for (int j = 0; j < m; j++)
            p *= i;
        Sm += p;
    }

    cout << "Sm = " << Sm;
}

/* ===== BAI 13 ===== */
void bai13() {
    int n, m;
    long long M;
    cin >> n >> m >> M;

    long long Sm = 0;

    for (int i = 1; i <= n; i++) {
        long long p = 1;
        for (int j = 0; j < m; j++)
            p *= i;

        if (Sm + p > M) break;
        Sm += p;
    }

    cout << Sm;
}

/* ===== BAI 14 ===== */
void bai14() {
    int n;
    cin >> n;

    if (n < 2) {
        cout << "Khong phai so nguyen to";
        return;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << "Khong phai so nguyen to";
            return;
        }
    }

    cout << "La so nguyen to";
}

/* ===== MAIN MENU ===== */
int main() {
    int chon;
    cout << "Chon bai (1-14): ";
    cin >> chon;

    switch (chon) {
    case 1: bai1(); break;
    case 2: bai2(); break;
    case 3: bai3(); break;
    case 4: bai4(); break;
    case 5: bai5(); break;
    case 6: bai6(); break;
    case 7: bai7(); break;
    case 8: bai8(); break;
    case 9: bai9(); break;
    case 10: bai10(); break;
    case 11: bai11(); break;
    case 12: bai12(); break;
    case 13: bai13(); break;
    case 14: bai14(); break;
    default: cout << "Khong hop le";
    }

    return 0;
}