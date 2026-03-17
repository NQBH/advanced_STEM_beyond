#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//BT 1
void hv(double c) {
    cout << "Nhap canh hinh vuong c = " << endl;

    cout << "Chu vi hinh vuong: " << c * 4 << endl;
    cout << "Dien tich hinh vuong: " << c * c << endl;
}


//BT 2
void hcn(double a, double b) {
    cout << "Nhap gia tri d & r = " << endl;
    cout << "Chu vi hinh chu nhat: " << (a + b) * 2 << endl;
    cout << "Dien tich hinh chu nhat: " << a * b << endl;
    cout << "Do dai duong cheo hinh chu nhat: " << sqrt(a * a + b * b) << endl;
}


//BT3
void hhcn(long long a1, long long b1, long long c1) {
    cout << "Nhap gia tri cua a, b, c = " << endl;

    if ( a1 <= 0 || b1 <= 0 || c1 <= 0) {
        cout << "Gia tri khong hop le" << endl;

    }
    else if ( a1 == b1 && b1 == c1 ) {
        cout << "HLP" << endl;
    }
    else {
        cout << "HHCN" << endl;
    }
    cout << "Dien tich xung quanh hinh hop chu nhat: " << 2 * (a1 + b1) * c1 << endl;
    cout << "Dien tich toan phan hinh hop chu nhat: " << 2 * (a1 * b1 + a1 * c1 + b1 * c1) << endl;
    cout << "Duong cheo hinh hop chu nhat: " << sqrt(a1 * a1 + b1 * b1 + c1 * c1) << endl;
    cout << "The tich hinh hop chu nhat: " << a1 * b1 * c1 << endl;
}


//BT4
void vande_4(double x, double y) {

    //4.1
    cout << "sqrt: ";
    if (x < 0) cout << "x khong duoc am";
    else cout << sqrt(x) << endl;


    //4.2
    cout << "pow: ";
    if (x < 0) cout << "x khong duoc am";
    else cout << pow(x, y) << endl;


    //4.3
    cout << "exp: ";
    cout << exp(x) << endl;


    //4.4
    cout << "log: ";
    if (x < 0) cout << "x khong duoc am";
    else cout << log(x) << endl;


    //4.5
    cout << "log10: ";
    if (x < 0) cout << "x khong duoc am";
    else cout << log10(x) << endl;


    //4.6
    cout << "abs: ";
    cout << abs(x) << endl;
    cout << "labs: ";
    cout << labs(x) << endl;
    cout << "fabs: ";
    cout << fabs(x) << endl;


    //4.7
    double rad = x * M_PI / 180;
    cout << "cos: ";
    cout << cos(rad) << endl;
    cout << "sin: ";
    cout << sin(rad) << endl;
    cout << "tan: ";
    cout << tan(rad) << endl;


    //4.8
    cout << "acos: ";
    if ( x < -1 || x > 1) {
        cout << "lan nay thi anh chiu thua" << endl;
    } else cout << acos(x) << endl;

    cout << "asin: ";
    if ( x < -1 || x > 1) {
        cout << "lan nay thi anh chiu thua" << endl;
    } else cout << asin(x) << endl;

    cout << "atan: ";
    cout << atan(x) << endl;


    //4.9
    cout << "floor: ";
    cout << floor(x) << endl;

    cout << "ceil: ";
    cout << ceil(x) << endl;
}


//BT5
void vande_5(double A, double B) {
    if (A == 0) {
        if (B == 0) {
            cout << "Vo so nghiem" << endl;
        } else {
            cout << "Vo nghiem" << endl;
        }
    } else cout << "x = " << -B / A << endl;

}


//BT6
void vande_6(double a, double b, double c) {
    if (a == 0) {
        //bx + c = 0
        if (b == 0) {
            if (c == 0) {
                cout << "Vo so nghiem" << endl;

            } else cout << "Vo nghiem" << endl;
        } else cout << "x = " << -c / b << endl;

    } else {
        double D = (b * b) - (4 * a * c);
        if ( D > 0 ) {
            cout << "2 nghiem thuc" << endl;
            cout << "x = " << ( -b + sqrt(D) ) / (2 * a) << endl;
            cout << "x = " << ( -b - sqrt(D) ) / (2 * a) << endl;
        } else if ( D == 0 ) {
            cout << "nghiem kep" << endl;
            cout << "x = " << ( -b ) / ( 2 * a ) << endl;
        } else {

            double thuc =  ( -b ) / ( 2 * a );
            double ao = sqrt( -D ) / ( 2 * a );

            cout << "x = " << thuc << " + " << ao << "i" << endl;
            cout << "x = " << thuc << " - " << ao << "i" << endl;
        }
    }
}


