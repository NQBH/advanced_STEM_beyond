#include <bits/stdc++.h>
#include <cmath>
#include <string>

using namespace std;

// BT1: Nhập cạnh HV _ tính cv,s
void BT1(int canh) {
    cout << "CV: " << canh * 4 << '\n';
    cout << "S: " << canh * canh;
}

// BT2: Nhập cd,cr _ tính cv,s, đường chéo hcn
void BT2(int cd, int cr) {
    cout << "CV: " << (cd + cr) * 2 << '\n';
    cout << "S: " << cd * cr << '\n';
    cout << "DC: " << (double)sqrt(pow(cd, 2) + pow(cr, 2));
}

// BT3: Nhập abc _ ktra HLP, HHCN _ tính Sxq, Stp, V, đường chéo
void BT3(int a, int b, int c) {
    int Sxq, Stp, V;
    double Dc;
    Sxq = 2 * (a * c + b * c);
    Stp = 2 * (a * c + b * c + a * b);
    V = a * b * c;
    Dc = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
    if (a == b && b == c && a > 0) {
        cout << "HLP: " << '\n';
        cout << "Sxq: " << Sxq << '\n';
        cout << "Stp: " << Stp << '\n';
        cout << "V: " << V << '\n';
        cout << "Dc: " << Dc << '\n';
    } else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN: " << '\n';
        cout << "Sxq: " << Sxq << '\n';
        cout << "Stp: " << Stp << '\n';
        cout << "V: " << V << '\n';
        cout << "Dc: " << Dc << '\n';
    }
}

// BT4: SGK
void BT4(double x, double y) {
    //Hàm căn bậc 2 (sqrt)
    if (x >= 0) {
        cout << "1.sqrt = " << sqrt(x) << endl;
    } else {
        cout << "Không tính được" << endl;
    }
    //Hàm lũy thừa (pow)
    cout << "2. pow = " << pow(x, y) << endl;
    //Hàm e^x (exp)
    cout << "3. exp = " << exp(x) << endl;
    //Hàm logarit tự nhiên (log)
    if (x > 0) {
        cout << "4. log = " << log(x) << endl;
    } else {
        cout << "Không tính được" << endl;
    }
    //Hàm logarit cơ số 10
    if (x > 0) {
        cout << "5. log10 = " << log10(x) << endl;
    } else {
        cout << "Không tính được" << endl;
    }
    //Hàm trị tuyệt đối (abs, labs, fabs)
    cout << "abs(int) = " << abs(int(x)) << endl;
    cout << "labs(long) = " << labs(long(x)) << endl;
    cout << "fabs = " << fabs(x) << endl;
    //Hàm lượng giác (cos, sin, tan)
    cout << "cos = " << cos(x) << endl;
    cout << "sin = " << sin(x) << endl;
    cout << "tan = " << tan(x) << endl;
    //Hàm lượng giác ngược (acos, asin, atan)
    if (x >= -1 && x <= 1) {
        cout << "acos = " << acos(x) << endl;
        cout << "asin = " << asin(x) << endl;
    } else {
        cout << "Không tính được" << endl;
    }
    cout << "atan = " << atan(x) << endl;
    //Hàm tính số nguyên lớn nhất (floor, ceil)
    cout << "floor = " << floor(x) << endl;
    cout << "ceil = " << ceil(x) << endl;
}

// BT5: giải phương trình bậc nhất ax + b = 0
void BT5(double a, double b) {
    if (a != 0) cout << (double) - b / a;
    else if (b != 0) cout << "Pt vô nghiệm";
    else if (b == 0) cout << "Pt vô số nghiệm";
    else if (a == 0)  cout << 0;
}

// BT6: giải phương trình bậc 2 ax^2 + bx + c = 0
void BT6(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Phuong trinh co vo so nghiem" << endl;
            else cout << "Phuong trinh vo nghiem" << endl;
        } else {
            cout << "Phuong trinh co nghiem: x = " << -c / b << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep: x = " << x << endl;
        } else {
            cout << "Phuong trinh vo nghiem thuc" << endl;
        }
    }
}

