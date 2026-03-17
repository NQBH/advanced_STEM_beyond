#include <iostream>
#include <cmath>
using namespace std;

//BT1
void BT1(float r) {
    float C = r * 4;
    float S = r * r;
    cout << C << endl;
    cout << S << endl;
}

//BT2
void BT2(float a, float b) {
    float C = (a + b) * 2;
    float S = a * b;
    float H = sqrt(a * a + b * b);
    cout << C << endl;
    cout << S << endl;
    cout << H << endl;
}

//BT3
void BT3(float a, float b, float c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1 << endl;
    }
    if (a == b && a == c) {
        cout << "HLP" << endl;
        float Sxq = 4 * a * a;
        float Stp = 6 * a * a;
        float H = sqrt(3 * a * a);
        float V = a * a * a;
        cout << Sxq << endl;
        cout << Stp << endl;
        cout << H << endl;
        cout << V << endl;
    } else {
        cout << "HHCN" << endl;
        float Sxq = 2 * (a + b) * c;
        float Stp = Sxq + 2 * a * b;
        float H = sqrt(a * a + b * b + c * c);
        float V = a * b * c;
        cout << Sxq << endl;
        cout << Stp << endl;
        cout << H << endl;
        cout << V << endl;
    }
}

//BT4
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

//BT5
void BT5(double a, double b) {
    if (a == 0) {
        if (b == 0) {
            cout << "Vô số N" << endl;
        } else {
            cout << "Vô N" << endl;
        }
    } else {
        double x = -b / a;
        cout << x << endl;
    }
}

//BT6
void BT6(double a, double b, double c) {
    cout << "Phương trình: (" << a << ")x^2 + (" << b << ")x + (" << c << ") = 0" << endl;
    if (a == 0) {
        cout << "Đây là phương trình bậc nhất" << endl;
        if (b == 0) {
            if (c == 0) {
                cout << "Phương trình có vô số nghiệm" << endl;
            } else {
                cout << "Phương trình vô nghiệm" << endl;
            }
        } else {
            double x = -c / b;
            cout << "Nghiệm: x = " << x << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        cout << "Delta = b^2 - 4ac = " << delta << endl;
        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phương trình có 2 nghiệm phân biệt: " << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else if (delta == 0) {
            double x = -b  / (2 * a);
            cout << "Phương trình có nghiệm kép: " << endl;
            cout << "x1 = x2 = " << x << endl;
        } else {
            double thuc = -b / (2 * a);
            double ao = sqrt(-delta) / (2 * a);
            cout << "Phương trình có 2 nghiệm phức: " << endl;
            cout << "x1 = " << thuc << " + " << ao <<  "i" << endl;
            cout << "x2 = " << thuc << " - " << ao << "i" << endl;
        }
    }
}

//BT7
void BT7(double a, double b, double c, double n) {
    double max, min;
    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }
    if (a <= b && a <= c) {
        min = a;
    } else if (b <= a && b <= c) {
        min = b;
    } else {
        min = c;
    }
    cout << "Max of 3 numbers: " << max << endl;
    cout << "Min of 3 numbers: " << min << endl;

    if (n <= 0) {
        cout << "Error" << endl;
        return;
    }
    double maxN, minN;
    for (int i = 1; i <= n; ++i) {
        double x;
        cin >> x;
        if (i == 1) {
            maxN = x;
            minN = x;
        } else {
            if (x > maxN) {
                maxN = x;
            }
            if (x < minN) {
                minN = x;
            }
        }
    }
    cout << "Max of n numbers: " << maxN << endl;
    cout << "Min of n numbers: " << minN << endl;
}


//BT8
void BT8(int n) {
    int so_ko = 0;
    int so_am = 0;
    int so_duong = 0;
    for (int i = 1; i <= n; i++) {
        double so;
        cin >> so;
        if (so == 0) {
            so_ko++;
        } else if (so < 0) {
            so_am++;
        } else {
            so_duong++;
        }
    }
    cout << so_ko << endl;
    cout << so_am << endl;
    cout << so_duong << endl;
}

//BT9
void BT9(int n) {
    int so_chan = 0;
    int so_le = 0;
    for (int i = 1; i <= n; ++i) {
        int so;
        cin >> so;
        if (so % 2 == 0) {
            so_chan++;
        } else {
            so_le++;
        }
    }
    cout << so_chan << endl;
    cout << so_le << endl;
}

