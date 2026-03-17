#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

void BT1(float canh,  float C, float S) {
    C = canh * 4 ;
    S = pow(canh, 2);
    cout << "chu vi = " << C << endl ;
    cout << "dien tich = " << S << endl ;
}

void BT2(float chieudai2, float chieurong2, float W, float K, float duongcheo) {
    W = 2 * (chieudai2 + chieurong2);
    K = chieudai2 * chieurong2 ;
    duongcheo = sqrt(pow(chieudai2, 2) + pow(chieurong2, 2));
    cout << "chu vi = " << W << endl ;
    cout << "dien tich = " << K << endl ;
    cout << "duongcheo = " << duongcheo << endl ;
}

void BT3(int a, int b, int c ) {
    if (a <= 0 || b <= 0 || c <= 0 ) {
        cout << "-1" ;
    }
    if ( a == b && b == c ) {
        cout << "HLP" ;
    }
    else {
        cout << "HHCN" << endl ;
        int Sxq = 2 * (a + b ) * c ;
        int Stp = 2 * (a * b + b * c + c * a) ;
        double duongcheo = sqrt(a * a + b * b + c * c);
        int thetich = a * b * c ;
        cout << "Dien tich xung quanh = " << Sxq << endl ;
        cout << "Dien tich toan phan =" << Stp << endl ;
        cout << "duong cheo = " << duongcheo << endl ;
        cout << "the tich = " << thetich << endl ;
    }
}

void BT4(double x, double y) {
    if (x >= 0) {
        // sqrt
        cout << "sqrt " << sqrt (x ) << endl ;
        // pow
        cout << "pow " << pow (x, 2) << endl ;
        // log
        cout << "log " << log (x ) << endl ;
        // exp
        cout << "exp " << exp (x ) << endl ;
        // log10
        cout << "log10 " << log10 (x ) << endl ;
        // int
        int absX = abs (x) ;
        cout << "abs(int x) " << absX << endl ;
        // long
        long labsX = labs (x) ;
        cout << "labs (int x) " << labsX << endl ;
        // double
        double fabsX = fabs (x) ;
        cout << "fabs (int x) " << fabsX << endl ;
        // sin
        double pi = acos (-1.0) ;
        double rad = pi / 6 ; // 30 do
        cout << "sin " << sin (rad) << endl ;
        // cos
        cout << "cos " << cos (rad) << endl ;
        // tan
        cout << "tan " << tan (rad) << endl ;
        // asin
        cout << "asin " << asin (0.5) << endl ;
        // acos
        cout << "acos " << acos (0.5) << endl ;
        // atan
        cout << "atan " << atan (0.5) << endl ;
        // floor
        double z = 3.7 ;
        cout << "floor " << floor (z) << endl ;
        // ceil
        cout << "ceil " << ceil (z) << endl ;
    }
}

void BT5(double bt_a, double bt_b) {
    if (bt_a == 0 ) {
        if (bt_b == 0 ) {
            cout << "phuong trinh vo so nghiem " << endl ;
        } else {
            cout << "phuong trinh vo nghiem " << endl ;
        }
    } else {
        double x = -bt_b / bt_a ;
        cout << "phuong trinh co nghiem x = " << x << endl ;
    }
}

void BT6(double a, double b, double c) {
    if (a == 0 ) {
        if (b == 0 ) {
            cout << "phuong trinh vo so nghiem " << endl ;
        } else {
            cout << "phuong trinh vo nghiem " << endl ;
        }
    } else {
        double delta = b * b - 4 * a * c ;
        if (delta < 0 ) {
            cout << "phuong trinh vo nghiem " << endl ;
        } else if (delta == 0 ) {
            double x = -b / (2 * a) ;
            cout << "phuong trinh co nghiem kep x = " << x << endl ;
        } else {
            double x1 = (-b + sqrt(delta)) / (2 * a) ;
            double x2 = (-b - sqrt(delta)) / (2 * a) ;
            cout << "phuong trinh co 2 nghiem phan biet x1 = " << x1 << ", x2 = " << x2 << endl ;
        }
    }
    // Bonus +1: Giai phuong trinh bac 2 co nghiem phuc
    double delta = b * b - 4 * a * c;
    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Phuong trinh co 2 nghiem thuc phan biet:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (delta == 0) {
        double x = -b / (2 * a);
        cout << "Phuong trinh co nghiem kep thuc: x = " << x << endl;
    }
    else {
        // Truong hop Delta < 0: Nghiem phuc (Bonus +1)
        double phanThuc = -b / (2 * a);
        double phanAo = sqrt(-delta) / (2 * a);

        cout << "Phuong trinh co 2 nghiem phuc:" << endl;
        // Nghiem phuc co dang: a + bi va a - bi
        cout << "x1 = " << phanThuc << " + " << abs(phanAo) << "i" << endl;
        cout << "x2 = " << phanThuc << " - " << abs(phanAo) << "i" << endl;
    }
}