//BT7
void vande_7(double a, double b, double c) {
    double min, max;
    cout << "Nhap 3 so thuc a, b, c:" << endl;


    //-min-
    if ( a <= b && a <= c ) {
        min = a;
    }
    else if ( b <= a && b <= c ) {
        min = b;
    }
    else {
        min = c;
    }

    //-max-
    if ( a >= b && a >= c) {
        max = a;
    }
    else if ( b >= a && b >= c ) {
        max = b;
    }
    else {
        max = c;
    }

    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;

//---Problem 2---
    int n;
    cout << "Nhap so phan tu cua n:" << endl;
    cin >> n;

    vector<double> arr(n);

    for (int i = 0; i < n; i++) {
        cout << "nhap so: ";
        cin >> arr[i];
    }

    //min max
    double vmax = arr[0];
    double vmin = arr[0];

    for (int i = 0; i < n; i++) {
        if (vmax < arr[i] ) {
            vmax = arr[i];
        }

        if (vmin > arr[i]) {
            vmin = arr[i];
        }
    }

    cout << "min: " << vmin << endl;
    cout << "max: " << vmax << endl;

}


//BT8
void vande_8(long long n, double num, int am = 0, int duong = 0, int khong = 0) {

    for (int i = 0; i < n; i++) {
        cout << "nhap so: ";
        cin >> num;

        if (num < 0) {
            am += 1;
        } else if (num > 0) {
            duong += 1;
        } else {
            khong += 1;
        }
    }

    cout << "so duong: " << duong << endl;
    cout << "so am: " << am << endl;
    cout << "so khong: " << khong << endl;

}

//BT9
void vande_9(double n, double chan, double le) {

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cout << "nhap so: " << endl;
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if ( arr[i] % 2 == 0 ) {
            chan += 1;
        } else le += 1;
    }

    cout << "so luong so chan: " << chan << endl;
    cout << "so luong so le: " << le << endl;

}
//BT10
void vande_10(int n) {
    while ( n < 0 || n > 20 ) {
        cout << "Lua chon khong hop le, vui long nhap lai so tu 0-20" << endl;
        cin >> n;
    }

    switch (n) {

    case 0:
        cout << "zero" << endl;
        break;

    case 1:
        cout << "one" << endl;
        break;

    case 2:
        cout << "two" << endl;
        break;

    case 3:
        cout << "three" << endl;
        break;

    case 4:
        cout << "four" << endl;
        break;

    case 5:
        cout << "five" << endl;
        break;

    case 6:
        cout << "six" << endl;
        break;

    case 7:
        cout << "seven" << endl;
        break;

    case 8:
        cout << "eight" << endl;
        break;

    case 9:
        cout << "nine" << endl;
        break;

    case 10:
        cout << "ten" << endl;
        break;

    case 11:
        cout << "elevent" << endl;
        break;

    case 12:
        cout << "twelve" << endl;
        break;

    case 13:
        cout << "thirteen" << endl;
        break;

    case 14:
        cout << "fourteen" << endl;
        break;

    case 15:
        cout << "fifteen" << endl;
        break;

    case 16:
        cout << "sixteen" << endl;
        break;

    case 17:
        cout << "seventeen" << endl;
        break;

    case 18:
        cout << "eighteen" << endl;
        break;

    case 19:
        cout << "nineteen" << endl;
        break;

    case 20:
        cout << "twenty" << endl;
        break;


    }
}


//BT11
void vande_11(double a, double b, double c, double A, double B, double C) {
    double M = (a * B) - (A * b);
    double Mx = (c * B) - (C * b);
    double My = (a * C) - (A * c);

    if (M != 0) {
        cout << "he co mot nghiem: x = " << Mx / M << " ; y = " << My / M << endl;
    } else if (Mx == 0 && My == 0) {
        cout << "he co vo so nghiem" << endl;
    } else {
        cout << "he vo nghiem" << endl;
    }
}


//BT12
void vande_12(int m, int n, int Sm) {
    for ( int i = 1; i <= n; i++) {
        Sm += pow(i, m);
    }

    cout << "Sm = " << Sm << endl;

    return;
}


//BT13
void vande_13(int m, int n, long long Sm, long long M) {
    for ( int i = 1; ; i++ ) {
        long long p = pow(i, m);

        if (Sm + p > M) {
            n = i - 1;
            break;
        }

        Sm += p;
        n = i;
    }

    cout << "n lon nhat = " << n << endl;
    cout << "Sm = " << Sm << endl;

    return;
}


