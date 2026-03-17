#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

void bai1() {
    float a;
    cin >> a;
    cout << 4 * a << endl;
    cout << a*a << endl;
}

void bai2() {
    float dai, rong;
    cin >> dai >> rong;
    cout << 2 * (dai + rong) << endl;
    cout << dai*rong << endl;
    cout << sqrt(dai * dai + rong * rong) << endl;
}

void bai3() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a <= 0 || b <= 0 || c <= 0) { cout << -1; return; }
    if (a == b && b == c) {
        cout << "HLP" << endl;
        cout << 4 * a*a << endl;
        cout << 6 * a*a << endl;
        cout << a*sqrt(3) << endl;
        cout << a*a*a;
        return;
    }
    cout << "HHCN" << endl;
    cout << 2 * c*(a + b) << endl;
    cout << 2 * (a * b + b * c + a * c) << endl;
    cout << sqrt(a * a + b * b + c * c) << endl;
    cout << a*b*c;
}

void bai4() {
    double x = 4, y = 2, angle = 0.5;
    int a = -10; long b = -100;
    cout << sqrt(x) << endl;
    cout << pow(x, y) << endl;
    cout << exp(y) << endl;
    cout << log(x) << endl;
    cout << log10(x) << endl;
    cout << abs(a) << endl;
    cout << labs(b) << endl;
    cout << fabs(-3.14) << endl;
    cout << sin(angle) << endl;
    cout << cos(angle) << endl;
    cout << tan(angle) << endl;
    cout << asin(0.5) << endl;
    cout << acos(0.5) << endl;
    cout << atan(1) << endl;
    cout << floor(3.7) << endl;
    cout << ceil(3.7) << endl;
}

void bai5() {
    double a, b;
    cin >> a >> b;
    if (fabs(a) > 1e-9) cout << -b / a;
    else if (fabs(b) < 1e-9) cout << "VSN";
    else cout << "VN";
}

void bai6() {
    double a, b, c;
    cin >> a >> b >> c;
    if (fabs(a) < 1e-9) {
        if (fabs(b) < 1e-9) {
            if (fabs(c) < 1e-9) cout << "VSN";
            else cout << "VN";
        } else cout << -c / b;
        return;
    }
    double d = b * b - 4 * a * c;
    if (d > 0) {
        cout << (-b + sqrt(d)) / (2 * a) << endl;
        cout << (-b - sqrt(d)) / (2 * a);
    } else if (fabs(d) < 1e-9) cout << -b / (2 * a);
    else cout << "Vo nghiem thuc";
}

void bai7() {
    double a, b, c, vmax, vmin;
    cin >> a >> b >> c;
    vmax = a; if (b > vmax) vmax = b; if (c > vmax) vmax = c;
    vmin = a; if (b < vmin) vmin = b; if (c < vmin) vmin = c;
    cout << vmax << endl << vmin;
}

void bai8() {
    int n; cin >> n;
    float a; int am = 0, duong = 0, khong = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > 0) duong++;
        else if (a < 0) am++;
        else khong++;
    }
    cout << am << endl << duong << endl << khong;
}

void bai9() {
    int n, chan = 0, le = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a % 2 == 0) chan++;
        else le++;
    }
    cout << chan << " " << le;
}

void inTiengAnh(int n) {
    if (n == 0) cout << "zero";
    else if (n == 1) cout << "one";
    else if (n == 2) cout << "two";
    else if (n == 3) cout << "three";
    else if (n == 4) cout << "four";
    else if (n == 5) cout << "five";
    else if (n == 6) cout << "six";
    else if (n == 7) cout << "seven";
    else if (n == 8) cout << "eight";
    else if (n == 9) cout << "nine";
    else if (n == 10) cout << "ten";
    else if (n == 11) cout << "eleven";
    else if (n == 12) cout << "twelve";
    else if (n == 13) cout << "thirteen";
    else if (n == 14) cout << "fourteen";
    else if (n == 15) cout << "fifteen";
    else if (n == 16) cout << "sixteen";
    else if (n == 17) cout << "seventeen";
    else if (n == 18) cout << "eighteen";
    else if (n == 19) cout << "nineteen";
    else if (n == 20) cout << "twenty";
}

void bai10() {
    int n; cin >> n;
    inTiengAnh(n);
}

void bai11() {
    double a, b, c, A, B, C;
    cin >> a >> b >> c >> A >> B >> C;
    double D = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;
    if (D != 0) cout << Dx / D << " " << Dy / D;
    else if (Dx == 0 && Dy == 0) cout << "VSN";
    else cout << "VN";
}

void bai12() {
    int n, m; cin >> n >> m;
    long long S = 0;
    for (int i = 1; i <= n; i++) {
        long long t = 1;
        for (int j = 1; j <= m; j++) t *= i;
        S += t;
    }
    cout << S;
}

void bai13() {
    int n, m; long long M;
    cin >> n >> m >> M;
    long long S = 0;
    for (int i = 1; i <= n; i++) {
        long long t = 1;
        for (int j = 1; j <= m; j++) t *= i;
        if (S + t > M) break;
        S += t;
    }
    cout << S;
}

void bai14() {
    long long A, a; string pin_real, pin_input;
    int max_trial;
    cin >> A >> a >> pin_real >> max_trial;
    int trials = 0; bool ok = false;
    while (trials < max_trial) {
        cin >> pin_input;
        string r = pin_real;
        reverse(r.begin(), r.end());
        if (pin_input == r) { cout << "Khoa the"; return; }
        if (pin_input == pin_real) { ok = true; break; }
        trials++;
    }
    if (!ok) { cout << "Khoa the"; return; }
    if (a > A) { cout << "Khong du tien"; return; }
    A -= a;
    cout << A;
}

int main() {
    int chon;
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
    }
}