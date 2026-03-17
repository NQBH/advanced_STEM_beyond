#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void vande_1(double n) {
    while (n <= 0) {
        cout << "loi so, vui long nhap lai " << endl;
        cin >> n;
    }
    cout << "chu vi hinh vuong: " << n * 4 << endl;
    cout << "dien tich hinh vuong: " << n*n << endl;
}

void vande_2(double d, double r) {
    while (d <= 0 || r <= 0) {
        cout << "loi so, vui long nhap lai " << endl;
        cin >> d >> r;
    }

    cout << "chu vi hinh chu nhat: " << (d + r) * 2 << endl;
    cout << "dien tich hinh chu nhat: " << d*r << endl;
    cout << "do dai duong cheo: " << sqrt(d * d + r * r) << endl;
}

void vande_3(int a, int b, int c) {
    while (a <= 0 || b <= 0 || c <= 0) {
        cout << "loi so, vui long nhap lai";
        cin >> a >> b >> c;
    }

    if (a == b && b == c) {
        cout << "HLP" << endl;
        return;
    } else {
        cout << "HHCN" << endl;
    }

    cout << "dien tich xung quanh: " << 2 * c*(a + b) << endl;
    cout << "dien tich toan phan: " << 2 * (a * b + b * c + c * a) << endl;
    cout << "duong cheo: " << sqrt(a * a + b * b + c * c) << endl;
    cout << "the tich: " << a*b*c << endl;
}
void vande_4(double x, double y) {
    //sqrt
    cout << "sqrt: ";
    if (x <= 0) cout << "khong hop le" << endl;
    else cout << sqrt(x) << endl;
//pow
    cout << "pow: ";
    cout << pow(x, y) << endl;
//exp
    cout << "exp: ";
    cout << exp(x) << endl;
//log
    cout << "log: ";
    if (x <= 0) cout << "khong hop le" << endl;
    else cout << log(x) << endl;
//log10
    cout << "log10: ";
    if (x <= 0) cout << "khong hop le" << endl;
    else cout << log10(x) << endl;
//abs
    cout << "abs: ";
    cout << abs(x) << endl;
//labs
    cout << "labs: ";
    cout << labs(x) << endl;
//fabs
    cout << "fabs: ";
    cout << fabs(x) << endl;
//-----radian-----
//cos
    cout << "cos: ";
    double rad = x * M_PI / 180; // 180 do
    cout << cos(rad) << endl;
//sin
    cout << "sin: ";
    cout << sin(rad) << endl;
//tan
    cout << "tan: ";
    cout << tan(rad) << endl;
//acos
    cout << "acos: ";
    if (rad > 1 || rad < -1) {
        cout << "khong tinh duoc" << endl;
    } else cout << acos(rad) << endl;
//asin
    cout << "asin: ";
    if (rad > 1 || rad < -1) {
        cout << "khong tinh duoc" << endl;
    } else cout << asin(rad) << endl;
//atan
    cout << "atan: ";
    cout << atan(rad) << endl;
//----------------
//floor
    cout << "floor: ";
    cout << floor(x) << endl;
//ceil
    cout << "ceil: ";
    cout << ceil(x) << endl;
}

void vande_5(double a, double b) {
    cout << "ket qua: " << endl;
    if (a == 0)  {

        if (b == 0) {
            cout << "vo so nghiem";
        } else cout << "vo nghiem";

    } else cout << -b / a << endl;
}

void vande_6(double a, double b, double c) {
    if (a == 0) {
        //bx + c = 0
        if (b == 0) {
            if (c == 0) {
                cout << "vo so nghiem" << endl;

            } else cout << "vo nghiem" << endl;
        } else cout << -c / b;

    } else {
        // ax^2 + bx + c = 0
        double delta = (b * b) - (4 * a * c);

        if (delta < 0) {
            //nghiem phuc
            double thuc = -b / (2 * a);
            double ao = sqrt(-delta) / (2 * a);

            cout << "2 nghiem phuc: " << endl;
            cout << "x1 = " << thuc << " + " << ao << "i" << endl;
            cout << "x2 = " << thuc << " - " << ao << "i" << endl;

        } else if (delta == 0) {
            cout << "nghiem kep: x = " << -b / (2 * a) << endl;

        } else {
            cout << "2 nghiem thuc:" << endl;
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        }
    }
}

