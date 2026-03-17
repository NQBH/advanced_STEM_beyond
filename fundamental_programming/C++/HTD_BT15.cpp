#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// bai 1
void bai1(float a) {
    if (a <= 0) cout << "Wrong input.\n";
    else {
        float C = 4 * a, S = a * a;
        cout << "Chu vi C = " << C << '\n';
        cout << "Dien tich S = " << S << '\n';
    }
}

// bai 2
void bai2(float a, float b) {
    if (a <= 0 || b <= 0) cout << "Wrong input.\n";
    else {
        float C = 2 * (a + b), S = a * b, d = sqrt(a * a + b * b);
        cout << "Chu vi C = " << C << '\n';
        cout << "Dien tich S = " << S << '\n';
        cout << "Duong cheo d = " << d << '\n';
    }
}

// BT 3
void bai3(float a, float b, float c) {
    if (a <= 0 || b <= 0 || c <= 0) cout << "-1\n";
    else {
        if (a == b && b == c) {
            cout << "HLP\n";
            float Sxq = 4 * a * a, Stp = 6 * a * a, V = a * a * a, d = sqrt(3) * a;
            cout << "Dien tich xung quanh Sxq = " << Sxq << '\n';
            cout << "Dien tich toan phan Stp = " << Stp << '\n';
            cout << "The tich V = " << V << '\n';
            cout << "Duong cheo d = " << d << '\n';
        } else {
            cout << "HHCN\n";
            float Sxq = 2 * (a + b) * c, Stp = 2 * (a * b + b * c + c * a), V = a * b * c, d = sqrt(a * a + b * b + c * c);
            cout << "Dien tich xung quanh Sxq = " << Sxq << '\n';
            cout << "Dien tich toan phan Stp = " << Stp << '\n';
            cout << "The tich V = " << V << '\n';
            cout << "Duong cheo d = " << d << '\n';
        }
    }
}

// bt 4
void bai4(double x, double y, int A, long long B, double C) {
    if (x >= 0) cout << sqrt(x) << '\n';
    else cout << "Error.\n";

    if (x > 0) cout << pow(x, y) << '\n';
    else cout << "Error.\n";

    if (x > 0) {
        cout << log(x) << '\n';
        cout << log10(x) << '\n';
    }

    cout << abs(A) << '\n';
    cout << fabs(B) << '\n';
    cout << fabs(C) << '\n';

    cout << cos(x) << '\n';
    cout << sin(x) << '\n';
    cout << tan(x) << '\n';
    if (tan(x) != 0) cout << 1.0 / tan(x) << '\n';

    if (x >= -1 && x <= 1) cout << acos(x) << '\n';
    else cout << "Error.\n";

    if (x >= -1 && x <= 1) cout << asin(x) << '\n';
    else cout << "Error.\n";

    cout << atan(x) << '\n';
    cout << floor(x) << '\n';
    cout << ceil(x) << '\n';
}

// bai 5: ax + b = 0
void bai5(double a, double b) {
    if (a == 0) {
        if (b == 0) cout << "Vo so nghiem.\n";
        else cout << "Vo nghiem.\n";
    } else {
        if (b == 0) cout << "x = 0.\n";
        else cout << "x = " << -b / a << "\n";
    }
}

// bai 6: ax^2 + bx + c = 0
void bai6(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Vo so nghiem.\n";
            else cout << "Vo nghiem.\n";
        } else {
            if (c == 0) cout << "x = 0.\n";
            else cout << "x = " << -c / b << "\n";
        }
    } else {
        double Delta = b * b - 4 * a * c;
        if (Delta < 0) {
            cout << "Phuong trinh co 2 nghiem phuc x1 = " << -b / (2 * a) << " - i" << sqrt(fabs(Delta)) / (2 * a) << " & ";
            cout << "x2 = " << -b / (2 * a) << " + i" << sqrt(fabs(Delta)) / (2 * a) << '\n';
        } else if (Delta == 0) {
            cout << "Phuong trinh co nghiem kep x = " << -b / (2 * a) << '\n';
        } else {
            cout << "Phuong trinh co 2 nghiem thuc x1 = " << (-b - sqrt(Delta)) / (2 * a) << " & x2 = " << (-b + sqrt(Delta)) / (2 * a) << '\n';
        }
    }
}

// bt 7: tim max min
void bai7(int n) {
    if (n <= 0) return;
    float temp;
    cout << "Nhap so thu 1: ";
    cin >> temp;

    float max = temp;
    float min = temp;

    for (int i = 2; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> temp;
        if (temp > max) max = temp;
        if (temp < min) min = temp;
    }

    cout << "So lon nhat: " << max << endl;
    cout << "So nho nhat: " << min << endl;
}

// bai 8
void bai8(int n) {
    int dem0 = 0, demAm = 0, demDuong = 0;
    float temp;

    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> temp;
        if (temp == 0) dem0++;
        else if (temp < 0) demAm++;
        else demDuong++;
    }

    cout << "So luong so 0: " << dem0 << endl;
    cout << "So luong so am: " << demAm << endl;
    cout << "So luong so duong: " << demDuong << endl;
}

// bai 9
void bai9(int n) {
    int demChan = 0, demLe = 0;
    int temp;

    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> temp;
        if (temp % 2 == 0) demChan++;
        else demLe++;
    }

    cout << "Co " << demChan << " so chan." << endl;
    cout << "Co " << demLe << " so le." << endl;
}