void BT7(int pt_x ) {
    int max_val, min_val;
    for (int i = 0; i < 3; i++) {
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> pt_x;

        if (i == 0) {
            max_val = min_val = pt_x;
        } else {
            if (pt_x > max_val)
                max_val = pt_x;
            if (pt_x < min_val)
                min_val = pt_x;
        }
    }

    cout << "So lon nhat la: " << max_val << endl;
    cout << "So nho nhat la: " << min_val << endl;
}

void BT8(double n) {
    if (n == 0) {
        double a;
        cout << "Nhap so thuc: ";
        cin >> a;
        cout << "So am:" << endl;
        cout << "So duong:" << endl;
        cout << "So  0 :" << endl;
    }

    double a;
    int demAm = 0, demDuong = 0, demZero = 0;

    cout << "Nhap " << n << " so thuc: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < 0) demAm++;
        else if (a > 0) demDuong++;
        else demZero++;
    }

    cout << "So am: " << demAm << endl;
    cout << "So duong: " << demDuong << endl;
    cout << "So  0 : " << demZero << endl;
}

void BT9(int n) {
    int chan = 0, le = 0;
    for (int i = 0; i < n; i++)
    {   cout << "nhap so thu " << i + 1 << ": ";
        int x;
        cin >> x;
        if (x % 2 == 0) {
            chan++;
        }
        else {
            le++;
        }
    }
    cout << "So chan: " << chan << ", So le: " << le << endl;
}

void BT10(int n) {
    switch (n) {
    case 0:
        cout << "ZERO";
        break;
    case 1:
        cout << "ONE";
        break;
    case 2:
        cout << "TWO";
        break;
    case 3:
        cout << "THREE";
        break;
    case 4:
        cout << "FOUR";
        break;
    case 5:
        cout << "FIVE";
        break;
    case 6:
        cout << "SIX";
        break;
    case 7:
        cout << "SEVEN";
        break;
    case 8:
        cout << "EIGHT";
        break;
    case 9:
        cout << "NINE";
        break;
    case 10:
        cout << "TEN";
        break;
    case 11:
        cout << "ELEVEN";
        break;
    case 12:
        cout << "TWELVE";
        break;
    case 13:
        cout << "THIRTEEN";
        break;
    case 14:
        cout << "FOURTEEN";
        break;
    case 15:
        cout << "FIFTEEN";
        break;
    case 16:
        cout << "SIXTEEN";
        break;
    case 17:
        cout << "SEVENTEEN";
        break;
    case 18:
        cout << "EIGHTEEN";
        break;
    case 19:
        cout << "NINETEEN";
        break;
    case 20:
        cout << "TWENTY";
        break;
    default:
        cout << "SO LUONG PHAN TU KHONG HOP LE";
        break;
    }
}

void BT11(double a, double b, double c, double A, double B, double C) {
    double D = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;
    if (D != 0) {
        cout << fixed << setprecision(2) ;
        cout << "nghiem duy nhat\n";
        cout << "x = " << Dx / D << endl;
        cout << "y = " << Dy / D << "\n";
    }
    else {
        if (Dx == 0 && Dy == 0) {
            cout << "he phuong trinh vo so nghiem\n";
        }
        else {
            cout << "he phuong trinh vo nghiem\n";
        }
    }
}

void BT12(int n, int m) {
    double Sm = 0;
    for (int i = 1; i <= n; i++) {
        Sm += pow(i, m);
    }
    cout << "Sm = " << Sm << endl;
}

void BT13(int n , int m , int M) {
    long long Sm = 0;
    for (int i = 1; i <= n; i++) {
        long long term = pow(i, m);
        if (Sm + term > M) {
            break;
        }
        Sm += term;
    }
    cout << "Sm lon nhat <= M la: " << Sm << endl;
}