void vande_7(double a, double b, double c) {
    //max min
    double xmin;
    double xmax;

    if (a > b) {
        xmin = b;
        xmax = a;
    } else {
        xmin = a;
        xmax = b;
    }

    if (xmin > c) {
        xmin = c;
    }

    if (xmax < c) {
        xmax = c;
    }

    cout << "min: " << xmin << endl;
    cout << "max: " << xmax << endl << endl;

//-----min va max cua n so thuc-----
    int n;
    cout << "nhap n so thuc: ";
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

void vande_8(int duong, int am, int ko, int n, double num) {
    for (int i = 0; i < n; i++) {
        cout << "nhap so: ";
        cin >> num;

        if (num < 0) {
            am += 1;
        } else if (num > 0) {
            duong += 1;
        } else {
            ko += 1;
        }
    }

    cout << "so duong: " << duong << endl;
    cout << "so am: " << am << endl;
    cout << "so 0: " << ko << endl;
}

void vande_9(int n, int chan, int le) {
    vector<int> arr(n);
//nhap so
    for (int i = 0; i < n; i++) {
        cout << "nhap so: ";
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if ((arr[i] % 2) == 0) {
            chan += 1;
        } else le += 1;
    }

    cout << "so luong so chan: " << chan << endl;
    cout << "so luong so le: " << le << endl;
}

void vande_10(int so) {
    switch (so) {

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

    default:
        cout << "Lua chon khong hop le, vui long nhap lai so tu 0-20" << endl;
    }
}

void vande_11(double a, double b, double c, double A, double B, double C) {
    //tinh 3 dinh thuc
    //he: ax + by = c
    //    Ax + By = C
    double D = (a * B) - (A * b);
    double Dx = (c * B) - (C * b);
    double Dy = (a * C) - (A * c);

    //TH1
    if (D != 0) {
        cout << "he co mot nghiem: x = " << Dx / D << " ; y = " << Dy / D << endl;
    } else if (Dx == 0 && Dy == 0) {
        cout << "he co vo so nghiem" << endl;
    } else {
        cout << "he vo nghiem" << endl;
    }
}
void vande_12 (int m, int n, double kq = 0) {
    while (cin.fail() || n <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai n (n > 0, chi nhap so): ";
        cin >> n;
    }

    cout << "nhap m: ";
    cin >> m;
    while (cin.fail() || m < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai m (m >= 0, chi nhap so): ";
        cin >> m;
    }

    for (int i = 1; i <= n; i++) {
        kq += pow(i, m);
    }

    cout << "ket qua: " << kq;
}

void vande_13(int m, int n, int M, int i) {
    double kq = 0;
    while (i <= n) {
        if (kq + pow(i, m) <= M) {
            kq += pow(i, m);
        } else break;
        i += 1;
    }

    cout << "ket qua: " << kq;
}

//BT14
int dao(int x) {
    int latlai = 0;
    while (x > 0) {
        latlai = latlai * 10 + x % 10;
        x /= 10;
    }
    return latlai;
}

void vande_14(int A, int a, int max_trial, int dem, int PIN, int inPIN) {
    dem = 0;
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

        // Kiem tra PIN dao nguoc
        if (inPIN == dao(PIN)) {
            cout << "SECURITY ALERT! Ban da nhap PIN nguoc. The bi khoa!\n";
            return;
        }

        // PIN dung
        if (inPIN == PIN) {
            cout << "Xac thuc thanh cong!\n";
            break;
        }

        // PIN sai
        dem++;
        cout << "Sai PIN! Ban con " << max_trial - dem << " lan thu.\n";
    }

    // Qua so lan thu
    if (dem == max_trial) {
        cout << "Ban da nhap sai qua so lan cho phep. The bi khoa!\n";
        return;
    }

    cout << "nhap so tien can rut: ";
    cin >> a;

    // Rut tien
    if (a > A) {
        cout << "So tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
        return;
    } else {
        A -= a;
    }

    // In hoa don
    cout << "\n========= HOA DON ATM =========\n";
    cout << "So tien rut : " << a << " VND\n";
    cout << "So du con lai: " << A << " VND\n";
    cout << "Cam on quy khach da su dung dich vu!\n";
    cout << "================================\n";
}


