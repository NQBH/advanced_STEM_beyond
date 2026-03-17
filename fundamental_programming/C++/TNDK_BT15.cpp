#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;

void bai1(double n) {
    while (n <= 0) {
        cout << "loi so, vui long nhap lai " << endl;
        cin >> n;
    }
    cout << "chu vi hinh vuong: " << n * 4 << endl;
    cout << "dien tich hinh vuong: " << n*n << endl;
}

void bai2(double d, double r) {
    while (d <= 0 || r <= 0) {
        cout << "loi so, vui long nhap lai " << endl;
        cin >> d >> r;
    }

    cout << "chu vi hinh chu nhat: " << (d + r) * 2 << endl;
    cout << "dien tich hinh chu nhat: " << d*r << endl;
    cout << "do dai duong cheo: " << sqrt(d * d + r * r) << endl;

}

void bai3(int a, int b, int c) {
    while (a <= 0 || b <= 0 || c <= 0) {
        cout << "loi so, vui long nhap lai";
        cin >> a >> b >> c;
    }

    if (a == b && b == c) {
        cout << "HLP" << endl;
        return ;
    } else {
        cout << "HHCN" << endl;
    }

    cout << "dien tich xung quanh: " << 2 * c*(a + b) << endl;
    cout << "dien tich toan phan: " << 2 * (a * b + b * c + c * a) << endl;
    cout << "duong cheo: " << sqrt(a * a + b * b + c * c) << endl;
    cout << "the tich: " << a*b*c << endl;

}

void bai4(double x) {
    if (x >= 0) {
        // 1. sq
        cout << "sqrt: " << sqrt(x) << endl;

        // 2. Ham pow can 2 tham so (vi du x mu 2)
        cout << "pow (x^2): " << pow(x, 2) << endl;

        // 3. Logarit
        cout << "log: " << log(x) << endl;
        cout << "log10: " << log10(x) << endl;
        cout << "exp: " << exp(x) << endl;

        // 4. Abs
        int a = 10;
        long b = -20;
        double c = -12.5;
        cout << "abs: " << abs(a) << endl;
        cout << "labs: " << labs(b) << endl;
        cout << "fabs: " << fabs(c) << endl;

        // 5. Luong giac (M_PI doi khi can define, nen dung acos(-1))
        double pi = acos(-1.0);
        double rad = pi / 6; // 30 do
        cout << "sin: " << sin(rad) << endl;
        cout << "cos: " << cos(rad) << endl;
        cout << "tan: " << tan(rad) << endl;

        // 6. Luong giac nguoc
        cout << "asin: " << asin(0.5) << endl;
        cout << "acos: " << acos(0.5) << endl;
        cout << "atan: " << atan(0.5) << endl;

        // 7. Lam tron
        double z = 3.7;
        cout << "floor: " << floor(z) << endl;
        cout << "ceil: " << ceil(z) << endl;

    } // <--- Đóng ngoặc của lệnh IF ở đây
}

void bai5(double a, double b) {
    // Xu ly cac truong hop
    if (a != 0) {
        // Truong hop a khac 0: co nghiem duy nhat
        double x = -b / a;
        cout << "Phuong trinh co nghiem duy nhat x = " << x << endl;
    } else {
        // Truong hop a = 0
        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem." << endl;
        } else {
            cout << "Phuong trinh vo nghiem." << endl;
        }
    }
}

void bai6(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Vo so nghiem" << endl;
            else cout << "Vo nghiem" << endl;
        } else {
            cout << "Nghiem x = " << -c / b << endl;
        }
    }
    else {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        }
        else if (delta == 0) {
            cout << "Nghiem kep x = " << -b / (2 * a) << endl;
        }
        else {
            // PHẦN BONUS +1
            double r = -b / (2 * a);
            double i = sqrt(-delta) / (2 * a);
            cout << "x1 = " << r << " + " << abs(i) << "i" << endl;
            cout << "x2 = " << r << " - " << abs(i) << "i" << endl;
        }
    }
}