// bai 10
void bai10(int n) {
    switch (n) {
    case 0:  cout << "zero\n"; break;
    case 1:  cout << "one\n"; break;
    case 2:  cout << "two\n"; break;
    case 3:  cout << "three\n"; break;
    case 4:  cout << "four\n"; break;
    case 5:  cout << "five\n"; break;
    case 6:  cout << "six\n"; break;
    case 7:  cout << "seven\n"; break;
    case 8:  cout << "eight\n"; break;
    case 9:  cout << "nine\n"; break;
    case 10: cout << "ten\n"; break;
    case 11: cout << "eleven\n"; break;
    case 12: cout << "twelve\n"; break;
    case 13: cout << "thirteen\n"; break;
    case 14: cout << "fourteen\n"; break;
    case 15: cout << "fifteen\n"; break;
    case 16: cout << "sixteen\n"; break;
    case 17: cout << "seventeen\n"; break;
    case 18: cout << "eighteen\n"; break;
    case 19: cout << "nineteen\n"; break;
    case 20: cout << "twenty\n"; break;
    default: cout << "So khong hop le\n";
    }
}

// bai 11
void bai11(float a1, float b1, float c1, float a2, float b2, float c2) {
    float D = a1 * b2 - a2 * b1;
    float Dx = c1 * b2 - c2 * b1;
    float Dy = a1 * c2 - a2 * c1;

    if (D != 0) {
        cout << "He phuong trinh co nghiem duy nhat:\n";
        cout << "x = " << Dx / D << "\ny = " << Dy / D << endl;
    } else {
        if (Dx == 0 && Dy == 0) cout << "He phuong trinh co vo so nghiem.\n";
        else cout << "He phuong trinh vo nghiem.\n";
    }
}

// bai 12
void bai12(int m, int n) {
    double Sm = 0;
    if (m == 0) Sm = n;
    else for (int i = 1; i <= n; ++i) Sm += pow(i, m);
    cout << "Sm = " << Sm << '\n';
}

// bai 13
void bai13(int m, double M) {
    double Sm = 0, term = 1;
    int i = 1;
    while (Sm + term <= M) {
        Sm += term;
        ++i;
        term = pow(i, m);
    }
    cout << "Sm = " << Sm << '\n';
}

// bai 14
void bai14(double A, string true_PIN, int max_trial) {
    string input_PIN;
    bool ok = false;
    double a;

    for (int i = 1; i <= max_trial; ++i) {
        cout << "\nEnter PIN: ";
        cin >> input_PIN;
        if (input_PIN == true_PIN) {
            ok = true;
            break;
        } else cout << "Wrong PIN. Re-enter PIN.\n";
    }

    if (ok) {
        cout << "Ma PIN dung. Cho phep rut tien.\nVui long nhap so tien ban muon rut: ";
        cin >> a;
        if (a > A) cout << "So tien rut lon hon so du kha dung. Ban bi ao tuong suc manh tai chinh a?\n";
        else {
            cout << "Ban da rut thanh cong " << a << " VND.\nSo du kha dung: " << A - a << " VND.\n";
            cout << "Ban muon in hoa don? (Yes/No)? ";
            string bill;
            cin >> bill;
            if (bill == "Yes") cout << "Dang in hoa don. Vui long doi de nhan ca hoa don, cash, & the.\n";
            else cout << "Vui long doi de nhan cash, & the.\n";
            cout << "Cam on ban da giao dich tai ngan hang X.\nVui long danh gia chat luong dich vu.\n";
        }
    } else cout << "Ban da bi khoa the. Vui long lien he chi nhanh ngan hang X gan nhat de ho tro nhan lai the.\n";
}

int main() {
    /* ----- CHAY THU TUNG BAI BANG CACH BO COMMENT ----- */

    /*
    // test bai 1
    float a;
    cout << "Nhap a: "; cin >> a;
    bai1(a);
    

    
    // test bai 2
    float a2, b2;
    cout << "Nhap a, b: "; cin >> a2 >> b2;
    bai2(a2, b2);
    

    
    // test bai 3
    float a3, b3, c3;
    cout << "Nhap a, b, c: "; cin >> a3 >> b3 >> c3;
    bai3(a3, b3, c3);

    
    // test bai 4
    double x, y, C; int A; long long B;
    cout << "Nhap x, y, A(int), B(long long), C(double): ";
    cin >> x >> y >> A >> B >> C;
    bai4(x, y, A, B, C);
    

    
    // test bai 5
    double a5, b5;
    cout << "Nhap a, b: "; cin >> a5 >> b5;
    bai5(a5, b5);
    

    
    // test bai 6
    double a6, b6, c6;
    cout << "Nhap a, b, c: "; cin >> a6 >> b6 >> c6;
    bai6(a6, b6, c6);
    

    
    // test bai 7, 8, 9, 10
    int n;
    cout << "Nhap n: "; cin >> n;
    bai7(n);
    bai8(n);
    bai9(n);
    bai10(n);
    /*
    
    */
    
    // test bai 11
    float a1, b1, c1, a2, b2, c2;
    cout << "Nhap a1, b1, c1: "; cin >> a1 >> b1 >> c1;
    cout << "Nhap a2, b2, c2: "; cin >> a2 >> b2 >> c2;
    bai11(a1, b1, c1, a2, b2, c2);
    

    
    // test bai 12
    int m, n12;
    cout << "Nhap m, n: "; cin >> m >> n12;
    bai12(m, n12);
    

    
    // test bai 13
    int m13; double M;
    cout << "Nhap m, M: "; cin >> m13 >> M;
    bai13(m13, M);
    

    // test bai 14 (dang mo code bai nay)
    double soDu;
    string pin;
    int soLan;
    cout << "Nhap so du, ma PIN, so lan nhap toi da: ";
    cin >> soDu >> pin >> soLan;
    bai14(soDu, pin, soLan);
    
    return 0;
}