//BT14
int dao(int x) {
    int nghichdao = 0;
    while (x > 0) {
        nghichdao = nghichdao * 10 + x % 10;
        x /= 10;
    }
    return nghichdao;
}
void vande_14(int a, int A, int max_trial, int dem, int PIN, int inPIN) {
    while (cin.fail() || A < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai so tien (lon hon 0, chi nhap so): ";
        cin >> A;
    }

    cout << "tao ma PIN (6 so): ";
    cin >> PIN;
    while (cin.fail() || PIN < 100000 || PIN > 999999) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai PIN (chi nhap 6 so, khong nhap chu): ";
        cin >> PIN;
    }

    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;
    while (cin.fail() || max_trial <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai so lan thu (lon hon 0, chi nhap so): ";
        cin >> max_trial;
    }

    cout << "---------------------------------" << endl;

    while (dem < max_trial) {
        cout << "\nNhap PIN: ";
        cin >> inPIN;

        if (inPIN == dao(PIN)) {
            cout << "SECURITY ALERT! Ban da nhap PIN nguoc. The bi khoa!\n";
            return;
        }

        if (inPIN == PIN) {
            cout << "Xac thuc thanh cong!\n";
            break;
        }

        dem++;
        cout << "Sai PIN! Ban con " << max_trial - dem << " lan thu.\n";
    }

    if (dem == max_trial) {
        cout << "Ban da nhap sai qua so lan cho phep. The bi khoa!\n";
        return;
    }

    cout << "nhap so tien can rut: ";
    cin >> a;

    if (a > A) {
        cout << "So tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
        return;
    } else {
        A -= a;
    }

    cout << "\n========= HOA DON ATM =========\n";
    cout << "So tien rut : " << a << " VND\n";
    cout << "So du con lai: " << A << " VND\n";
    cout << "Cam on quy khach da su dung dich vu!\n";
    cout << "================================\n";
}



//BT 1
int main () {
    double c;
    cout << "Nhap vao 1 canh hinh vuong: ";
    cin >> c;
    hv(c);

//BT2
    double a, b;
    cout << "Nhap vao chieu dai va rong: ";
    cin >> a >> b;
    hcn(a, b);

//BT3
    long long a1, b1, c1;
    cout << "Nhap vao chieu dai, rong, cao: ";
    cin >> a1 >> b1 >> c1;
    hhcn(a1, b1, c1);

//BT4
    double x, y;
    cout << "Nhap gia tri cua x, y: ";
    cin >> x >> y;
    vande_4(x, y);

//BT5
    double A, B;
    cout << "Nhap gia tri cua A, B: ";
    cin >> A >> B;
    vande_5(A, B);

//BT6
    double a2, b2, c2;
    cout << "Nhap gia tri cua a2, b2, c2: ";
    cin >> a2 >> b2 >> c2;
    vande_6(a2, b2, c2);

//BT7
    double J, Q, K;
    cout << "Nhap gia tri cua J, Q, K: ";
    cin >> J >> Q >> K;
    vande_7(J, Q, K);

//BT8
    int w;
    int am = 0, duong = 0, khong = 0;
    double num;
    cout << "nhap n so thuc: ";
    cin >> w;
    vande_8(w, num, am, duong, khong);

//BT9
    int t;
    int chan = 0, le = 0;
    cout << "Nhap n so nguyen" << endl;
    cin >> t;
    vande_9(t, chan, le);

//BT10
    int f;
    cout << "Nhap so tu 0-20" << endl;
    cin >> f;
    vande_10(f);

//BT11
    double h, i, v, H, I, V;
    cout << "nhap bien vao phuong trinh 1 (a, b, c): " << endl;
    cin >> h >> i >> v;
    cout << "nhap bien vao phuong trinh 2 (A, B, C): " << endl;
    cin >> H >> I >> V;
    vande_11(h, i, v, H, I, V);

//BT12
    int n, m;
    double Sm = 0;

    cout << "Nhap n: " << endl;
    cin >> n;

    cout << "Nhap m: " << endl;
    cin >> m;
    vande_12(m, n, Sm);

//BT13
    long long Smm = 0;
    long long M;
    int Z, F = 0;

    cout << "Nhap f " << endl;
    cin >> Z;

    cout << "Nhap M ( M la gia tri lon nhat ) " << endl;
    cin >> M;
    vande_13(Z, F, M, Smm);

//BT14
    int p, P, max_trial, dem = 0;
    int PIN, inPIN;

    cout << "so tien(VND) ban co: ";
    cin >> P;
    vande_14(p, P, max_trial, dem = 0, PIN, inPIN);

}