void BT14(long long a, long long A, int max_traial, string pin_real) {
    string pin_input;
    int traial = 0;
    bool authenticated = false;
    string reverse_pin = pin_real;
    reverse(reverse_pin.begin(), reverse_pin.end());
    while (traial < max_traial) {
        cout << "nhap ma PIN: ";
        cin >> pin_input;
        if (pin_input == reverse_pin) {
            cout << "SECURITY ALERT" << endl;
            break;
        }
        if (pin_input == pin_real) {
            authenticated = true;
            break;
        }
        traial++;
    }
    if (!authenticated) {
        cout << "the da bi khoa do nhap sai qua so lan quy dinh!" << endl;
        return;
    }
    if (a > A) {
        cout << "So du khong du de thuc hien giao dich!" << endl;
    } else {
        A -= a;
        cout << "Rut tien thanh cong! So du con lai: " << A << endl;
    }
    cout << "\n ban co muon in hoa don khong? (Y/N): ";
    char choice;
    if (cin >> choice && (choice == 'Y' || choice == 'y')) {
        cout << "\n=========== Hoa don ATM ===========" << endl;
        cout << "ngan hang: ABC Bank" << endl;
        cout << "so tai khoan: 123456789" << endl;
        cout << "So tien rut: " << a << endl;
        cout << "So du tai khoan: " << A << endl;
        cout << "trang thai giao dich: thanh cong" << endl;
        cout << "cam on quy khach da su dung dich vu!" << endl;
    }
    else {
        cout << "\n giao dich ket thuc. khong xuat hoa don!" << endl;
    }
}
int main() {
    // BT1
    float canh1, C1, S1;
    cout << "nhap canh hinh vuong" ;
    cin >> canh1;
    BT1(canh1  , C1, S1);

    // // BT2
    float chieudai2;
    float chieurong2;
    float C2, S2 ;
    float duongcheo ;
    cout << "nhap chieu dai" ;
    cin >> chieudai2 ;
    cout << "nhap chieu rong";
    cin >> chieurong2 ;
    BT2(chieudai2, chieurong2, C2, S2, duongcheo);

    // BT3
    int a3, b3, c3;
    cout << "nhap canh a, b, c" ;
    cin >> a3 >> b3 >> c3;
    BT3(a3, b3, c3);

    // BT4
    double x4, y4;
    cout << "nhap x, y" ;
    cin >> x4 >> y4;
    BT4(x4, y4);

    // BT5
    double a5, b5 ;
    cout << "nhap a, b: " ;
    cin >> a5 >> b5 ;
    BT5(a5, b5);

    // BT6
    double a6 , b6 , c6 ;
    cout << "nhap a , b , c: " ;
    cin >> a6 >> b6 >> c6 ;
    cout << "giai phuong trinh bac 2 ax^2 + bx + c = 0" << endl ;
    BT6(a6, b6, c6);

    //BT7
    int x7;
    BT7(x7);


    //BT8
    double n8;
    cout << "Nhap so luong so thuc: " ;
    cin >> n8;
    BT8(n8);

    //BT9
    int n9;
    cout << "nhap so luong phan tu : " ;
    cin >> n9;
    BT9(n9);

    //BT10
    int n10;
    cout << "nhap so luong phan tu : ";
    cin >> n10;
    BT10(n10);

    //BT11
    double a11, b11, c11, A11, B11, C11;
    cout << "nhap a, b, c , A, B, C: " ;
    cin >> a11 >> b11 >> c11 >> A11 >> B11 >> C11;
    BT11(a11, b11, c11, A11, B11, C11);

    //BT12
    int n12, m12;
    long long Sm = 0;
    cout << "nhap so n" ;
    cin >> n12;
    cout << "nhap so m" ;
    cin >> m12;
    BT12(n12, m12);

    //BT13
    int n13, m13, M13;
    long long M = 0;
    Sm = 0;
    cout << "nhap so n" ;
    cin >> n13;
    cout << "nhap so m" ;
    cin >> m13;
    cout << "nhap so M";
    cin >> M13;
    BT13(n13, m13, M13);

    //BT14
    long long A , a;
    string pin_real ;
    int max_traial ;
    cout << "nhap so du ban dau(A): ";
    cin >> A;
    cout << "nhap so tien can rut (a): ";
    cin >> a;
    cout << "nhap ma PIN (6 chu so): ";
    cin >> pin_real;
    cout << "nhap so lan thu toi da :";
    cin >> max_traial ;
    BT14(a, A, max_traial, pin_real);
}



