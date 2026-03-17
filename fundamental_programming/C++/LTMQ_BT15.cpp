#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void bai1() {
    float canh = 20;
    float dientich = canh * canh;
    float chuvi = canh * 4;
    cout << "Dien tich = " << dientich << endl;
    cout << "Chu vi = " << chuvi << endl;
}

void bai2() {
    float a, b;
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap b: "; cin >> b;

    float dientich = a * b;
    float chuvi = 2 * (a + b);
    float duongcheo = sqrt(a * a + b * b);

    cout << "Dien tich = " << dientich << endl;
    cout << "Chu vi = " << chuvi << endl;
    cout << "Duong cheo = " << duongcheo << endl;
}

void bai3() {
    int a, b, c;
    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1 << endl;
        return;
    }

    if (a == b && b == c) {
        cout << "HLP" << endl;
    } else {
        cout << "HHCN" << endl;

        float Sxq = 2 * c * (a + b);
        float Stp = 2 * (a * b + a * c + b * c);
        float duongcheo = sqrt(a * a + b * b + c * c);
        float thetich = a * b * c;

        cout << "Sxq = " << Sxq << endl;
        cout << "Stp = " << Stp << endl;
        cout << "Duong cheo = " << duongcheo << endl;
        cout << "The tich = " << thetich << endl;
    }
}

void bai4() {
    double x, y;
    int a;

    cout << "Nhap x: "; cin >> x;
    if (x >= 0) cout << "sqrt = " << sqrt(x) << endl;

    cout << "Nhap x y: "; cin >> x >> y;
    cout << "pow = " << pow(x, y) << endl;

    cout << "Nhap a: "; cin >> a;
    cout << "abs = " << abs(a) << endl;
}

void bai5() {
    int a, b;
    cout << "Nhap a b: ";
    cin >> a >> b;

    if (a != 0) {
        cout << "Nghiem = " << -b / a << endl;
    } else {
        if (b == 0) cout << "Vo so nghiem";
        else cout << "Vo nghiem";
    }
}

void bai6() {
    float a, b, c;
    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Vo so nghiem";
            else cout << "Vo nghiem";
        } else {
            cout << "x = " << -c / b;
        }
    } else {
        float d = b * b - 4 * a * c;
        if (d < 0) cout << "Vo nghiem";
        else if (d == 0) cout << "Nghiem kep x = " << -b / (2 * a);
        else {
            cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(d)) / (2 * a);
        }
    }
}

void bai7() {
    double a, b, c;
    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    cout << "Min = " << min(a, min(b, c)) << endl;
    cout << "Max = " << max(a, max(b, c)) << endl;
}

void bai8() {
    int N;
    cin >> N;

    double a;
    int so0 = 0, soAm = 0, soDuong = 0;

    for (int i = 1; i <= N; i++) {
        cin >> a;
        if (a == 0) so0++;
        else if (a > 0) soDuong++;
        else soAm++;
    }

    cout << "So duong = " << soDuong << endl;
    cout << "So 0 = " << so0 << endl;
    cout << "So am = " << soAm << endl;
}

void bai9() {
    int N, a, chan = 0, le = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a % 2 == 0) chan++;
        else le++;
    }
    cout << "Chan = " << chan << endl;
    cout << "Le = " << le << endl;
}

void bai10() {
    int n;
    cin >> n;
    string str;

    switch (n) {
    case 0: str = "zero"; break;
    case 1: str = "one"; break;
    case 2: str = "two"; break;
    default: str = "other";
    }

    cout << str;
}

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

void bai12() {
    int n, m;
    long long Sm = 0;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        Sm += pow(i, m);
    cout << Sm;
}

void bai13() {
    int n, m;
    long long M;
    cin >> n >> m >> M;

    long long Sm = 0;
    for (int i = 1; i <= n; i++) {
        long long term = pow(i, m);
        if (Sm + term > M) break;
        Sm += term;
    }
    cout << Sm;
}

void bai14() {
    int n;
    cin >> n;
    bool prime = true;

    if (n < 2) prime = false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) prime = false;

    if (prime) cout << "La so nguyen to";
    else cout << "Khong phai so nguyen to";
}

int main() {

    int chon;
    cout << "Nhap bai muon chay (1-14): ";
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