//BT10
#include <iostream>
#include <string>
using namespace std;
//Lệnh dựa theo Sách"Nhập môn lập trình" Trang 97
void BT10(int n) {
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

//BT11
void BT11(double a, double b, double c, double A, double B, double C) {
    double x, y;
    y = (c * B - b * C) / (a * B - b * A);
    x = (c - (b * y)) / a;
    if (a * B - A * b != 0) {
        cout << "He co 1 nghiem duy nhat:\n";
        cout << "x = " << y << ", y = " << x << endl;
    } else {
        if (c * B - C * b == 0 && a * C - A * c == 0) {
            cout << "He co vo so nghiem" << endl;
        } else {
            cout << "He vo nghiem" << endl;
        }
    }
}

//BT12
void BT12(long long n, long long m) {
    double T = 0;
    for (int i = 1; i <= n; ++i) {
        T += pow(i, m);
    }
    cout << T << endl;
}

//BT13
void BT13(long long n, long long m, double M) {
    double T = 0;
    long long i = 1;
    while (i <= n) {
        double u = pow(i, m);
        if (T + u <= M) {
            T = T + u;
            i++;
        } else {
            break;
        }
    }
    cout << T << endl;
}

//BT14
void BT14(long long A, long long a, int max_trial, string pin) {
    string pin_n = "";
    int len = pin.length();
    int i = len - 1;
    while (i >= 0) {
        pin_n = pin_n + pin[i];
        i--;
    }
    string input;
    int trial = 0;
    bool unlock = false;
    while (trial < max_trial) {
        cin >> input;
        if (input == pin_n) {
            cout << "Canh bao security! Khong duoc nhap PIN nua" << endl;
            return;
        }
        if (input == pin) {
            unlock = true;
            break;
        }
        trial++;
    }
    if (!unlock) {
        cout << "The da bi khoa do nhap sai qua nhieu" << endl;
        return;
    }
    if (a > A) {
        cout << "So tien rut lon hon so du kha dung. Ban bi ao tuong suc manh tai chinh a ???" << endl;

    } else {
        long long rut = A - a;
        cout << "Rut tien thanh cong!" << endl;
        cout << "So tien rut: " << a << " VND" << endl;
        cout << "So du con lai: " << rut << " VND" << endl;
        cout << "Cam on quy khach" << endl;
    }
}

int main() {
    cout << "BT1:" << endl;
    float r;
    cin >> r;
    BT1(r);

    cout << "BT2:" << endl;
    float a2, b2;
    cin >> a2 >> b2;
    BT2(a2, b2);

    cout << "BT3:" << endl;
    float a3, b3, c3;
    cin >> a3 >> b3 >> c3;
    BT3(a3, b3, c3);

    cout << "BT4:" << endl;
    double x, y;
    cin >> x;
    cin >> y;
    BT4(x, y);

    cout << "BT5:" << endl;
    double a5, b5;
    cin >> a5 >> b5;
    BT5(a5, b5);

    cout << "BT6:" << endl;
    double a6, b6, c6;
    cin >> a6;
    cin >> b6;
    cin >> c6;
    BT6(a6, b6, c6);

    cout << "BT7:" << endl;
    double a7, b7, c7;
    cin >> a7 >> b7 >> c7;
    double n7;
    cin >> n7;
    BT7(a7, b7, c7, n7);

    cout << "BT8:" << endl;
    int n8;
    cin >> n8;
    BT8(n8);

    cout << "BT9:" << endl;
    int n9;
    cin >> n9;
    BT9(n9);

    cout << "BT10:" << endl;
    int n10;
    cout << "Nhap so (0-20): ";
    cin >> n10;
    BT10(n10);

    cout << "BT11:" << endl;
    double a11, b11, c11, A11, B11, C11;
    cin >> a11 >> b11 >> c11 >> A11 >> B11 >> C11;
    BT11(a11, b11, c11, A11, B11, C11);

    cout << "BT12:" << endl;
    long long n12, m12;
    cin >> n12 >> m12;
    BT12(n12, m12);

    cout << "BT13:" << endl;
    long long n13, m13;
    double M;
    cin >> n13 >> m13 >> M;
    BT13(n13, m13, M);

    cout << "BT14:" << endl;
    long long A14, a14;
    int max_trial;
    string pin;
    cin >> A14 >> a14 >> max_trial >> pin;
    BT14(A14, a14, max_trial, pin);

    return 0;
}