// BT7: tìm 3 số thực cho trước
int Max_Min(double a, double b) {
    if (a >= b) return a;
    else return b;
}
void BT7(long long t) {
    double arr[t], somax, somin; // Mảng arr có 7 ptu
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }
    somax = arr[0];
    somin = arr[0];
    for (int i = 0; i < t; i++) {
        somax = Max_Min(somax, arr[i]);
        somin = -Max_Min(-somin, -arr[i]);
    }
    cout << "Max: " << somax << "\n";
    cout << "Min: " << somin << '\n';
}

// BT8: Nhập n _ đếm số 0, âm, dương
void BT8(long long t) {
    long long sduong, sam, s0;
    s0 = 0;
    sduong = 0;
    sam = 0;
    while (t--) {
        long long k;
        cin >> k;
        if (k == 0) {
            s0++;
        } else if (k > 0) {
            sduong++;
        } else sam++;
    }
    cout << "Số số 0: " << s0 << '\n';
    cout << "Số số âm: " << sam << '\n';
    cout << "Số số dương: " << sduong << '\n';
}

// BT9: Nhập n _ đếm số chẵn, lẻ
void BT9(long long t) {
    int sle, schan;
    sle = 0;
    schan = 0;
    while (t--) {
        long long k;
        cin >> k;
        if (k % 2 == 0) schan++;
        else sle++;
    }
    cout << "Số số chẵn: " << schan << '\n';
    cout << "Số số lẻ: " << sle << '\n';
}

// BT10:
void BT10(long long n) {
    switch (n) {
    case 0:
        cout << "Zero";
        break;
    case 1:
        cout << "One";
        break;
    case 2:
        cout << "Two";
        break;
    case 3:
        cout << "Three";
        break;
    case 4:
        cout << "Four";
        break;
    case 5:
        cout << "Five";
        break;
    case 6:
        cout << "Six";
        break;
    case 7:
        cout << "Seven";
        break;
    case 8:
        cout << "Eight";
        break;
    case 9:
        cout << "Nine";
        break;
    case 10:
        cout << "Ten";
        break;
    case 11:
        cout << "Eleven";
        break;
    case 12:
        cout << "Twelve";
        break;
    case 13:
        cout << "Thirteen";
        break;
    case 14:
        cout << "Fourteen";
        break;
    case 15:
        cout << "Fifteen";
        break;
    case 16:
        cout << "Sixteen";
        break;
    case 17:
        cout << "Seventeen";
        break;
    case 18:
        cout << "Eighteen";
        break;
    case 19:
        cout << "Nineteen";
        break;
    case 20:
        cout << "Twenty";
        break;
    default:
        if (n < 0) {
            cout << "Khong hop le" << endl;
        } else {
            cout <<  "Khong nhap so > 20" << endl;
        }
        break;
    }
    cout << endl;
}

// BT11: giải hệ phương trình tuyến tính bậc 2
void BT11(double a111, double b111, double c111, double a112, double b112, double c112) {
    double D  = a111 * b112 - a112 * b111;
    double Dx = c111 * b112 - c112 * b111;
    double Dy = a111 * c112 - a112 * c111;
    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He co nghiem duy nhat:" << endl;
        cout << "x = " << x << ", y = " << y << endl;
    } else {
        if (Dx == 0 && Dy == 0) {
            cout << "He co vo so nghiem" << endl;
        } else {
            cout << "He vo nghiem" << endl;
        }
    }
}

// BT12:
void BT12(long long n, long long m) {
    double s = 0;
    for (int i = 1; i <= n; i++) {
        s += pow(i, m);
    }
    cout << s;
}

// BT13:
void BT13(long long n, long long m, long long M) {
    int s = 1, i = 1;
    while (s <= M) {
        i++;
        if (i <= n) {
            if (s + pow(i, m) <= M) {
                if (s + pow(i, m) == M) {
                    s += pow(i, m);
                    break;
                } else s += pow(i, m);
            } else break;
        } else break;
    }
    cout << s;
}

