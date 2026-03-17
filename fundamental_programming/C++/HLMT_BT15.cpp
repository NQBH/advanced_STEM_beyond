#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void BT1 () {
    double a;
    cout << "Nhap canh hinh vuong: ";
    cin >> a;
    cout << "Chu vi: " << 4 * a << endl;
    cout << "Dien tich: " << a*a << endl;

}

void BT2 () {
    double dai , rong;
    cout << "Nhap chieu dai va rong: ";
    cin >> dai >> rong;
    cout << "Chu vi: " << 2 * (dai + rong) << endl;
    cout << "Dien tich: " << dai*rong << endl;
    cout << "Duong cheo: " << sqrt(dai * dai + rong * rong) << endl;

}

void BT3 () {
    int a, b, c;
    cout << "Nhap 3 canh a b c: ";
    cin >> a >> b >> c;

    if (a == b && b == c && a > 0) {
        cout << "HLP" << endl;
    }
    else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN" << endl;
        cout << "Dien tich xung quanh: " << 2 * c*(a + b) << endl;
        cout << "Dien tich toan phan: " << 2 * (a * b + a * c + b * c) << endl;
        cout << "The tich: " << a*b*c << endl;
        cout << "Duong cheo: " << sqrt(a * a + b * b + c * c) << endl;

    }
    else cout << -1;

}

void BT4 () {
    double x;
    cout << "Nhap so x: ";
    cin >> x;

    cout << "sqrt(x): " << sqrt(x) << endl;
    cout << "abs(x): " << abs (x) << endl;
    cout << "pow(x,2): " << pow (x, 2) << endl;
    cout << "sin(x): " << sin (x) << endl;
    cout << "cos(x): " << cos (x) << endl;
    cout << "tan(x): " << tan (x) << endl;
    cout << "log(x): " << log (x) << endl;
    cout << "log10(x): " << log10 (x) << endl;
    cout << "ceil(x): " << ceil (x) << endl;
    cout << "floor(x): " << floor (x) << endl;

}

void BT5 () {
    double a, b;
    cout << "Nhap a b: ";
    cin >> a >> b;

    if (a == 0) {
        if (b == 0) cout << "Vo so nghiem";
        else cout << "Vo nghiem";
    } else cout << "x = " << -b / a;

}

void BT6 () {
    double a, b, c;
    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) cout << "Vo nghiem";
        else cout << "x = " << -c / b;
        return;
    }

    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        cout << "Vo nghiem";
    }
    else if (delta == 0) {
        cout << "Nghiem kep x = " << -b / (2 * a);
    }
    else {
        cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;

    }
}

void BT7 () {
    double a, b, c;
    cout << "Nhap 3 so: ";
    cin >> a >> b >> c;

    double max = a , min = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (b < min) min = b;
    if (c < min) min = c;

    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

}

void BT8 () {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    double x;
    int am = 0 , duong = 0 , khong = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0) duong++;
        else if (x < 0) am++;
        else khong++;
    }
    cout << "So duong: " << duong << endl;
    cout << "So am: " << am << endl;
    cout << "So 0: " << khong << endl;

}

void BT9 () {
    int n, x, chan = 0, le = 0;
    cout << "Nhap n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if  (x % 2 == 0) chan++;
        else le++;
    }

    cout << "So chan: " << chan << endl;
    cout << "So le: " << le << endl;

}

void BT10 () {
    int n;
    cout << "Nhap n (0-20): ";
    cin >> n;

    switch (n)  {
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

}

void BT11 () {
    double a, b, c, A, B, C;
    cout << "Nhap a , b ,c: ";
    cin >> a >> b >> c;
    cout << "Nhap A , B ,C: ";
    cin >> A >> B >> C;

    void giai_he (double a , double b , double c , double A , double B , double C);


}


void BT12 () {
    int n, m;
    cout << "Nhap n va m: ";
    cin >> n >> m;

    long long S = 0;
    for (int i = 1; i <= n; i++) S += pow (i, m);
    cout << "Tong = " << S;
}

void BT13 () {
    int n, m;
    long long M;
    cout << "Nhap n m M: ";
    cin >> n >> m >> M;
    long long S = 0;
    int i = 1;

    while (i <= n && S + pow(i, m) <= M) {
        S += pow(i, m);
        i++;
    }

    cout << "Tong lon nhat <= M la: " << S << endl;
    cout << "Dung den i = " << i - 1;

}


void BT14 () {
    string PIN = "123456", nhap;
    int max_trial;
    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;

    int dem = 0;
    while (dem < max_trial)  {
        cout << "Nhap PIN: ";
        cin >> nhap;

        if (nhap == "654321") {
            cout << "Security Alert!";
            return;
        }

        if (nhap == PIN) break;
        dem++;
    }

    if (dem == max_trial) {
        cout << "Khoa the!";
        return;
    }

    double A, a;
    cout << "Nhap so du: ";
    cin >> A;
    cout << "Nhap so tien muon rut: ";
    cin >> a;

    if  (a > A)
        cout << "So tien rut lon hon so du!";
    else {
        A -= a;
        cout << "Rut thanh cong!\nSo du con lai: " << A;
    }

}

int main() {
    int chon;
    cout << "Chon bai (1-14): ";
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
    case 11: BT11(); break;
    case 12: BT12(); break;
    case 13: BT13(); break;
    case 14: BT14(); break;
    default: cout << "Khong hop le!";
    }

    return 0;
}