void bai7(double a, double b, double c) {
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

void bai8(int duong, int am, int ko, int n, double num) {
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

void bai9(int n, int chan, int le) {
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
void bai10(int so) {
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
void bai11(double a, double b, double c, double A, double B, double C) {
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

void bai12(int n, int m) {
    long long Sm = 0;
    for (int i = 1; i <= n; i++) {
        Sm += pow(i, m);
    }

    cout << "Sm = " << Sm << endl;
}
void bai13(int n, int m, long long M, long long Sm = 0) {
    for (int i = 1; i <= n; i++) {
        long long term = pow(i, m);
        if (Sm + term > M)
            break;
        Sm += term;
    }

    cout << "Sm lon nhat <= M la: " << Sm << endl;
}

void bai14(long long A, long long a, string pinDung, string pinNhap, int max_trial, int trial = 0) {
    string pinDao = pinDung;
    reverse(pinDao.begin(), pinDao.end());

    while (trial < max_trial) {
        cout << "\nNhap ma PIN: ";
        cin >> pinNhap;

        if (pinNhap == pinDung) {
            cout << "Xac thuc thanh cong!\n";
            break;
        }

        if (pinNhap == pinDao) {
            cout << "CANH BAO SECURITY!\n";
            cout << "Da bao ve bao ve ngan hang!\n";
            return ;
        }

        trial++;
        if (trial == max_trial) {
            cout << "\nTHE DA BI KHOA!\n";
            cout << "Nhap sai PIN qua so lan cho phep!\n";
            cout << "Da bao ve bao ve ngan hang!\n";
            return ;
        }

        cout << "Ma PIN sai! Con " << (max_trial - trial) << " lan thu.\n";
    }

    if (a > A) {
        cout << "\nSo tien rut lon hon so du kha dung.\n";
        cout << "Ban bi ao tuong suc manh tai chinh a?\n";
        return ;
    }

    A -= a;

    time_t now = time(0);
    cout << "\n========== HOA DON ATM ==========\n";
    cout << "Thoi gian: " << ctime(&now);
    cout << "So tien rut: " << a << " VND\n";
    cout << "So du con lai: " << A << " VND\n";
    cout << "Cam on quy khach da su dung dich vu!\n";
    cout << "=================================\n";
}
int main() {
    //b1
    double n;
    cout << "nhap vao canh 1 hinh vuong: ";
    cin >> n;
    bai1(n);

    //b2
    double d, r;
    cout << "nhap chieu dai: ";
    cin >> d;
    cout << "nhap chieu rong: ";
    cin >> r;
    bai2(d, r);

    //b3
    int a, b, c;
    cout << "nhap 3 so nguyen vao chieu dai rong cao: " << endl;
    cin >> a >> b >> c;
    bai3(a, b, c);

    //b4
    double x;
    cout << "Nhap x: ";
    cin >> x;
    bai4(x);

    //b5
    double q, w;
    cout << "Nhap he so a: ";
    cin >> q;
    cout << "Nhap he so b: ";
    cin >> w;
    bai5(q, w);

    //b6
    double e, R, t;
    cout << "Nhap he so a, b, c: ";
    cin >> e >> R >> t;

    cout << fixed << setprecision(2);
    bai6(e, R, t);

    //b7
    double y, u, i;
    //nhap abc
    cout << "nhap 3 so: " << endl;
    cin >> y >> u >> i;
    bai7(y, u, i);

    //b8
    int m;
    int am = 0, duong = 0, ko = 0;
    double num;

    cout << "nhap n so thuc: ";
    cin >> m;
    bai8(duong, am, ko, m, num);

    //b9
    int l;
    int chan = 0, le = 0;
    cout << "nhap vao n so nguyen: ";
    cin >> l;
    bai9(l, chan, le);

    //b10
    int so;
    cout << "Nhap so tu 0-20" << endl;
    cin >> so;
    bai10(so);

    //b11
    double k, j, p, U, I, P;
    cout << "nhap bien phuong trinh 1 (a, b, c): " << endl;
    cin >> k >> j >> p;
    cout << "nhap bien phuong trinh 2 (A, B, C): " << endl;
    cin >> U >> I >> P;
    bai11(k, j, p, U, I, P);

    //b12
    int N, z;
    cout << "Nhap n: ";
    cin >> N;
    cout << "Nhap m: ";
    cin >> z;
    bai12(N, z);

    //b13
    int s, g;
    long long G;
    long long Sm = 0;

    cout << "Nhap n: ";
    cin >> s;
    cout << "Nhap m: ";
    cin >> g;
    cout << "Nhap M: ";
    cin >> G;
    bai13(s, g, G, Sm);

    //b14
    long long A, v;
    string pinDung, pinNhap;
    int max_trial;
    int trial = 0;

    cout << "Nhap so du tai khoan (A): ";
    cin >> A;
    cout << "Nhap so tien can rut (a): ";
    cin >> v;
    cout << "Nhap ma PIN dung (6 chu so): ";
    cin >> pinDung;
    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;
    bai14(A, v, pinDung, pinNhap, max_trial, trial = 0);
}