int main() {
    //BT1
    cout << "BT1\n";
    double n;
    cout << "nhap vao canh 1 hinh vuong: ";
    cin >> n;
    vande_1(n);
    cout << endl;

    //BT2
    cout << "BT2\n";
    double d, r;
    cout << "nhap chieu dai: ";
    cin >> d;
    cout << "nhap chieu rong: ";
    cin >> r;
    vande_2(d, r);
    cout << endl;

    //BT3
    cout << "BT3\n";
    int a, b, c;
    cout << "nhap 3 so nguyen vao chieu dai rong cao: " << endl;
    cin >> a >> b >> c;
    vande_3(a, b, c);
    cout << endl;

    //BT4
    cout << "BT4\n";
    double x, y;
    cout << "nhap: " << endl;
    cin >> x >> y;
    cout << "tra ve: " << '\n' << endl;
    vande_4(x, y);
    cout << endl;

    //BT5
    cout << "BT5\n";
    double pt_a, pt_b;
    cout << "nhap: " << endl;
    cin >> pt_a >> pt_b;
    vande_5(pt_a, pt_b);
    cout << endl;

    //BT6
    cout << "BT6\n";
    double PT_a, PT_b , PT_c;
    cout << "nhap a, b, c:" << endl;
    cin >> PT_a >> PT_b >> PT_c;
    cout << "ket qua: " << '\n' << endl;
    vande_6(PT_a, PT_b, PT_c);
    cout << endl;

    //BT7
    cout << "BT7\n";
    double aa, bb, cc;
    cout << "nhap 3 so: " << endl;
    cin >> aa >> bb >> cc;
    vande_7(aa, bb, cc);
    cout << endl;

    //BT8
    cout << "BT8\n";
    int m;
    int am = 0, duong = 0, ko = 0;
    double num;

    cout << "nhap n so thuc: ";
    cin >> m;
    vande_8(duong, am, ko, m, num);
    cout << endl;

    //BT9
    cout << "BT9\n";
    int l;
    int chan = 0, le = 0;
    cout << "nhap vao n so nguyen: ";
    cin >> l;
    vande_9(l, chan, le);
    cout << endl;

    //BT10
    cout << "BT10\n";
    int so;
    cout << "Nhap so tu 0-20" << endl;
    cin >> so;
    vande_10(so);
    cout << endl;

    //BT11
    cout << "BT11\n";
    double u, i, p, U, I, P;
    cout << "nhap bien phuong trinh 1 (a, b, c): " << endl;
    cin >> u >> i >> p;
    cout << "nhap bien phuong trinh 2 (A, B, C): " << endl;
    cin >> U >> I >> P;
    vande_11(u, i, p, U, I, P);
    cout << endl;

    //BT12
    cout << "BT12\n";
    double kq = 0;
    int M, N;

    cout << "nhap n: ";
    cin >> N;
    vande_12(M, N, kq);
    cout << endl;
    cout << '\n';

    //BT13
    cout << "BT13\n";
    int f, g, F, h = 1;

    cout << "nhap n: ";
    cin >> g;
    while (cin.fail() || g <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai n (n > 0, chi nhap so): ";
        cin >> g;
    }

    cout << "nhap f: ";
    cin >> f;
    while (cin.fail() || f <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai m (m > 0, chi nhap so): ";
        cin >> f;
    }

    cout << "nhap F: ";
    cin >> F;
    while (cin.fail() || F <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai M (M > 0, chi nhap so): ";
        cin >> F;
    }
    vande_13(f, g, F, h);
    cout << endl;
    cout << '\n';

    //BT14
    cout << "BT14\n";
    int O, o, max_trial, dem = 0;
    int PIN, inPIN;

    cout << "so tien(VND) ban co: ";
    cin >> O;
    vande_14(O, o, max_trial, dem , PIN, inPIN);

    return 0;
}