// BT14:
int BT14(double a, double b, long long max_trial, string s, string pin) {
    while (max_trial--) {
        if (max_trial != 0) {
            cout << "Ma PIN: ";
            cin >> s;
            int demx = 0, demn = 0;
            for (int i = 0; i < pin.length(); i++) {
                if (pin[i] != s[i]) break;
                else demx += 1;
            }
            int k = pin.length();
            for (int i = 0; i < pin.length(); i++) {
                if (pin[i] != s[k - 1]) break;
                else {
                    demn += 1;
                    k--;
                }
            }
            if (demn == pin.length()) {
                cout << "Police will come in 30s";
                break;
            } else {
                if (demx == pin.length()) {
                    if (b > a) {
                        cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?";
                        return 0;
                    } else {
                        cout << "Rut thanh cong " << b << " VND" << '\n';
                        cout << "So du con lai: " << a - b << " VND" << '\n';
                        return 0;
                    }
                } else cout << "Nhap lai ma PIN _ ";
            }
        } else {
            cout << "The bi lock. Di lam lai the moi =)";
            break;
        }
    }
    return 0;
}

int main() {
    // BT1:
    cout << "BT1" << '\n';
    int canh;
    cin >> canh;
    BT1(canh);
    cout << '\n';

    // BT2:
    cout << "BT2" << '\n';
    int cd, cr;
    cin >> cd >> cr;
    BT2(cd, cr);
    cout << '\n';


    // BT3:
    cout << "BT3" << '\n';
    int a1, b1, c1;
    cin >> a1 >> b1 >> c1;
    BT3(a1, b1, c1);
    cout << '\n';


    // BT4:
    cout << "BT4" << '\n';
    double x4, y4;
    cout << "Nhập x: ";
    cin >> x4;
    cout << "Nhập y: ";
    cin >> y4;
    BT4(x4, y4);
    cout << '\n';


    // BT5:
    cout << "BT5" << '\n';
    double a5, b5;
    cin >> a5 >> b5;
    BT5(a5, b5);
    cout << '\n';


    // BT6:
    cout << "BT6" << '\n';
    double a6, b6, c6;
    cin >> a6 >> b6 >> c6;
    BT6(a6, b6, c6);
    cout << '\n';


    // BT7:
    cout << "BT7" << '\n';
    long long t7;
    cin >> t7;
    BT7(t7);
    cout << '\n';


    // BT8:
    cout << "BT8" << '\n';
    long long t8;
    cin >> t8;
    BT8(t8);
    cout << '\n';


    // BT9:
    cout << "BT9" << '\n';
    long long t9;
    cin >> t9;
    BT8(t9);
    cout << '\n';


    // BT10:
    cout << "BT10" << '\n';
    long long n10;
    cout << "Nhap so (0-20): ";
    cin >> n10;
    BT10(n10);
    cout << '\n';


    // BT11:
    cout << "BT11" << '\n';
    double a111, b111, c111;
    double a112, b112, c112;
    cout << "Nhap he so phuong trinh 1 (a1, b1, c1): ";
    cin >> a111 >> b111 >> c111;
    cout << "Nhap he so phuong trinh 2 (a2, b2, c2): ";
    cin >> a112 >> b112 >> c112;
    BT11(a111, b111, c111, a112, b112, c112);
    cout << '\n';


    // BT12:
    cout << "BT12" << '\n';
    long long m12, n12;
    cin >> m12 >> n12;
    BT12(n12, m12);
    cout << '\n';


    // BT13:
    cout << "BT13" << '\n';
    long long n13, m13, M13;
    cin >> n13 >> m13 >> M13;
    BT13(n13, m13, M13);
    cout << '\n';


    // BT14:
    cout << "BT14" << '\n';
    double a, b;
    int max_trial;
    string s, pin;
    cout << "PIN real: ";
    cin >> pin;
    cout << "Max_trial: ";
    cin >> max_trial;
    cout << "Nhap so tien: ";
    cin >> a;
    cout << "Nhap so tien muon rut: ";
    cin >> b;
    BT14(a, b, max_trial, s, pin);
    cout << '\n';

}